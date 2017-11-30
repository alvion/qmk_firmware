#include "atreus62.h"

#define _______ KC_TRNS
#define FN MO(_FN)
#define TODO KC_NO

enum atreus62_layers {
  _DEFAULT,
  _FN,
  _RESET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default layer
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |  =   |   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |,------.,------.|   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  ||Delete||Enter ||   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  |  `   |  Fn  | Bksp |`------'`------'|Space |  Fn  |      | Alt  | Win  | Ctrl |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_DEFAULT] = { /* qwerty */
    { KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS },
    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS },
    { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
    { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
    { KC_LCTL, KC_LGUI, KC_LALT, KC_GRV,  FN,      KC_BSPC, KC_ENT,   KC_SPC,  FN,      TODO,    KC_RALT, KC_RGUI, KC_RCTL }
},

/* Function layer
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  F9  | F10  | F11  | F12  | PrSc |                | PgUp | Home | End  |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Caps |  F5  |  F6  |  F7  |  F8  |Pause |,------.,------.| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F2  |  F2  |Insert||      ||      || PgDn |  [   |  ]   |  {   |  }   |      |
 * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
 * |      |      |      |      |      |      |`------'`------'|      |      |      |      |      |      |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_FN] = {
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_RESET) },
    { _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______, KC_PGUP, KC_HOME, KC_END,  _______, _______, _______ },
    { KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_PAUS, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______ },
    { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_INS,  _______, KC_PGDN, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},

/*
 * This layer makes it possible to reset the firmware; don't get rid of it and make sure there is a way to activate it.
 */
[_RESET] = {
    { TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
    { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
    { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
    { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
    { KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET }
}

/*
[_TRNS] = {
    { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};
