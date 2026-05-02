# Windows Toolchain Installation  

## Install MSYS2 from [msys2.org](https://www.msys2.org) to the standard directory ``C:/msys64/``.  

## Launch the **MSYS2 UCRT64** terminal from the Windows Start Menu.  
![](https://www.msys2.org/docs/ucrt64.png)

## Execute to install gcc, gdb, ld, as, cmake, and ninja:
```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain

pacman -S mingw-w64-ucrt-x86_64-gdb

pacman -S mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja

# Calling pacman directly from PowerShell works too:
# C:/msys64/usr/bin/pacman.exe -S --noconfirm --needed base-devel mingw-w64-ucrt-x86_64-toolchain
# C:/msys64/usr/bin/pacman.exe -S --noconfirm mingw-w64-ucrt-x86_64-gdb
# C:/msys64/usr/bin/pacman.exe -S --noconfirm mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja
```

## Add MSYS2 to PATH

### Option 1: Temporary (Current Session Only)
Use this to quickly test the compiler in your active PowerShell window. This change will be lost when the terminal is closed.

```powershell
$env:Path += ";C:\msys64\ucrt64\bin"
gcc --version
```

### Option 2: Permanent (Current User)
Use this to write the path to the Windows Registry. The compiler will be available in all future terminal sessions. 
Note: You must restart your terminal after running this.

```powershell
$msysPath = "C:\msys64\ucrt64\bin" 
$userPath = [Environment]::GetEnvironmentVariable("Path", [EnvironmentVariableTarget]::User)
[Environment]::SetEnvironmentVariable("Path", "$userPath;$msysPath", [EnvironmentVariableTarget]::User)
```
