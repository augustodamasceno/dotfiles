# FreeBSD Toolchain Installation  

```bash
sudo pkg update
sudo pkg install gcc gdb binutils cmake ninja
```

## To avoid silently defaulting to the system Clang  

```bash
cmake -S . -B build -G Ninja \
  -DCMAKE_C_COMPILER=/usr/local/bin/gcc13 \
  -DCMAKE_CXX_COMPILER=/usr/local/bin/g++13
```