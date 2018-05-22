#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_____ KC_TRNS
#define KC_ENTS MT(MOD_RSFT, KC_ENT)
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG // RGB Toggle
#define KC_RMOD RGB_MOD // RGB Mode
#define KC_RHUI RGB_HUI // RGB Hue Increase
#define KC_RHUD RGB_HUD // RGB Hue Decrease
#define KC_RSAI RGB_SAI // RGB Saturation Increase
#define KC_RSAD RGB_SAD // RGB Saturation Decrease
#define KC_RVAI RGB_VAI // RGB Value Increase
#define KC_RVAD RGB_VAD // RGB Value Decrease

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default layer
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |  =   |   1  |   2  |   3  |   4  |   5  |                   |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                   |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |                   |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|  .-----. .-----.  |------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  | /Delete/ \Raise \ |   N  |   M  |   ,  |   .  |   /  |Enter |
   * `------+------+------+------+------+------'/------/   \------\'------+------+------+------+------+------'
   *                           | Ctrl |Lower | / Bksp /     \Space \ | Win  | Alt  |
   *                           `------+------' `-----'       `-----' `------+------'
   */
  [_QWERTY] = LAYOUT_kc(
     EQL,    1,    2,    3,    4,    5,                6,    7,    8,    9,    0, MINS,
     TAB,    Q,    W,    E,    R,    T,                Y,    U,    I,    O,    P, BSLS,
     ESC,    A,    S,    D,    F,    G,                H,    J,    K,    L, SCLN, QUOT,
    LSFT,    Z,    X,    C,    V,    B,  DEL, RASE,    N,    M, COMM,  DOT, SLSH, ENTS,
                            LCTL, LOWR, BSPC,  SPC, LGUI, LALT
  ),

  /* Lower layer
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * | Win  |  F9  | F10  | F11  | F12  |PrtScr|                   |PageUp| Home | End  |   =  |   -  |      |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * | Ctrl |  F5  |  F6  |  F7  |  F8  |Pause |                   | Left | Down |  Up  |Right |      |
   * |------+------+------+------+------+------|  .-----. .-----.  |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |Insert| /      / \      \ |PageDn|   [  |   ]  |   `  |      |      |
   * `------+------+------+------+------+------'/------/   \------\'------+------+------+------+------+------'
   *                           |      |      | /      /     \      \ |      |      |
   *                           `------+------' `-----'       `-----' `------+------'
   */
  [_LOWER] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____,             ____, ____, ____, ____, ____, ____,
    LGUI,   F9,  F10,  F11,  F12, PSCR,             PGUP, HOME,  END,  EQL, MINS, ____,
    LCTL,   F5,   F6,   F7,   F8, PAUS,             LEFT, DOWN,   UP, RGHT, ____, ____,
    ____,   F1,   F2,   F3,   F4,  INS, ____, ____, PGDN, LBRC, RBRC,  GRV, ____, ____,
                            ____, ____, BL_S, ____, ____, ____
  ),

  /* Raise layer
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|  .-----. .-----.  |------+------+------+------+------+------|
   * |      |      |      |      |      |      | /      / \      \ |      |      |      |      |      |      |
   * `------+------+------+------+------+------'/------/   \------\'------+------+------+------+------+------'
   *                           |      |      | /      /     \      \ |      |      |
   *                           `------+------' `-----'       `-----' `------+------'
   */
  [_RAISE] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____,             ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____,             ____, ____, ____, ____, ____, ____,
    ____, MPRV, MNXT, ____, ____, ____,             ____, ____, ____, ____, ____, ____,
    MUTE, MSTP, MPLY, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
                            ____, ____, ____, ____, ____, ____
  ),

  /* Adjust layer
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|  .-----. .-----.  |------+------+------+------+------+------|
   * |      |      |      |      |      |      | /      / \      \ |      |      |      |      |      |      |
   * `------+------+------+------+------+------'/------/   \------\'------+------+------+------+------+------'
   *                           |      |      | /      /     \      \ |      |      |
   *                           `------+------' `-----'       `-----' `------+------'
   */
  [_ADJUST] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____,             ____, ____, ____, ____, ____, ____,
    RTOG, RMOD, RHUI, RSAI, RVAI, ____,             ____, ____, ____, ____, ____, ____,
    ____, DBUG, RHUD, RSAD, RVAD, ____,             ____, ____, ____, ____, ____, ____,
    BL_S,  RST, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
                            ____, ____, ____, ____, ____, ____
  )

  /* Layer Template
   * ,-----------------------------------------.                   ,-----------------------------------------.
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
   * |------+------+------+------+------+------|  .-----. .-----.  |------+------+------+------+------+------|
   * |      |      |      |      |      |      | /      / \      \ |      |      |      |      |      |      |
   * `------+------+------+------+------+------'/------/   \------\'------+------+------+------+------+------'
   *                           |      |      | /      /     \      \ |      |      |
   *                           `------+------' `-----'       `-----' `------+------'
   */
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
