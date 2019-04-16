#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _ALT 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

// Tap Dance Declarations
enum {
  TD_WIN = 0,
  TD_ALTF4
};

#define SPACEFN         LT(_FN1, KC_SPC)

uint32_t user_default = 20;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _BL: (Base Layer) Default Layer
 * +---------------------------------------------------------------------------------+
 * | ESC | 1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP |  HOME |
 * +---------------------------------------------------------------------------------+
 * | TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  |  END  |
 * +---------------------------------------------------------------------------------+
 * | CAPS   |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |  RETURN |  PGUP |
 * +---------------------------------------------------------------------------------+
 * | LSHIFT   |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / | SHIFT | UP |  PGDN |
 * +---------------------------------------------------------------------------------+
 * |LCTRL|TD_WIN|RCTRL|SPACEFN |TD_CTRLFN| SPACE  |OSL(FN1)|WIN |RCTRL|LEFT|DWN| RGHT|
 * +----------------------------------------------~----------------------------------+
 */
  [_BASE] = LAYOUT_65(
    KC_GESC, KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX,  KC_BSPC, KC_HOME, \
    KC_TAB,  KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, \
    KC_CAPS, KC_A,      KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, TD(TD_WIN),KC_LALT, SPACEFN, KC_RCTL,                   KC_SPC,  XXXXXXX, OSL(_FN1), KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

/* Keymap _FN1: (Function Layer)
 * +---------------------------------------------------------------------------------+
 * | ~  |  F1 |  F2 | F3 |  F4 | F5 |  F6 | F7 | F8 | F9 |  F10 | F11 | F12 |  | INS |
 * +---------------------------------------------------------------------------------+
 * | RGB_TOG | RGB_MOD |   |    |    |KP_7 |KP_8 |KP_ 9|   |   |   |   |   |   | DEL |
 * +---------------------------------------------------------------------------------+
 * |       |    |    |    |    |    |    |KP_4 |KP_5 |KP_6 |KP_+|KP_*|         |     |
 * +--------------------------------------------------------------------------------+
 * |         |    |    |    |     |     |     |KP_1 |KP_2 |KP_3 |KP_-|KP_/|    |     |
 * +---------------------------------------------------------------------------------+
 * |     |     |     |          |     |      | KP_0 |     | KP_DOT |     |    | PSCR |        
 * +----------------------------------------------~----------------------------------+
 */
  [_FN1] = LAYOUT_65(
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,  _______, KC_INS, \
    RGB_TOG, RGB_MOD, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, KC_DEL, \
    _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PSLS, KC_PENT, _______, _______, \
    _______, _______, _______, _______, _______,                   KC_P0,   _______, _______, KC_PDOT, _______, _______, _______, KC_PSCR
  )

/*  [_ALT] = LAYOUT_65(
    _______, _______, _______, _______, A(KC_F4), _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, \
    A(KC_TAB), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    TO(_BASE), _______, KC_LALT, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______
  )*/
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_WIN]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E))   // Tap once for Windows key, twice for Windows Explorer
// Other declarations would go here, separated by commas, if you have them
}; 

uint32_t rgbMode;

void matrix_init_user(void) {
  rgbMode = RGBLIGHT_MODE_KNIGHT + 1;

  rgblight_enable();
  rgblight_sethsv(0, 0, 100);
  rgblight_mode(rgbMode);
}

uint32_t layer_state_set_user(uint32_t state) {
  switch(biton32(state)) {
    case _FN1:
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_setrgb(0x00, 0xFF, 0xFF);
      break;
    default:
      rgblight_mode(rgbMode);
      rgblight_setrgb(0xFF, 0xFF, 0xFF);
      break;
  }

  return state;
}

// Runs constantly in the background, in a loop.
// void matrix_scan_user(void) {
//   uint8_t layer = biton32(layer_state);

  
// }