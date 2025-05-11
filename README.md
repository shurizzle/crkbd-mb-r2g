# Corne MechBoards R2G

![crkbd](/.github/pictures/crkbd.jpg)

### Flash firmware

#### First time

- `git clone --recursive https://github.com/qmk/qmk_firmware`
- `ln -s ../../../../shurizzle qmk_firmware/keyboards/crkbd/keymaps/shurizzle`
- `cd qmk_firmware`
- Left half: `qmk flash -kb crkbd/r2g -km shurizzle -bl dfu-split-left`
- Right half: `qmk flash -kb crkbd/r2g -km shurizzle -bl dfu-split-right`

#### Following times

- `cd qmk_firmware`
- `git pull --recurse-submodules`
- Just in case: `make clean`
- On both halves: `qmk flash -kb crkbd/r2g -km shurizzle`
