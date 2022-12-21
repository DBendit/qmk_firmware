#include QMK_KEYBOARD_H
#include "features/achordion.h"

// Each layer gets a name for readability, which is then used in the keymap
// matrix below. The underscores don't mean anything - you can have a layer
// called STUFF or any other name. Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _SYMB 2
#define _ADJUST 3
#define _GAMING 4

enum layers {
  QWERTY,
  COLEMAK,
  SYMB,
  GAMING,
  ADJUST,
};

enum unicode_names {
  PLUS1,
  PARTY,
  NEG1,
  RAGE,
  UPSIDE_DOWN,
  MELTING,
  ROLLING_EYES,
  JOY,
  LAUGHING,
};

// clang-format off
const uint32_t PROGMEM unicode_map[] = {
  [PLUS1]        = 0x1F44D,
  [PARTY]        = 0x1F973,
  [NEG1]         = 0x1F44E,
  [RAGE]         = 0x1F621,
  [UPSIDE_DOWN]  = 0x1F643,
  [MELTING]      = 0x1FAE0,
  [ROLLING_EYES] = 0x1F644,
  [JOY]          = 0x1F602,
  [LAUGHING]     = 0x1F923,
};

#define SFT_D       MT(MOD_LSFT, KC_D)
#define SFT_K       MT(MOD_RSFT, KC_K)
#define ALT_S       MT(MOD_LALT, KC_S)
#define CTL_F       MT(MOD_LCTL, KC_F)
#define CTL_J       MT(MOD_RCTL, KC_J)
#define ALT_L       MT(MOD_RALT, KC_L)
#define LT2_A       LT(_SYMB, KC_A)
#define LT2_SCL     LT(_SYMB, KC_SCLN)
#define GUI_Z       MT(MOD_LGUI, KC_Z)
#define GUI_SLSH    MT(MOD_RGUI, KC_SLSH)
#define SFT_S       MT(MOD_LSFT, KC_S)
#define SFT_E       MT(MOD_RSFT, KC_E)
#define ALT_R       MT(MOD_LALT, KC_R)
#define CTL_TC      MT(MOD_LCTL, KC_T)
#define CTL_N       MT(MOD_RCTL, KC_N)
#define ALT_I       MT(MOD_RALT, KC_I)
#define LT2_A       LT(_SYMB, KC_A)
#define LT2_O       LT(_SYMB, KC_O)
#define GUI_Z       MT(MOD_LGUI, KC_Z)
#define GUI_SLSH    MT(MOD_RGUI, KC_SLSH)

#define KC_SYM      MO(_SYMB)
#define KC_ADJ      TG(_ADJUST)
#define KC_QWE      DF(_QWERTY)
#define KC_COL      DF(_COLEMAK)
#define KC_GAM      TG(_GAMING)

#define KC_POS      XP(PLUS1, PARTY)
#define KC_NEG      XP(NEG1, RAGE)
#define KC_SAR      XP(UPSIDE_DOWN, ROLLING_EYES)
#define KC_LAF      XP(JOY, LAUGHING)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_SAR  ,                          KC_LAF  , KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,LT2_A   ,ALT_S   ,SFT_D   ,CTL_F   ,KC_G    ,KC_ENT  ,                          KC_ENT  ,KC_H    ,CTL_J   ,SFT_K   ,ALT_L   ,LT2_SCL ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,GUI_Z   ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,GUI_SLSH,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LWIN ,KC_LALT ,KC_SYM  ,     KC_NEG  ,    KC_BSPC ,KC_DEL  ,        KC_ENT  ,KC_SPC  ,    KC_POS  ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,_______ ,                          _______ ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,LT2_A   ,ALT_R   ,SFT_S   ,CTL_TC  ,KC_G    ,_______ ,                          _______ ,KC_M    ,CTL_N   ,SFT_E   ,ALT_I   ,LT2_O   ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,GUI_Z   ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,_______ ,_______ ,        _______ ,_______ ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,GUI_SLSH,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LBRC ,KC_RBRC ,XXXXXXX ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_EQL  ,KC_PLUS ,_______ ,                          _______ ,KC_MINS ,KC_UNDS ,KC_LPRN ,KC_RPRN ,KC_PIPE ,KC_ADJ  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,XXXXXXX ,KC_LCBR ,KC_RCBR ,KC_BSLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,XXXXXXX ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    XXXXXXX ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),


  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,_______ ,_______ ,                          _______ ,_______ ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Z    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,KC_SYM  ,     KC_SPC  ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, QK_BOOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ADJ  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_GAM  ,UC_WINC ,                          UC_MAC  ,XXXXXXX ,KC_QWE  ,KC_COL  ,XXXXXXX ,XXXXXXX ,KC_ADJ  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case SFT_D:
    case SFT_K:
    case SFT_E:
    case SFT_S:
      return true;
    default:
      return false;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case SFT_D:
    case SFT_K:
    case SFT_E:
    case SFT_S:
      return 150;
    default:
      return TAPPING_TERM;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }

  return true;
}

// Sticking with default impl, since I keep triggering Alt-'-' when trying to
// type "brazil-"
/*
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  switch (other_keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      other_keycode &= 0xff;  // Get base keycode
  }

  // Allow same-hand holds with non-alpha keys
  if (other_keycode > KC_Z) { return true; }

  return achordion_opposite_hands(tap_hold_record, other_record);
}
*/

void matrix_scan_user(void) {
  achordion_task();
}

