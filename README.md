# Corne MechBoards R2G

![crkbd](/.github/pictures/crkbd.jpg)

### Flash firmware

#### First time

- Left half: `qmk flash -kb crkbd/r2g -km shurizzle -bl dfu-split-left`
- Right half: `qmk flash -kb crkbd/r2g -km shurizzle -bl dfu-split-right`

#### Following times

On both halves: `qmk flash -kb crkbd/r2g -km shurizzle`
