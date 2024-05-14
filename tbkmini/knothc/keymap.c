/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include "caps_word.h"

// Layer definitions
enum layers {
    _QWERTY = 0,
    _LOWER,
    _NAV,
    _RAISE,
    _ADJUST
};

// Left-hand home row mods
#define HRM_A  LSFT_T(KC_A)
#define HRM_S  CTL_T(KC_S)
#define HRM_D  ALT_T(KC_D)
#define HRM_F  CMD_T(KC_F)

// one-shot-key definitions
#define OSK_JUMP OSM(MOD_LCTL|MOD_LALT)

// Right-hand home row mods
#define HRM_J    RCMD_T(KC_J)
#define HRM_K    ALT_T(KC_K)
#define HRM_L    CTL_T(KC_L)
#define HRM_SCLN LSFT_T(KC_SCLN)

// Layer Tap definitons
#define ENT_HIG  LT(_RAISE, KC_ENT)
#define SPC_HIG  LT(_RAISE, KC_SPC)
#define TAB_NAV  LT(_NAV, KC_TAB)
#define ENT_NAV  LT(_NAV, KC_ENT)
#define ML_LO    LT(_LOWER, KC_TAB)
#define BSPC_LOW LT(_LOWER, KC_BSPC)
#define CTRL_HIG LM(_RAISE, MOD_LCTL)

// Other - Convenience Shortcuts
#define GO_BACK G(C(KC_LEFT))
#define GO_FRWD G(C(KC_RIGHT))
#define QTERM   C(KC_BSPC)    // Toggle iTerm2


// Macro Declarations
enum custom_keycodes {
  FWD_DEL_WORD = SAFE_RANGE,
  BCK_DEL_WORD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Base Layer: QWERTY
     *
     * ,-------------------------------------------.                              ,--------------------------------------------.
     * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  BSPC   |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+---------|
     * |   TAB  |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ñ  |  ' ?    |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+---------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |  N   |  M   | ,  ; | . :  | -  _ |  RShift |
     * `----------------------+------+------+------+------+------|  |------+--------+------+------+------+---------------------'
     *                        |      |      | CMD  |      |      |  | Enter| Space| NAV  |      |       |
     *                        |      |      |      | Lower| ENT  |  | Lower| Raise|      |      |       |
     *                        `----------------------------------'  `-----------------------------------'
     */
    [_QWERTY] = LAYOUT_split_3x6_3(
      KC_ESC,  KC_Q,  KC_W,   KC_E,    KC_R,    KC_T,        KC_Y,     KC_U,     KC_I,    KC_O,   KC_P,     KC_BSPC,
      TAB_NAV, HRM_A, HRM_S,  HRM_D,   HRM_F,   KC_G,        KC_H,     HRM_J,    HRM_K,   HRM_L,  HRM_SCLN, ES_QUOT,
      KC_LSFT, KC_Z,  KC_X,   KC_C,    KC_V,    KC_B,        KC_N,     KC_M,     KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                              KC_LGUI, ML_LO,   OSK_JUMP,    KC_ENT,   SPC_HIG,  CTRL_HIG
    ),


    /*
     * Lower Layer: Symbols
     *
     * ,------------------------------------------.                              ,-------------------------------------------.
     * |       |  @   |      |      |  =   |  +   |                              |   |  |  {   |  }   |  =   |  `   |  DEL   |
     * |-------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |       |  !   |  "   |  #   |  $   |  %   |                              |  &   |  (   |  )   |  /   |   ?  |  ´ ¨   |
     * |-------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------| 
     * |       |  <   |  >   |      |  *   |  -   |      |      |  |      |      |  ¬   |  [   |  ]   |      | - _  |        |
     * `---------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                       |      |      |      |      |      |  |      |      |      |      |      |
     *                       |      |      |      |      |      |  |      |      |      |      |      |
     *                       `----------------------------------'  `----------------------------------'
     */
    [_LOWER] = LAYOUT_split_3x6_3(
       _______, ES_AT,   ES_BSLS,    _______, ES_EQL,  ES_PLUS,     ES_PIPE, ES_LCBR, ES_RCBR, ES_EQL,  KC_LBRC, KC_DEL,
       _______, ES_EXLM, ES_DQUO,    ES_HASH, ES_DLR,  ES_PERC,     ES_AMPR, ES_LPRN, ES_RPRN, ES_SLSH, ES_QUES, KC_QUOT,
       _______, ES_LABK, S(ES_LABK), _______, ES_ASTR, ES_MINS,     ES_NOT,  ES_LBRC, ES_RBRC, ES_EXLM, ES_QUES, _______,
                                     _______, _______, _______,     _______, _______, _______
     ),


    /*
     * Raise Layer: Number keys & media
     *
     * ,-------------------------------------------.                              ,---------------------------------------------.
     * |        |      | Prev | Play | Next |      |                              |      | Vol- | Vol+   | Mute |      |        |
     * |--------+------+------+------+------+------|                              |------+------+--------+------+------+--------|
     * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8     |  9   |  0   |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+--------+------+------+--------|
     * |        |      |      |      |      |      |      |      |  |      |      |      | BACK |CTRL+SPC| FRWD |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+--------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |        |
     *                        |      |      |      |      |      |  |      |      |      |      |        |
     *                        `----------------------------------'  `------------------------------------'
     */
    [_RAISE] = LAYOUT_split_3x6_3(
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, QTERM,   _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,    _______, _______, _______
    ),





    /*
    * Navigation Layer: Arrows, navigation, text macros
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_NAV] = LAYOUT_split_3x6_3(
      _______, _______, _______,    BCK_DEL_WORD,  FWD_DEL_WORD,   _______,     _______, LCMD(KC_LEFT), KC_UP,   LCMD(KC_RIGHT), KC_PGUP, KC_DEL,
      _______, KC_LSFT, KC_LSFT,    LALT(KC_LEFT), LALT(KC_RIGHT), _______,     _______, KC_LEFT,       KC_DOWN, KC_RIGHT,       KC_PGDN, _______,
      _______, _______, LCMD(KC_X), LCMD(KC_C),    LCMD(KC_V),     _______,     _______, GO_BACK,       _______, GO_FRWD,        _______, _______,
                                                 _______, _______, _______,     _______, _______, _______
    ),





    /*
     * Adjust Layer: Function keys, LED modes
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_ADJUST] = LAYOUT_split_3x6_3(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,     _______, _______, _______
    ),




    // /*
    //  * Layer template
    //  *
    //  * ,-------------------------------------------.                              ,-------------------------------------------.
    //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    //  *                        |      |      |      |      |      |  |      |      |      |      |      |
    //  *                        |      |      |      |      |      |  |      |      |      |      |      |
    //  *                        `----------------------------------'  `----------------------------------'
    //  */
    //     [_LAYERINDEX] = LAYOUT(
    //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //     ),
};

enum combo_events {
    CAPS_COMBO,
    COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;


const uint16_t PROGMEM caps_combo[] = {HRM_F, HRM_J, COMBO_END};


combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO_ACTION(caps_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        //caps_word_set(true);  // Activate Caps Word!
        caps_word_on();
      }
      break;

    // Other combos...
  }
}


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


// Macro Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_caps_word(keycode, record)) { return false; }
    switch (keycode) {
    case FWD_DEL_WORD:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_UP(X_LALT) SS_TAP(X_BSPC));
            return false;
        }
        break;

    case BCK_DEL_WORD:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LSFT) SS_UP(X_LALT) SS_TAP(X_BSPC));
            return false;
        }
        break;
    }
    return true;
};
