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

#include QMK_KEYBOARD_H

enum Layers { L_BASE, L_LOWER, L_RAISE, L_ADJUST, L_FS, L_MEDIA, L_LENGHT };

enum custom_keycodes {
  M_JIGL = QK_USER_0,
};

#define RSFT_EN RSFT_T(KC_ENT)
#define LCTL_TB CTL_T(KC_TAB)

#define LSPC0 LT(L_LOWER, KC_SPC)
#define RSPC0 LT(L_RAISE, KC_ENT)

#define LSPC1 LT(KC_NO, KC_SPC)
#define RSPC1 LT(L_ADJUST, KC_ENT)

#define LSPC2 LT(L_ADJUST, KC_SPC)
#define RSPC2 LT(KC_NO, KC_ENT)

#define LSPC3 LT(KC_NO, KC_SPC)
#define RSPC3 LT(KC_NO, KC_ENT)

#define TB_NEXT C(KC_TAB)
#define TB_PREV S(C(KC_TAB))

#define T_MEDIA TG(L_MEDIA)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_TB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LGUI,   LSPC0,      RSPC0, KC_RALT, MO(L_FS)
                                      //`--------------------------'  `--------------------------'

  ),

  [L_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_TB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_DOT, XXXXXXX, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LGUI,   LSPC1,      RSPC1, KC_RALT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_TB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LGUI,   LSPC2,      RSPC2, KC_RALT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_ADJUST] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_MNXT,                      KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, KC_MUTE, KC_MPLY,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      UG_NEXT, UG_HUED, UG_SATD, UG_VALD, KC_VOLD, KC_MPRV,                       M_JIGL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LGUI,   LSPC3,      RSPC3, KC_RALT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_FS] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,                      T_MEDIA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8,                      XXXXXXX, TB_PREV, TB_NEXT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [L_MEDIA] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      T_MEDIA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_MNXT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_MUTE, KC_MPLY,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MPRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, XXXXXXX, XXXXXXX,     KC_SPC,    KC_K,    KC_F
                                      //`--------------------------'  `--------------------------'
  ),
#if 0
  [L_LENGHT] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
#endif
};
// clang-format on

#define MOUSE_JIGGLE_INTERVAL_MS 15000 // how often to move the mouse

static bool is_mouse_jiggle_active = false;
static bool mouse_jiggle_direction = false; // used to alternate direction
static uint16_t mouse_jiggle_timer = 0;

#ifdef OLED_ENABLE
static char *const LAYER_NAMES[] = {"DEF", "LOW", "RAI", "ADJ", "Fs", "MED"};

// 8x8 bell icon rotated 90deg CW, column-major for SSD1306 GDDRAM
static const char bell_icon[] PROGMEM = {0x00, 0x3C, 0xFF, 0xFF,
                                         0x7E, 0x3C, 0x3C, 0x18};
static const char bell_blank[sizeof(bell_icon)] PROGMEM = {0};

static inline void oled_render_layer_state(void) {
  static size_t len = sizeof(LAYER_NAMES) / sizeof(LAYER_NAMES[0]);
  static char buf[3] = {0};

  size_t i = get_highest_layer(layer_state);
  oled_set_cursor(0, 0);
  if (i < len) {
    oled_write_ln(LAYER_NAMES[i], false);
  } else {
    // hand-rolled hex: snprintf would pull in ~1.3 KB of printf
    static const char hex[] = "0123456789abcdef";
    buf[0] = hex[(i >> 4) & 0xF];
    buf[1] = hex[i & 0xF];
    oled_write_ln(buf, false);
  }

  // col is in characters (6 px), so col 20 = pixel 120; line 3 = rows 24..31.
  // oled_write_raw_P skips unchanged bytes, so writing every frame is cheap.
  oled_set_cursor(20, 3);
  oled_write_raw_P(is_mouse_jiggle_active ? bell_icon : bell_blank,
                   sizeof(bell_icon));
}

void oled_render_keylog_r2g(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_layer_state();
    // oled_render_keylog_r2g();
    return false;
  } else {
    return true;
  }
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case M_JIGL:
    if (record->event.pressed) {
      is_mouse_jiggle_active = !is_mouse_jiggle_active;
      if (is_mouse_jiggle_active)
        mouse_jiggle_timer = timer_read();
    }
    return false;
  }

  return true;
}

void matrix_scan_user(void) {
  if (is_mouse_jiggle_active) {
    if (timer_elapsed(mouse_jiggle_timer) > MOUSE_JIGGLE_INTERVAL_MS) {
      mouse_jiggle_timer = timer_read();
      // raw mouse report: same 8 px step as mousekey, without its code
      report_mouse_t report = {.x = mouse_jiggle_direction ? -8 : 8};
      host_mouse_send(&report);
      mouse_jiggle_direction = !mouse_jiggle_direction;
    }
  }
}
