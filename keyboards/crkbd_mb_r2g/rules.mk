# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
AUDIO_ENABLE = no           # Audio output
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812

LTO_ENABLE = yes

OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306

RGBLIGHT_SUPPORTED = yes
RGB_MATRIX_SUPPORTED = yes

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes

NO_USB_STARTUP_CHECK = yes

SPLIT_KEYBOARD = yes

LAYOUTS = split_3x5_3 split_3x6_3
