#!/bin/bash
sudo apt-get update
sudo apt-get install -y gcc-arm-none-eabi gdb-multiarch binutils-arm-none-eabi

wget https://github.com/renode/renode/releases/download/v1.16.1/renode_1.16.1_amd64.deb
sudo dpkg -i renode_1.16.1_amd64.deb
rm renode_1.16.1_amd64.deb

python3 -m pip install pyelftools