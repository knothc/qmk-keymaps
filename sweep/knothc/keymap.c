
#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include <stdio.h>

// Layer definition
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
  [_QWERTY] = LAYOUT(
  //,--------------------------------------------.    ,----------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|    |--------+--------+--------+--------+----------|
      HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,         KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN,
  //|--------+--------+--------+--------+--------|    |--------+--------+--------+--------+----------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  //|--------+--------+--------+--------+--------|    |--------+---------+--------+--------+---------|
                                 KC_LGUI, ENT_LOW,      SPC_HIG, MO(_NAV)
                             //`--------+--------'    `--------+---------'

  ),

  [_LOWER] = LAYOUT(
  //,--------------------------------------------.    ,----------------------------------------------.
      ES_AT,   XXXXXXX, XXXXXXX,  ES_EQL, ES_PLUS,     ES_PIPE,  ES_LCBR, ES_RCBR,  ES_EQL, KC_LBRC,
  //|--------+--------+--------+--------+--------|    |--------+--------+--------+--------+----------|
      ES_EXLM, ES_DQUO, ES_HASH,  ES_DLR, ES_PERC,     ES_AMPR,  ES_LPRN, ES_RPRN, ES_SLSH, ES_QUES,
  //|--------+--------+--------+--------+--------|    |--------+--------+--------+--------+----------|
      ES_LABK,S(ES_LABK), XXXXXXX, ES_ASTR, ES_MINS,   ES_NOT,   ES_LBRC, ES_RBRC, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|    |--------+---------+--------+--------+---------|
                                 _______,  _______,     _______,  _______
                             //`--------+--------'    `--------+---------'
  ),


  [_RAISE] = LAYOUT(
  //,--------------------------------------------.    ,----------------------------------------------.
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,      XXXXXXX, KC_VOLD,  KC_VOLU, KC_MUTE, XXXXXXX,
  //|--------+--------+--------+--------+--------|    |--------+---------+--------+--------+---------|
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,     KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|    |--------+---------+--------+--------+---------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,RCTL(KC_SPC), XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|    |--------+---------+--------+--------+---------|
                                 _______,  _______,     _______,  _______
                             //`--------+--------'    `--------+---------'
  ),

  // TODO: FORMAT ↓

  [_NAV] = LAYOUT(
  //,--------------------------------------------.    ,----------------------------------------------.
      XXXXXXX, XXXXXXX, BCK_DEL_WORD, FWD_DEL_WORD, XXXXXXX,      XXXXXXX, LCMD(KC_LEFT), KC_UP,    LCMD(KC_RIGHT), KC_HOME,
  //|--------+--------+--------+--------+--------|    |--------+---------+--------+--------+---------|
      KC_LSFT, KC_LSFT, LALT(KC_LEFT), LALT(KC_RIGHT), XXXXXXX,   XXXXXXX, KC_LEFT,       KC_DOWN,  KC_RIGHT,  KC_END,
  //|--------+--------+--------+--------+--------|    |--------+---------+--------+--------+---------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX,       XXXXXXX,  XXXXXXX,   XXXXXXX,
  //|--------+--------+--------+--------+--------|    |--------+---------+--------+--------+---------|
                                 _______,  _______,     _______,  _______
                             //`--------+--------'    `--------+---------'
  ),

// TODO: Adjust and format ↓

  [_ADJUST] = LAYOUT(
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
