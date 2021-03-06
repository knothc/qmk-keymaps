#include QMK_KEYBOARD_H

// Callum oneshot mods and swapper
// https://github.com/callum-oakley/qmk_firmware/blob/master/users/callum
#include "caps_word.h"
#include "oneshot.h"
#include "swapper.h"
#include "keycodes.h"
#include "keymap_spanish.h"

// knothc
#define SHFT_Z    LSFT_T(KC_Z)
#define SHFT_SLSH RSFT_T(KC_SLSH)
#define ALFRED    RCTL(KC_SPC)

#define ML_LO   LT(_LOW, KC_TAB)

#define KCA_NAV LT(_NAV, KC_A)
#define HI_SPC  LT(_HIGH, KC_SPC)

#define LWORD  A(KC_LEFT)
#define RWORD  A(KC_RIGHT)
#define LLINE  G(KC_LEFT)
#define RLINE  G(KC_RIGHT)
#define QTERM  C(KC_BSPC)
#define TMUXP  C(KC_B)

#define OSM_AC  OSM(MOD_LCTL|MOD_LALT)
#define OSM_ACG OSM(MOD_LCTL|MOD_LALT|MOD_LGUI)

// TODO: add or not add?
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT_split_3x5_2(
		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		KCA_NAV, KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
		SHFT_Z,  KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  SHFT_SLSH,
															 KC_LGUI, ML_LO,           HI_SPC,  SYM
  ),

	[_HIGH] = LAYOUT_split_3x5_2(  // "RAISE"
		KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,       KC_VOLU, KC_7, KC_8, KC_9, KC_DEL,
		KC_TAB, ALFRED,  OSM_ACG, OSM_AC,  XXXXXXX,       KC_VOLD, KC_4, KC_5, KC_6, KC_0,
		QTERM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MUTE, KC_1, KC_2, KC_3, TMUXP,
															_______, _______,       _______,  _______
  ),

	[_MODS] = LAYOUT_split_3x5_2( // ONE SHOT MODS
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX,     XXXXXXX, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                           KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS
  ),

	[_NAV] = LAYOUT_split_3x5_2( // NAVIGATION
		XXXXXXX, XXXXXXX, BCK_DEL_WORD, FWD_DEL_WORD, XXXXXXX,      XXXXXXX, LLINE,   KC_UP,   RLINE,    KC_HOME,
		XXXXXXX, KC_LSFT, LWORD,        RWORD,        XXXXXXX,      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,
		XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
																		_______,      _______,       _______, _______
  ),

	[_LOW] = LAYOUT_split_3x5_2(  // "LOWER"
  	SW_APP,  ES_QUOT,  KC_LBRC,    KC_QUOT, ES_PLUS,     ES_PIPE,  ES_LCBR, ES_RCBR, ES_EQL,  KC_BSPC,
  	KC_TAB,  ES_DQUO,  ES_HASH,    ES_DLR,  ES_PERC,     ES_AMPR,  ES_LPRN, ES_RPRN, ES_SLSH, KC_ENT,
  	ES_AT,   KC_GRV,   S(KC_GRV),  ES_ASTR, ES_MINS,     ES_NOT,   ES_LBRC, ES_RBRC, ES_EXLM, ES_QUES,
  																_______,  _______,    _______,  _______
  ),

  //	[_LOW] = LAYOUT_split_3x5_2(
  //      RESET,    KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,     HOOK,   LHLF,  FULL,  RHLF,  KC_NO,
  //			KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,  W4,    W5,    W6,    KC_NO,
  //			TG_QWTY,  KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,     KC_NO,  W1,    W2,    W3,    KC_NO,
  //			                          KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS
  //								),

	//	[_HIGH] = LAYOUT_split_3x5_2(
  //			KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_PERC,   KC_PLUS, KC_7, KC_8, KC_9, KC_MINS,
  //			OS_SHFT, OS_CTRL, OS_ALT, OS_CMD,   KC_EQL,    KC_DOT,  KC_4, KC_5, KC_6, KC_COLN,
  //			KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_UNDS,   KC_ASTR, KC_1, KC_2, KC_3, KC_SLSH,
  //			                        KC_TRNS,    KC_TRNS,   KC_0, FUN
  //  ),

  //	[_FUN] = LAYOUT_split_3x5_2(
  //			KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_CAPS,      KC_F12,  KC_F7, KC_F8, KC_F9, KC_NO,
  //			OS_SHFT, OS_CTRL,  OS_ALT,   OS_CMD,   KC_ESC,       KC_F11,  KC_F4, KC_F5, KC_F6, KC_NO,
  //			KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_F10,  KC_F1, KC_F2, KC_F3, KC_NO,
  //			                             KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS
  //  )
};

enum combo_events {
  // qwerty layer combos
  CAPS_COMBO_Q,
  ENTER_COMBO_Q,
  TAB_COMBO_Q,
  BSP_COMBO_Q,
  DEL_COMBO_Q,
  CTRLC_COMBO_Q,
  ESC_COMBO_Q,
  // beakl layer combos
  CAPS_COMBO_B,
  ENTER_COMBO_B,
  TAB_COMBO_B,
  BSP_COMBO_B,
  DEL_COMBO_B,
  CTRLC_COMBO_B,
  ESC_COMBO_B,
  // braces
  LCBR_COMBO_B,
  LPRN_COMBO_B,
  LBRC_COMBO_B,
  RCBR_COMBO_B,
  RPRN_COMBO_B,
  RBRC_COMBO_B,
  // Other combos...
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
// qwerty combos
const uint16_t PROGMEM caps_combo_q[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM enter_combo_q[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM tab_combo_q[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM bsp_combo_q[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM del_combo_q[] = {KC_J, KC_L, COMBO_END};
// Ctrl-c combo mostly for Emacs
const uint16_t PROGMEM ctrlc_combo_q[] = {KC_J, KC_K, KC_L, COMBO_END};  // TODO: Update to something useful
const uint16_t PROGMEM esc_combo_q[] = {KC_F, KC_D, KC_S, COMBO_END};

// beakl combos // TODO: Remove BEAKL related combos
const uint16_t PROGMEM caps_combo_b[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM enter_combo_b[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM tab_combo_b[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM bsp_combo_b[] = {KC_I, KC_A, COMBO_END};
const uint16_t PROGMEM del_combo_b[] = {KC_S, KC_N, COMBO_END};
// braces - vertical combos 				// TODO: Remove?
const uint16_t PROGMEM lcbr_combo_b[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM lprn_combo_b[] = {KC_U, KC_A, COMBO_END};
const uint16_t PROGMEM lbrc_combo_b[] = {KC_X, KC_DOT, COMBO_END};
const uint16_t PROGMEM rcbr_combo_b[] = {KC_M, KC_T, COMBO_END};
const uint16_t PROGMEM rprn_combo_b[] = {KC_C, KC_S, COMBO_END};
const uint16_t PROGMEM rbrc_combo_b[] = {KC_G, KC_D, COMBO_END};
// Ctrl-c combo mostly for Emacsaz444
const uint16_t PROGMEM ctrlc_combo_b[] = {KC_S, KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM esc_combo_b[] = {KC_I, KC_E, KC_A, COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO_Q] = COMBO_ACTION(caps_combo_q),
  [ENTER_COMBO_Q] = COMBO(enter_combo_q, KC_ENT),
  [TAB_COMBO_Q] = COMBO(tab_combo_q, KC_TAB),
  [BSP_COMBO_Q] = COMBO(bsp_combo_q, KC_BSPC),
  [DEL_COMBO_Q] = COMBO(del_combo_q, KC_DEL),
  [CTRLC_COMBO_Q] = COMBO(ctrlc_combo_q, LCTL(KC_C)),   // TODO: Update to something useful
  [ESC_COMBO_Q] = COMBO(esc_combo_q, KC_ESC),
  // Other combos...
  [CAPS_COMBO_B] = COMBO_ACTION(caps_combo_b),
  [ENTER_COMBO_B] = COMBO(enter_combo_b, KC_ENT),
  [TAB_COMBO_B] = COMBO(tab_combo_b, KC_TAB),
  [BSP_COMBO_B] = COMBO(bsp_combo_b, KC_BSPC),
  [DEL_COMBO_B] = COMBO(del_combo_b, KC_DEL),
  [CTRLC_COMBO_B] = COMBO(ctrlc_combo_b, LCTL(KC_C)),
  [ESC_COMBO_B] = COMBO(esc_combo_b, KC_ESC),
  [LCBR_COMBO_B] = COMBO(lcbr_combo_b, KC_LCBR),
  [LPRN_COMBO_B] = COMBO(lprn_combo_b, KC_LPRN),
  [LBRC_COMBO_B] = COMBO(lbrc_combo_b, KC_LBRC),
  [RCBR_COMBO_B] = COMBO(rcbr_combo_b, KC_RCBR),
  [RPRN_COMBO_B] = COMBO(rprn_combo_b, KC_RPRN),
  [RBRC_COMBO_B] = COMBO(rbrc_combo_b, KC_RBRC),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO_Q:
    case CAPS_COMBO_B:
      if (pressed) {
        caps_word_set(true);  // Activate Caps Word!
      }
      break;

    // Other combos...
  }
}


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
	case CLEAR:
    case NUM:
    case SYM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
	case CLEAR:
    case NUM:
    case SYM:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_app_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	if (!process_caps_word(keycode, record)) { return false; }

	update_swapper(
		&sw_app_active, KC_LGUI, KC_TAB, SW_APP,
		keycode, record
	);
	update_oneshot(
	  &os_shft_state, KC_LSFT, OS_SHFT,
	  keycode, record
	);
	update_oneshot(
	  &os_ctrl_state, KC_LCTL, OS_CTRL,
	  keycode, record
	);
	update_oneshot(
	  &os_alt_state, KC_LALT, OS_ALT,
		keycode, record
	);
	update_oneshot(
	  &os_cmd_state, KC_LCMD, OS_CMD,
	  keycode, record
	);

	switch (keycode) {
		case CLEAR:
			clear_oneshot_mods();
			if (get_oneshot_layer() != 0) {
				clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
			}
			layer_move(_DEFAULT);
			return false;
			break;

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

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _LMOD, _RMOD, _HIGH); */
/* } */
