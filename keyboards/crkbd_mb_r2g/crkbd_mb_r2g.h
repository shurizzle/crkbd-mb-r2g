#include "quantum.h"
#include "quantum/split_common/transactions.h"
#include <LUFA/Drivers/USB/USB.h>

// clang-format off
#define LAYOUT_split_3x6_3( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { KC_NO, KC_NO, KC_NO, L30, L31, L32 }, \
    { R05, R04, R03, R02, R01, R00 }, \
    { R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20 }, \
    { KC_NO, KC_NO, KC_NO, R32, R31, R30 } \
  }

#define LAYOUT_split_3x5_3( \
  L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,           R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,           R20, R21, R22, R23, R24, \
                 L30, L31, L32, R30, R31, R32 \
  ) \
  { \
    { KC_NO, L00, L01, L02, L03, L04 }, \
    { KC_NO, L10, L11, L12, L13, L14 }, \
    { KC_NO, L20, L21, L22, L23, L24 }, \
    { KC_NO, KC_NO, KC_NO, L30, L31, L32 }, \
    { KC_NO, R04, R03, R02, R01, R00 }, \
    { KC_NO, R14, R13, R12, R11, R10 }, \
    { KC_NO, R24, R23, R22, R21, R20 }, \
    { KC_NO, KC_NO, KC_NO, R32, R31, R30 } \
  }


#define LAYOUT LAYOUT_split_3x6_3
