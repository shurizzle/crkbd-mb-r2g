# Corne MechBoards R2G

### Peculiarities

- Uses caterina bootloader but needs dfu flasher.
- EE_HANDS handness (dfu-split-{left,right}).
- Only works on USB on left half.

### Flash firmware

#### First time

- Left half: `qmk flash -kb crkbd_mb_r2g -km via -bl dfu-split-left`
- Right half: `qmk flash -kb crkbd_mb_r2g -km via -bl dfu-split-right`

#### Following times

On both halves: `qmk flash -kb crkbd_mb_r2g -km via -bl dfu`
