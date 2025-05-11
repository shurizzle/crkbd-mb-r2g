BOOTLOADER = custom

OPT_DEFS += -DBOOTLOADER_CATERINA
BOOTLOADER_TYPE = caterina

BOOTLOADER_SIZE = 4096

PROGRAM_CMD = $(call EXEC_DFU)

COMMAND_ENABLE   = no
CAPS_WORD_ENABLE = yes
MOUSEKEY_ENABLE  = no     # Mouse keys
VIA_ENABLE       = no     # Enable VIA
RGBLIGHT_ENABLE  = no     # Enable WS2812 RGB underlight.
OLED_ENABLE      = yes
OLED_DRIVER      = ssd1306
LTO_ENABLE       = yes
EXTRAFLAGS      += -flto
