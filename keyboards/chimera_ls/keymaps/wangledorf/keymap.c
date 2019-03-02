#include QMK_KEYBOARD_H

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum chimera_lets_split_layers
{
	_QWERTY,
	_LOWER,
	_RAISE
};

enum custom_keycodes {
  KC_INCL = SAFE_RANGE,
  KC_PULL,
  KC_PUSH
};

#define LONGPRESS_DELAY 150

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, KC_LALT, LOWER,   RAISE,   KC_SPC,       KC_ENT,  RAISE,   LOWER,   KC_RALT, KC_RGUI, KC_RCTL
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  ),


  [_LOWER] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,      KC_GRV,  KC_LBRC, KC_RBRC, KC_BSLS, _______, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_PAUS,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_INS,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  ),


  [_RAISE] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     _______, KC_PUSH, KC_PULL, KC_INCL, _______, _______,      KC_MINS, KC_EQL,  _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    /* include some kind of library or header */
    case KC_INCL:
      if (record->event.pressed) {
        SEND_STRING("#include <>" SS_TAP(X_LEFT) );
        return false;
      }
      break;
    case KC_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull" SS_TAP(X_ENTER) );
        return false;
      }
      break;
    case KC_PUSH:
      if (record->event.pressed){
        SEND_STRING("git push" SS_TAP(X_ENTER) );
        return false;
      }
      break;
  }
  return true;
};


void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  switch (layer) {
    case _QWERTY:
      set_led_green;
      break;
    case _LOWER:
      set_led_white;
      break;
    case _RAISE:
      set_led_blue;
      break;
    default:
      set_led_green;
      break;
  }
};

