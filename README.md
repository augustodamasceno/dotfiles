# dotfiles  
Dot Files  

# 1. Samples

The `samples/` folder contains minimal projects used to validate IDE configuration for compile, run, debug, and testing workflows. Each sample is self-contained and intended to verify that toolchain and editor settings are working correctly.

# 2. Visual Studio Code  
> Place the `.vscode` directory at the root of the project.

# 3. [i3](i3/README.md)  
Configuration for the [i3 window manager](https://i3wm.org/), including i3status. See [i3/README.md](i3/README.md) for install and update instructions.  

# 4. [My Vim and Neovim Setups](https://github.com/augustodamasceno/vimlink)  

# 5. [Gin Shell (GSH) - A collection of bash scripts](https://github.com/augustodamasceno/gsh)  

# 6. Toolchain Installations for Unix-like and Windows:  

* ## 6.1 [C++](docs/cpp.md)

# 7. [Databases Playground](databases/README.md)
Pre-configured Docker Compose environments for quick database setup during development and testing. Includes:

- **PostgreSQL** (Port 65001) - Relational database for structured data
- **MongoDB** (Port 65002) - NoSQL document database for flexible schemas
- **Redis** (Port 65003) - In-memory cache and data store for high-speed operations

All databases use the same credentials (`playground`/`playground`) for easy access. See [databases/README.md](databases/README.md) for detailed setup, connection instructions, and usage examples for terminal, DBeaver, and application code.
