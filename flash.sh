#!/bin/sh

set -eux

if test -d qmk_firmware; then
    cd qmk_firmware
    git pull --recurse-submodules
    make clean
else
    git clone --recursive https://github.com/qmk/qmk_firmware
    ln -s ../../../../shurizzle qmk_firmware/keyboards/crkbd/keymaps/shurizzle
    cd qmk_firmware
fi

qmk flash -kb crkbd/r2g -km shurizzle
qmk flash -kb crkbd/r2g -km shurizzle
