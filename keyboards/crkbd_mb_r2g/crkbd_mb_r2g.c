/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "crkbd_mb_r2g.h"

bool matrix_scan_task(void);
bool quantum_task(void);
extern void protocol_post_task(void);
extern void protocol_pre_init(void);
extern void protocol_post_init(void);

#ifdef RGB_MATRIX_ENABLE

// Logical Layout
// Columns
// Left
// 0  1  2  3  4  5
//                   ROWS
// 25 24 19 18 11 10   0
//    03    02    01
// 26 23 20 17 12 09   1
//    04    05    06
// 27 22 21 16 13 08   2
//
//          15 14 07   3
//
// Right
// 0  1  2  3  4  5
//                    ROWS
// 25 24 19 18 11 10   4
//    03    02    01
// 26 23 20 17 12 09   5
//    04    05    06
// 27 22 21 16 13 08   6
//
//          15 14 07   7
//
// Physical Layout
// Columns
// 0  1  2  3  4  5  6  7  8  9  10 11 12 13
//                                           ROWS
// 25 24 19 18 11 10       10 11 18 19 24 25  0
//    03    02    01       01    02    03
// 26 23 20 17 12 09       09 12 17 20 23 26  1
//    04                               04
// 27 22 21 16 13 08       08 13 16 21 22 27  2
//          05    06       06    05
//           15 14 07     07 14 15              3

// clang-format off
led_config_t g_led_config = { {
    {  24,  23,  18,  17,  10,   9 },
    {  25,  22,  19,  16,  11,   8 },
    {  26,  21,  20,  15,  12,   7 },
    { NO_LED, NO_LED, NO_LED,  14,  13,   6 },
    {  51,  50,  45,  44,  37,  36 },
    {  52,  49,  46,  43,  38,  35 },
    {  53,  48,  47,  42,  39,  34 },
    { NO_LED, NO_LED, NO_LED,  41,  40,  33 }
}, {
    {  85,  16 }, {  50,  13 }, {  16,  20 }, {  16,  38 }, {  50,  48 }, {  85,  52 }, {  95,  63 },
    {  85,  39 }, {  85,  21 }, {  85,   4 }, {  68,   2 }, {  68,  19 }, {  68,  37 }, {  80,  58 },
    {  60,  55 }, {  50,  35 }, {  50,  13 }, {  50,   0 }, {  33,   3 }, {  33,  20 }, {  33,  37 },
    {  16,  42 }, {  16,  24 }, {  16,   7 }, {   0,   7 }, {   0,  24 }, {   0,  41 }, { 139,  16 },
    { 174,  13 }, { 208,  20 }, { 208,  38 }, { 174,  48 }, { 139,  52 }, { 129,  63 }, { 139,  39 },
    { 139,  21 }, { 139,   4 }, { 156,   2 }, { 156,  19 }, { 156,  37 }, { 144,  58 }, { 164,  55 },
    { 174,  35 }, { 174,  13 }, { 174,   0 }, { 191,   3 }, { 191,  20 }, { 191,  37 }, { 208,  42 },
    { 208,  24 }, { 208,   7 }, { 224,   7 }, { 224,  24 }, { 224,  41 }
}, {
    2, 2, 2, 2, 2, 2, 1,
    4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 1, 1, 1, 2,
    2, 2, 2, 2, 2, 1, 4,
    4, 4, 4, 4, 4, 1, 1,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 1, 1, 1
} };
// clang-format on
#endif

bool is_keyboard_master(void) { return is_keyboard_left(); }

static bool _suspend_wakeup_condition(void) {
  for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
    if (matrix_get_row(r))
      return true;
  }
  return false;
}

static void _keyboard_task(void) {
  bool is_suspended =
      is_keyboard_master() && USB_DeviceState != DEVICE_STATE_Configured;

  if (is_suspended) {
    matrix_power_up();
  }
  bool matrix_changed = matrix_scan_task();
  (void)matrix_changed;
  if (is_suspended) {
    matrix_power_down();
  }

  quantum_task();

#if defined(RGBLIGHT_ENABLE)
  rgblight_task();
#endif

#ifdef LED_MATRIX_ENABLE
  led_matrix_task();
#endif
#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_task();
#endif

#if defined(BACKLIGHT_ENABLE)
#if defined(BACKLIGHT_PIN) || defined(BACKLIGHT_PINS)
  backlight_task();
#endif
#endif

#ifdef ENCODER_ENABLE
  bool encoders_changed = encoder_read();
  if (encoders_changed)
    last_encoder_activity_trigger();
#endif

  if (is_suspended) {
    if ((matrix_changed
#ifdef ENCODER_ENABLE
         || encoders_changed
#endif
         ) &&
        USB_Device_RemoteWakeupEnabled && _suspend_wakeup_condition()) {
      USB_Device_SendRemoteWakeup();
    }
  } else {
#ifdef OLED_ENABLE
    oled_task();
#if OLED_TIMEOUT > 0
    // Wake up oled if user is using those fabulous keys or spinning those
    // encoders!
    if (matrix_changed
#ifdef ENCODER_ENABLE
        || encoders_changed
#endif
    )
      oled_on();
#endif
#endif

#ifdef ST7565_ENABLE
    st7565_task();
#if ST7565_TIMEOUT > 0
    // Wake up display if user is using those fabulous keys or spinning those
    // encoders!
    if (matrix_changed
#ifdef ENCODER_ENABLE
        || encoders_changed
#endif
    )
      st7565_on();
#endif
#endif

#ifdef MOUSEKEY_ENABLE
    // mousekey repeat & acceleration
    mousekey_task();
#endif

#ifdef PS2_MOUSE_ENABLE
    ps2_mouse_task();
#endif

#ifdef POINTING_DEVICE_ENABLE
    pointing_device_task();
#endif

#ifdef MIDI_ENABLE
    midi_task();
#endif

#ifdef VELOCIKEY_ENABLE
    if (velocikey_enabled()) {
      velocikey_decelerate();
    }
#endif

#ifdef JOYSTICK_ENABLE
    joystick_task();
#endif

#ifdef DIGITIZER_ENABLE
    digitizer_task();
#endif

#ifdef PROGRAMMABLE_BUTTON_ENABLE
    programmable_button_send();
#endif
  }

  led_task();
}

static int prev_USB_DeviceState = DEVICE_STATE_Unattached;

static void _protocol_pre_task(void) {
  if (is_keyboard_master()) {
    if (USB_DeviceState != DEVICE_STATE_Configured &&
        prev_USB_DeviceState == DEVICE_STATE_Configured) {
      suspend_power_down();
      clear_keyboard();
    } else if (USB_DeviceState == DEVICE_STATE_Configured &&
               prev_USB_DeviceState != DEVICE_STATE_Configured) {
      suspend_wakeup_init();
    }
    prev_USB_DeviceState = USB_DeviceState;
  }
}

void protocol_task(void) {
  _protocol_pre_task();

  _keyboard_task();

  protocol_post_task();
}

void keyboard_post_init_kb(void) {
  if (is_keyboard_master()) {
    prev_USB_DeviceState = USB_DeviceState;

    if (USB_DeviceState != DEVICE_STATE_Configured) {
      suspend_power_down();
    }
  }

  keyboard_post_init_user();
}

void protocol_init(void) {
  protocol_pre_init();

  keyboard_init();

  protocol_post_init();
}
