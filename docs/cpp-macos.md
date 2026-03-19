# macOS Toolchain Installation  

## Clang

```bash
xcode-select --install
```

## GCC
```bash
# Install Homebrew
/bin/bash -c "$(curl -fsSL [https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh](https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh))"

brew install cmake ninja gcc gdb
```

### Codesigning GDB on macOS

The macOS enforces strict binary signing for any process attempting to attach a debugger. To use GDB natively, you must generate a self-signed certificate, establish system trust, and apply it to the `gdb` binary alongside specific debugging entitlements.

#### 1. Create a Code Signing Certificate
1. Open the **Keychain Access** application (`Cmd + Space`, type "Keychain").
2. In the top menu bar, navigate to **Keychain Access > Certificate Assistant > Create a Certificate**.
3. Configure the certificate with the following exact parameters:
   * **Name:** `gdb-cert`
   * **Identity Type:** `Self Signed Root`
   * **Certificate Type:** `Code Signing`
   * Check **Let me override defaults**.
4. Click **Continue** through the prompts until you reach the **Specify a Location For The Certificate** screen.
5. Change the **Keychain** dropdown to **System**, then click **Create**.
   *(Note: You will be prompted for your macOS administrator password).*

#### 2. Establish System Trust
1. Locate your newly created `gdb-cert` within the **System** keychain.
2. Double-click the certificate to open its properties.
3. Expand the **Trust** section.
4. Change the **Code Signing** dropdown to **Always Trust**.
5. Close the window and authenticate again to save the trust settings.
6. Quit Keychain Access.

#### 3. Create the Entitlements File
macOS requires explicit XML entitlements for the debugger. Create a file named `gdb-entitlements.xml` in your current terminal directory with the following content:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "[http://www.apple.com/DTDs/PropertyList-1.0.dtd](http://www.apple.com/DTDs/PropertyList-1.0.dtd)">
<plist version="1.0">
<dict>
    <key>com.apple.security.cs.debugger</key>
    <true/>
</dict>
</plist>
```

#### 4. Apply the Signature  
```bash
# Refresh the keychain state
sudo killall taskgated

# Apply the codesign with the XML entitlements
codesign --entitlements gdb-entitlements.xml -fs gdb-cert $(which gdb)
```

#### 5. Verification
```bash
codesign -vv $(which gdb)
codesign -d --entitlements :- $(which gdb)
```

> Note: You may need to fully reboot your Mac for the kernel to recognize the new taskgated trust policies before GDB can successfully attach to a process.