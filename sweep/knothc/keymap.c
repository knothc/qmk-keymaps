#include QMK_KEYBOARD_H

// Callum oneshot mods and swapper
// https://github.com/callum-oakley/qmk_firmware/blob/master/users/callum
// #include "caps_word.h"
#include "swapper.h"
#include "keycodes.h"
#include "keymap_spanish.h"

// knothc
#define SHFT_SLSH RSFT_T(KC_SLSH)
#define ALFRED    RCTL(KC_SPC)

#define KE_NAV LT(_NAV, KC_E)
#define TAB_NAV LT(_NAV, KC_TAB)
#define ENT_NAV LT(_NAV, KC_ENT)
#define ESC_NAV LT(_NAV, KC_ESC)
#define HI_SPC LT(_HIGH, KC_SPC)							
#define LO_ENT LT(_LOW, KC_ENT)
#define LO_TAB LT(_LOW, KC_TAB)

#define LWORD  A(KC_LEFT)
#define RWORD  A(KC_RIGHT)
#define LLINE  G(KC_LEFT)
#define RLINE  G(KC_RIGHT)
#define QTERM  C(KC_BSPC)
#define TMUXP  C(KC_B)

#define OSM_AC  OSM(MOD_LCTL|MOD_LALT)
#define OSM_ACG OSM(MOD_LCTL|MOD_LALT|MOD_LGUI)

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

// one-shot-key definitions
#define OSK_JUMP OSM(MOD_LCTL|MOD_LALT)   // define app-specific jumps using bettertouchtool or similar

#define W_FULL  LCAG(KC_O)
#define W_NEXT  LCAG(KC_P)
#define W_LEFT  LCAG(KC_J)  
#define W_RIGHT LCAG(KC_L)
#define W_UP    LCAG(KC_I)
#define W_DOWN  LCAG(KC_K)

#define GO_BACK G(C(KC_LEFT))
#define GO_FRWD G(C(KC_RIGHT))

// Macro Declarations
//enum custom_keycodes {
//  FWD_DEL_WORD = SAFE_RANGE,
//  BCK_DEL_WORD
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
    /*
     * DEFAULT
     *
     * ,----------------------------------.  ,----------------------------------.
     * |  Q   |  W   |  E   |  R   |  T   |  |  Y   |  U   |  I   |  O   |  P   |
     * |------+------+------+------+------|  |------+------+------+------+------|
     * |  A   |  S   |  D   |  F   |  G   |  |  H   |  J   |  K   |  L   |  Ñ   |
     * |------+------+------+------+------|  |------+------+------+------+------|
     * |  Z   |  X   |  C   |  V   |  B   |  |  N   |  M   | , ;  | . :  | - _  |
     * `--------------------+------+------|  |------+------+------+------+------'
     *                      |      |      |  |      |      |
     *                      `-------------'  `-------------'
     */	
    [_DEFAULT] = LAYOUT_split_3x5_2(
		KC_Q,    KC_W,    KE_NAV,  KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,            KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  SHFT_SLSH,
			           			   KC_BSPC, LO_TAB,          HI_SPC,  ENT_NAV
    ),
    
    /* 
     * LOWER (Symbols)
     *
     * ,----------------------------------.  ,----------------------------------.
     * |      |      |      |      |  +   |  |  |   |  {   |  }   |  =   |      |
     * |------+------+------+------+------|  |------+------+------+------+------|
     * |  @   |  "   |  #   |  $   |  %   |  |  &   |  (   |  )   |  /   |      |
     * |------+------+------+------+------|  |------+------+------+------+------|
     * |  <   |  >   |      |  *   |  -   |  |  ¬   |  [   |  ]   |  !   |  ?   |
     * `--------------------+------+------|  |------+------+------+------+------'
     *                      |      |      |  |      |      |
     *                      `-------------'  `-------------'
     */	
    [_LOW] = LAYOUT_split_3x5_2(  // "LOWER"
  	    KC_ESC,  KC_LBRC,    ES_QUOT, KC_QUOT, ES_PLUS,     ES_PIPE,  ES_LCBR, ES_RCBR, ES_EQL,  KC_DEL,
  	    ES_AT,   ES_DQUO,    ES_HASH, ES_DLR,  ES_PERC,     ES_AMPR,  ES_LPRN, ES_RPRN, ES_SLSH, KC_ENT,
  	    ES_LABK, S(ES_LABK), KC_BSPC, ES_ASTR, ES_MINS,     ES_NOT,   ES_LBRC, ES_RBRC, ES_EXLM, ES_QUES,
  					                 _______,  _______,    _______,  _______
    ),

    /* 
     * HIGHER (Numbers)
     *
     * ,----------------------------------.  ,----------------------------------.
     * | ESC  |  ⏮  |  ▶️   |  ⏭   |      |  |      |VOL-  | VOL+ | MUTE |      |
     * |------+------+------+------+------|  |------+------+------+------+------|
     * |  1   |  2   |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   |
     * |------+------+------+------+------|  |------+------+------+------+------|
     * | TERM |      |      |      |      |  |      |      |      |      |TMUXP |
     * `--------------------+------+------|  |------+------+------+------+------'
     *                      |      |      |  |      |      |
     *                      `-------------'  `-------------'
     */	
    [_HIGH] = LAYOUT_split_3x5_2(  // "RAISE"
		KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,       XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX,
		KC_1,   KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
		QTERM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TMUXP,
                                  _______, _______,       _______,  _______
    ),



    [_COMMON] = LAYOUT_split_3x5_2(  // "COMMON"
		KC_ESC,  _______, _______, _______, _______,      _______, _______, _______, _______, KC_BSPC,
		KC_LSFT, _______, _______, _______, _______,      _______, _______, _______, _______, KC_ENT,
		_______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                                   _______, _______,      _______, _______
    ),


//    [_HIGH] = LAYOUT_split_3x5_2(  // "RAISE"
//		KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,       KC_VOLU, KC_7, KC_8, KC_9, KC_DEL,
//		KC_TAB, ALFRED,  OSM_ACG, OSM_AC,  XXXXXXX,       KC_VOLD, KC_4, KC_5, KC_6, KC_0,
//		QTERM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MUTE, KC_1, KC_2, KC_3, TMUXP,
//                                  _______, _______,       _______,  _______
//    ),<>


    [_MODS] = LAYOUT_split_3x5_2( // ONE SHOT MODS
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX,     XXXXXXX, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		                           KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS
    ),

    [_NAV] = LAYOUT_split_3x5_2( // NAVIGATION
		XXXXXXX, BCK_DEL_WORD, XXXXXXX, FWD_DEL_WORD, XXXXXXX,      XXXXXXX, LLINE,   KC_UP,   RLINE,    KC_PGUP,
		KC_LSFT, XXXXXXX,      LWORD,   RWORD,        XXXXXXX,      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,
		XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX, GO_BACK, XXXXXXX, GO_FRWD,  XXXXXXX,
										_______,      _______,      _______, _______
    ),

    // TODO:
    // KC_QUOT = ´      ES_QUOT = '       KC_LBRC = ` 
    // enter, bspc, del

    [_FUN] = LAYOUT_split_3x5_2(
		KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,   KC_NO,   W_UP,    W_FULL,  W_NEXT,
 		KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,   W_LEFT,  W_DOWN,  W_RIGHT, KC_NO, 
     	KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
		                             KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
    ),
};

enum combo_events {
  // qwerty layer combos
  CAPS_COMBO_Q,
  ENTER_COMBO_Q,
  //TAB_COMBO_Q,
  //BSP_COMBO_Q,
  //DEL_COMBO_Q,
  //CTRLC_COMBO_Q,
  ESC_COMBO_Q,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;
// qwerty combos
const uint16_t PROGMEM caps_combo_q[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM enter_combo_q[] = {KC_J, KC_K, COMBO_END};
//const uint16_t PROGMEM tab_combo_q[] = {KC_F, KC_D, COMBO_END};
//const uint16_t PROGMEM bsp_combo_q[] = {KC_F, KC_S, COMBO_END};
//const uint16_t PROGMEM del_combo_q[] = {KC_J, KC_L, COMBO_END};
//// Ctrl-c combo mostly for Emacs
//const uint16_t PROGMEM ctrlc_combo_q[] = {KC_J, KC_K, KC_L, COMBO_END};  // TODO: Update to something useful
const uint16_t PROGMEM esc_combo_q[] = {KC_F, KC_D, KC_S, COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO_Q] = COMBO_ACTION(caps_combo_q),
  [ENTER_COMBO_Q] = COMBO(enter_combo_q, KC_ENT),
  //[TAB_COMBO_Q] = COMBO(tab_combo_q, KC_TAB),
  //[BSP_COMBO_Q] = COMBO(bsp_combo_q, KC_BSPC),
  //[DEL_COMBO_Q] = COMBO(del_combo_q, KC_DEL),
  //[CTRLC_COMBO_Q] = COMBO(ctrlc_combo_q, LCTL(KC_C)),   // TODO: Update to something useful
  [ESC_COMBO_Q] = COMBO(esc_combo_q, KC_ESC),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO_Q:
      if (pressed) {
        caps_word_on();  // Activate Caps Word!
      }
      break;

    // Other combos...
  }
}


//bool is_oneshot_cancel_key(uint16_t keycode) {
//    switch (keycode) {
//	case CLEAR:
//    case NUM:
//    case SYM:
//        return true;
//    default:
//        return false;
//    }
//}
//
//bool is_oneshot_ignored_key(uint16_t keycode) {
//    switch (keycode) {
//	case CLEAR:
//    case NUM:
//    case SYM:
//    case OS_SHFT:
//    case OS_CTRL:
//    case OS_ALT:
//    case OS_CMD:
//        return true;
//    default:
//        return false;
//    }
//}

//bool sw_app_active = false;
//
//oneshot_state os_shft_state = os_up_unqueued;
//oneshot_state os_ctrl_state = os_up_unqueued;
//oneshot_state os_alt_state = os_up_unqueued;
//oneshot_state os_cmd_state = os_up_unqueued;
//


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


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _HIGH, _LOW, _FUN);
}   


    // /*
    //  * Layer template
    //  *
    //  * ,----------------------------------.  ,----------------------------------.
    //  * |      |      |      |      |      |  |      |      |      |      |      |
    //  * |------+------+------+------+------|  |------+------+------+------+------|
    //  * |      |      |      |      |      |  |      |      |      |      |      |
    //  * |------+------+------+------+------|  |------+------+------+------+------|
    //  * |      |      |      |      |      |  |      |      |      |      |      |
    //  * `--------------------+------+------|  |------+------+------+------+------'
    //  *                      |      |      |  |      |      |
    //  *                      |      |      |  |      |      |
    //  *                      `-------------'  `-------------'
    //  */	
