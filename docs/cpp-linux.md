# Linux Toolchain Installation  

## Debian & Ubuntu

```bash
sudo apt update
sudo apt install build-essential gdb cmake ninja-build
```

## Arch Linux

```bash
sudo pacman -S --needed base-devel gdb cmake ninja
```

## Fedora & Red Hat Enterprise Linux (RHEL)

```bash
sudo dnf check-update
sudo dnf install gcc gcc-c++ gdb binutils cmake ninja-build
```