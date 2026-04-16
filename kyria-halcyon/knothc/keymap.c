/*
 * Copyright 2024 Thomas Baart <thomas@splitkb.com>
 *
 * This keymap is a port of a Kyria rev3 keymap for the Kyria rev4 (Halcyon series).
 *
 * The physical key layout is identical to the 50-key rev3 layout.
 *
 * Changes made for rev4 compatibility:
 * - Updated RGB keycodes from RGBLIGHT to RGB_MATRIX.
 * - Added a placeholder for encoder functionality.
 * - Updated OLED text to reflect rev4.
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
     * Layout is identical to the 50-key rev3 layout.
     */
    [_QWERTY] = LAYOUT(
      KC_ESC,  KC_Q,  KC_W,   KC_E,     KC_R,    KC_T,                                               KC_Y,     KC_U,     KC_I,    KC_O,   KC_P,     KC_BSPC,
      TAB_NAV, HRM_A, HRM_S,  HRM_D,    HRM_F,   KC_G,                                               KC_H,     HRM_J,    HRM_K,   HRM_L,  HRM_SCLN, ES_QUOT,
      KC_LSFT, KC_Z,  KC_X,   KC_C,     KC_V,    KC_B,   XXXXXXX, OSK_JUMP,       OSK_JUMP, XXXXXXX, KC_N,     KC_M,     KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                              KC_LCTL, KC_LALT, KC_LGUI, ML_LO,   OSK_JUMP,       KC_ENT,   SPC_HIG, CTRL_HIG, MO(_NAV), KC_RALT
    ),


    /*
     * Lower Layer: Symbols
     */
    [_LOWER] = LAYOUT(
       _______, ES_AT,   ES_BSLS,    _______, ES_EQL,  ES_PLUS,                                        ES_PIPE, ES_LCBR, ES_RCBR, ES_EQL,  KC_LBRC, KC_DEL,
       _______, ES_EXLM, ES_DQUO,    ES_HASH, ES_DLR,  ES_PERC,                                        ES_AMPR, ES_LPRN, ES_RPRN, ES_SLSH, ES_QUES, KC_QUOT,
       _______, ES_LABK, S(ES_LABK), _______, ES_ASTR, ES_MINS, _______, _______,    _______, _______, ES_NOT,  ES_LBRC, ES_RBRC, ES_EXLM, ES_QUES, _______,
                                     _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
     ),


    /*
     * Raise Layer: Number keys & media
     */
    [_RAISE] = LAYOUT(
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                                        _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, QTERM,   _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),


    /*
    * Navigation Layer: Arrows, navigation, text macros
    */
    [_NAV] = LAYOUT(
      _______, _______, _______,    BCK_DEL_WORD,  FWD_DEL_WORD,   _______,                                         _______, LCMD(KC_LEFT), KC_UP,   LCMD(KC_RIGHT), KC_PGUP, KC_DEL,
      _______, KC_LSFT, KC_LSFT,    LALT(KC_LEFT), LALT(KC_RIGHT), _______,                                         _______, KC_LEFT,       KC_DOWN, KC_RIGHT,       KC_PGDN, _______,
      _______, _______, LCMD(KC_X), LCMD(KC_C),    LCMD(KC_V),     _______, _______, _______,     _______, _______, _______, GO_BACK,       _______, GO_FRWD,        _______, _______,
                                                 _______, _______, _______, _______, _______,     _______, _______, _______,       _______, _______
    ),


    /*
     * Adjust Layer: Function keys, LED modes (Updated for RGB Matrix)
     */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      RM_SPDU, RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      RM_SPDD, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left encoder */
        if (clockwise) {
            // Your code here (e.g., tap_code(KC_VOLU);)
        } else {
            // Your code here (e.g., tap_code(KC_VOLD);)
        }
    } else if (index == 1) { /* Right encoder */
        if (clockwise) {
            // Your code here
        } else {
            // Your code here
        }
    }
    return true;
}
#endif


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
        caps_word_on();
      }
      break;
  }
}


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_caps_word(keycode, record)) { return false; }
    switch (keycode) {
    case FWD_DEL_WORD:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_UP(X_LALT) SS_TAP(X_BSPC));
            return false;
        }
        break;

    case BCK_DEL_WORD:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LSFT) SS_UP(X_LALT) SS_TAP(X_BSPC));
            return false;
        }
        break;
    }
    return true;
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_status(void) {
    // QMK Logo and version information
    oled_write_P(PSTR("QMK\n\n"), false);
    oled_write_P(PSTR("Kyria r4.0\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("     "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif


