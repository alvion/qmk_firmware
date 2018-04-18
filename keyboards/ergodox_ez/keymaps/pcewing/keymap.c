#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _______ KC_TRNS
#define FN MO(_FN)
#define MEDIA MO(_MEDIA)
#define TODFT TO(_DEFAULT)
#define TORST TO(_RESET)
#define TODO KC_NO

enum layers {
  _DEFAULT,
  _FN,
  _MEDIA,
  _RESET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = KEYMAP(

    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MUTE,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_VOLU,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_VOLD,
    KC_LCTL, KC_LGUI, KC_LALT, KC_GRV,  FN,
                                                 KC_LEFT, KC_RGHT,
                                                                   KC_HOME,
                                                 KC_BSPC, KC_DELT, KC_END,

    TODO,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_LBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    FN,      MEDIA,    KC_RALT, KC_RGUI, KC_RCTL,
    KC_UP,   KC_DOWN,
    KC_PGUP,
    KC_PGDN, KC_ENT,  KC_SPC

),

[_FN] = KEYMAP(

    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______,
    KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_PAUS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_INS,  _______,
    _______, _______, _______, _______, _______,
                                        _______, _______,
                                                          _______,
                                        _______, _______, _______,

    _______, _______, _______, _______, _______, _______, TORST,
    _______, KC_PGUP, KC_HOME, KC_END,  _______, _______, _______,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, KC_PGDN, KC_LBRC, KC_RBRC, _______, _______, _______,
                      _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, TODO

),

[_MEDIA] = KEYMAP(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                             _______,
                                           _______, _______, _______,

       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),

[_RESET] = KEYMAP(
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,
                                                             KC_NO,
                                           KC_NO,   KC_NO,   KC_NO,

       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TODFT,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   RESET,   KC_NO
),

/*
 * Keymap Template
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |BrwserBack|
 *                                 `--------------------'       `------------------------'
[_LAYER_ID] = KEYMAP(
    // Left hand
    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,
    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,
    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,
    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,
    TODO,    TODO,    TODO,    TODO,    TODO,
                                                 TODO,    TODO,
                                                                  TODO,
                                                 TODO,    TODO,   TODO,

    // Right hand
    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,
    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,
             TODO,    TODO,    TODO,    TODO,    TODO,    TODO,
    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,    TODO,
                      TODO,    TODO,    TODO,    TODO,    TODO,
    TODO,    TODO,
                      TODO,
    TODO,    TODO,    TODO
),
*/
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_FN)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
