#!/bin/bash

set -e

sudo apt-get update

# Toolchain
sudo apt-get install -y \
    gcc-arm-none-eabi \
    gdb-multiarch \
    binutils-arm-none-eabi

# Ruby (required by Ceedling/CMock)
sudo apt-get install -y \
    ruby \
    ruby-dev \
    build-essential

# Python tools
sudo apt-get install -y \
    python3-pip

# Coverage tool
python3 -m pip install --upgrade pip
python3 -m pip install \
    pyelftools \
    gcovr

# Ceedling (includes Unity + CMock support)
# Install Ceedling only if not already installed
if ! command -v ceedling >/dev/null 2>&1; then
    sudo gem install ceedling
fi

# Renode
# Install Renode only if not already installed
if ! command -v renode >/dev/null 2>&1; then
    wget -q https://github.com/renode/renode/releases/download/v1.16.1/renode_1.16.1_amd64.deb
    sudo dpkg -i renode_1.16.1_amd64.deb
    rm renode_1.16.1_amd64.deb
fi

# Verify installation
echo "===== Installed Versions ====="
gcc --version | head -n1 || true
ruby --version || true
ceedling version || true
gcovr --version || true
renode --version || true