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
#include "keymap_spanish.h"
#include <stdio.h>

// Layer definitions
enum layers {
    _QWERTY = 0,
    _LOWER,
    _NAV,
    _RAISE,
    _ADJUST
};

// Macro Declarations
enum custom_keycodes {
  FWD_DEL_WORD = SAFE_RANGE,
  BCK_DEL_WORD
};

// Left-hand home row mods
#define HRM_A  LSFT_T(KC_A)
#define HRM_S  CTL_T(KC_S)
#define HRM_D  ALT_T(KC_D)
#define HRM_F  CMD_T(KC_F)

// Right-hand home row mods
#define HRM_J    RCMD_T(KC_J)
#define HRM_K    ALT_T(KC_K)
#define HRM_L    CTL_T(KC_L)
#define HRM_SCLN LSFT_T(KC_SCLN)

// Layer Tap definitons
#define ENT_HIG LT(_RAISE, KC_ENT)
#define SPC_HIG LT(_RAISE, KC_SPC)
#define TAB_NAV LT(_NAV, KC_TAB)
#define ENT_NAV LT(_NAV, KC_ENT)
#define ENT_LOW LT(_LOWER, KC_ENT)
#define BSPC_LOW LT(_LOWER, KC_BSPC)

// one-shot-key definitions
#define OSK_CA OSM(MOD_LCTL|MOD_LALT)  // I use this combinations with BetterTouchTool shorcuts to jump/open a specific application


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TAB_NAV,   HRM_A,   HRM_S,   HRM_D,   HRM_F,    KC_G,                         KC_H,   HRM_J,   HRM_K,   HRM_L,HRM_SCLN, ES_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LGUI, ENT_LOW,    SPC_HIG,MO(_NAV),  OSK_CA
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   ES_AT,   XXXXXXX, XXXXXXX,  ES_EQL, ES_PLUS,                      ES_PIPE, ES_LCBR, ES_RCBR,  ES_EQL, XXXXXXX,  KC_DEL,
  //|--------+--------+----------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ES_EXLM,   ES_DQUO, ES_HASH,  ES_DLR, ES_PERC,                      ES_AMPR, ES_LPRN, ES_RPRN, ES_SLSH, ES_QUES, KC_QUOT,
  //|--------+--------+----------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ES_LABK,S(ES_LABK), XXXXXXX, ES_ASTR, ES_MINS,                       ES_NOT, ES_LBRC, ES_RBRC, XXXXXXX, XXXXXXX, KC_TILD,
  //|--------+--------+----------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,---------------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                      XXXXXXX,     KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+------------+--------+--------+--------+--------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,        KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+------------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,RCTL(KC_SPC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+------------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX,  BCK_DEL_WORD,   FWD_DEL_WORD, XXXXXXX,                      XXXXXXX, LCMD(KC_LEFT),   KC_UP, LCMD(KC_RIGHT), KC_HOME, KC_DEL,
  //|--------+--------+--------+--------------+---------------+--------|                    |--------+--------------+--------+---------------+--------+--------|
      _______, KC_LSFT, KC_LSFT, LALT(KC_LEFT), LALT(KC_RIGHT), XXXXXXX,                      XXXXXXX,       KC_LEFT, KC_DOWN,       KC_RIGHT,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------------+---------------+--------|                    |--------+--------------+--------+---------------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,        XXXXXXX, XXXXXXX,                      XXXXXXX,       XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------------+---------------+--------+--------|  |--------+--------+--------------+--------+---------------+--------+--------|
                                                       _______, _______, _______,    _______, _______,       _______
                                            //`---------------------------------'  `--------------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_NAV 4
#define L_RAISE 8
#define L_ADJUST 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("raise"), false);
            break;
        case L_NAV:
            oled_write_ln_P(PSTR("nav"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
}
#endif // OLED_ENABLE
