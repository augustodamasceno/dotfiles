#!/usr/bin/env bash
#
# i3 dotfiles installer
#
# Copyright (c) 2026, Augusto Damasceno.
# All rights reserved.
# SPDX-License-Identifier: BSD-2-Clause
#
# See https://github.com/augustodamasceno/dotfiles
#
# Usage:  ./install.sh [--deps]

set -euo pipefail

REPO_DIR="$(cd "$(type -p -- "${BASH_SOURCE[0]}" > /dev/null; echo "${BASH_SOURCE[0]}")" 2>/dev/null || realpath "${BASH_SOURCE[0]}")"
REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

I3_SRC="$REPO_DIR/config"
I3STATUS_SRC="$REPO_DIR/i3status.conf"

I3_DEST="$HOME/.config/i3/config"
I3STATUS_DEST="$HOME/.config/i3status/config"

info()    { printf '\033[1;36m[INFO]\033[0m  %s\n' "$*"; }
ok()      { printf '\033[1;32m[ OK ]\033[0m  %s\n' "$*"; }
warn()    { printf '\033[1;33m[WARN]\033[0m  %s\n' "$*"; }
die()     { printf '\033[1;31m[ERR ]\033[0m  %s\n' "$*" >&2; exit 1; }

install_file() {
    local src="$1"
    local dest="$2"
    local label="$3"

    [[ -f "$src" ]] || die "Source not found: $src"
    mkdir -p "$(dirname "$dest")"

    if [[ -e "$dest" ]]; then
        local bak="${dest}.bak.$(date +%Y%m%d%H%M%S)"
        warn "$label: existing file backed up to $bak"
        mv "$dest" "$bak"
    fi

    cp "$src" "$dest"
    ok "$label copied to: $dest"
}

detect_os() {
    if [[ -f /etc/os-release ]]; then
        # shellcheck source=/dev/null
        . /etc/os-release
        echo "${ID:-linux}"
    elif command -v uname &>/dev/null && [[ "$(uname)" == "FreeBSD" ]]; then
        echo "freebsd"
    else
        echo "unknown"
    fi
}

install_deps() {
    local os
    os="$(detect_os)"

    local pkgs_debian="i3 i3status rofi alacritty picom dunst feh playerctl brightnessctl scrot numlockx pulseaudio-utils pavucontrol dex xss-lock"
    local pkgs_arch="i3-wm i3status rofi alacritty picom dunst feh playerctl brightnessctl scrot numlockx pavucontrol dex xss-lock"
    local pkgs_fedora="i3 i3status rofi alacritty picom dunst feh playerctl brightnessctl scrot numlockx pavucontrol dex xss-lock"
    local pkgs_freebsd="i3 i3status rofi alacritty picom dunst feh playerctl brightnessctl scrot numlockx pavucontrol dex xss-lock"

    info "Detected OS: $os"

    case "$os" in
        ubuntu|debian|linuxmint|pop)
            info "Installing packages via apt..."
            sudo apt-get update -qq
            # shellcheck disable=SC2086
            sudo apt-get install -y $pkgs_debian
            ;;
        arch|manjaro|endeavouros|garuda)
            info "Installing packages via pacman..."
            # shellcheck disable=SC2086
            sudo pacman -S --needed --noconfirm $pkgs_arch
            ;;
        fedora)
            info "Installing packages via dnf..."
            # shellcheck disable=SC2086
            sudo dnf install -y $pkgs_fedora
            ;;
        freebsd)
            info "Installing packages via pkg..."
            # shellcheck disable=SC2086
            sudo pkg install -y $pkgs_freebsd
            ;;
        *)
            warn "Unknown distro '$os' — skipping automatic dependency install."
            warn "Install manually: $pkgs_debian"
            ;;
    esac
}

create_screenshots_dir() {
    local dir="$HOME/Pictures/screenshots"
    if [[ ! -d "$dir" ]]; then
        mkdir -p "$dir"
        ok "Created screenshots directory: $dir"
    fi
}

reload_i3() {
    if command -v i3-msg &>/dev/null && i3-msg -t get_version &>/dev/null 2>&1; then
        info "Reloading i3 configuration..."
        i3-msg reload
        ok "i3 reloaded"
    else
        info "i3 is not running — skipping reload (start i3 to apply config)"
    fi
}

printf '\n\033[1;35m  i3 dotfiles installer\033[0m\n\n'

# Optional: pass --deps flag to install system packages
if [[ "${1:-}" == "--deps" ]]; then
    install_deps
fi

# Install config files
install_file "$I3_SRC"       "$I3_DEST"       "i3 config"
install_file "$I3STATUS_SRC" "$I3STATUS_DEST"  "i3status config"

# Ensure screenshots directory exists
create_screenshots_dir

# Reload if i3 is running
reload_i3

printf '\n\033[1;32mDone.\033[0m\n\n'
printf '  To reload i3 manually:  i3-msg reload\n'
printf '  To reload i3status:      killall -SIGUSR1 i3status\n'
printf '  To restart i3 fully:     i3-msg restart\n\n'
