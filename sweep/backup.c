
#include QMK_KEYBOARD_H

this is a test, typing on my shiny new keyboard with very little amount of keys.... i donñtpp
#include "keymap_spanish.h"
#include "oneshot.h"
#include "swapper.h"
#include "caps_word.h"
#include "keycodes.h"
#include "quantum.h"


// convenience
#define ALFRED   RCTL(KC_SPC)
#define LLOWE    OSL(_LOWER)
#define LHIGH    OSL(_RAISE)
#define LMODS    MO(_MODS)
#define KCA_NAV  LT(_NAV, KC_A)
//#define ENT_LOW  LT(_LOWER, KC_ENT)
//#define BSPC_LOW LT(_LOWER, KC_BSPC)

// Shift
#define SHFT_Z    LSFT_T(KC_Z)
#define SHFT_SLSH RSFT_T(KC_SLSH)

// Layer definition
enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _NAV,
  _MODS,
  _ADJUST
};

// Macro Declarations
enum keycodes {
  OS_SHFT = SAFE_RANGE,
  OS_CTRL,
  OS_ALT,
  OS_CMD,
  FWD_DEL_WORD,   // Delete word (forward)
  BCK_DEL_WORD,   // Delete word (backwards)
  CLEAR,   // WTFBBQ?
  SW_APP,  // CMD+TAB
  SW_LANG
};

// enum sweep_tap_dances {
//   TD_Q_ESC,
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
      KC_Q,    KC_W,KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      KCA_NAV, KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      SHFT_Z,  KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  SHFT_SLSH,
                                 KC_LGUI, LLOWE,           LHIGH, LMODS
  ),

  [_LOWER] = LAYOUT(
      KC_ESC,  KC_QUOT,  ES_QUOT,    KC_GRV,  ES_PLUS,     ES_PIPE,  ES_LCBR, ES_RCBR, ES_EQL,  KC_BSPC,
      KC_TAB,  ES_DQUO,  ES_HASH,    ES_DLR,  ES_PERC,     ES_AMPR,  ES_LPRN, ES_RPRN, ES_SLSH, KC_ENT,
      ES_AT,   ES_LABK,  S(ES_LABK), ES_ASTR, ES_MINS,     ES_NOT,   ES_LBRC, ES_RBRC, ES_EXLM, ES_QUES,
                                    _______,  _______,    _______,  _______
  ),


  [_RAISE] = LAYOUT(
      KC_ESC,  KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,       XXXXXXX, KC_7, KC_8, KC_9, KC_DEL,
      KC_TAB,  XXXXXXX, XXXXXXX, ALFRED,  KC_VOLD,       XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,       KC_0,    KC_1, KC_2, KC_3, XXXXXXX,
                                _______,  _______,     _______,  _______
  ),

//    [_RAISE] = LAYOUT(
//        XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,      XXXXXXX, KC_VOLD,      KC_VOLU, KC_MUTE, XXXXXXX,
//
//        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,         KC_8,    KC_9,    KC_0,
//
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, RCTL(KC_SPC), XXXXXXX, XXXXXXX, XXXXXXX,
//
//                                  _______,  _______,     _______,  _______
//
//    ),


  [_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX,      XXXXXXX, G(KC_LEFT), KC_UP,   G(KC_RIGHT), KC_HOME,
      XXXXXXX, KC_LSFT, A(KC_LEFT), A(KC_RIGHT), XXXXXXX,      XXXXXXX, KC_LEFT,    KC_DOWN, KC_RIGHT,    KC_END,
      XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,     XXXXXXX,
                                       _______,  _______,       _______,  _______
  ),


    [_MODS] = LAYOUT(
        KC_ESC,  SW_APP,  KC_Q,    XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                  _______,  _______,    _______,  _______
    ),


  [_ADJUST] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11, KC_F12,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
                                _______, _______,      _______, _______
  )
};



  //       qk_tap_dance_action_t tap_dance_actions[] = {
    //       // Once for Q, twice for ESC
    //       [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  //       };


enum combo_events {
  CAPS_COMBO_Q,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_combo_q[] = {KC_F, KC_J, COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO_Q] = COMBO_ACTION(caps_combo_q)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO_Q:
      if (pressed) {
        caps_word_set(true);
      }
      break;
  }
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case CLEAR:
    case LLOWE:
    case LHIGH:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case CLEAR:
    case LLOWE:
    case LHIGH:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};


// Macro Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_APP, keycode, record);
    update_swapper(&sw_lang_active, KC_LCTL, KC_SPC, SW_LANG, keycode, record);
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    // switch (keycode) {
    // case FWD_DEL_WORD:
    //     if (record->event.pressed) {
    //         // when keycode QMKBEST is pressed
    //         SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_UP(X_LALT) SS_TAP(X_BSPC));
    //         return false;
    //     }
    //     break;
    //
    // case BCK_DEL_WORD:
    //     if (record->event.pressed) {
    //         // when keycode QMKBEST is pressed
    //         SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LSFT) SS_UP(X_LALT) SS_TAP(X_BSPC));
    //         return false;
    //     }
    //     break;
    // }
    return true;
};
