/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 Simon Korzun <@korzun>

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
#include <stdio.h>

enum layers {
    _COLE,
    _QWER,
    _SYM,
    _NUM,
    _NAVI,
    _FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,  KC_SPC,MO(_SYM),MO(_NUM),MO(_NAVI)
                                      //`--------------------------'  `--------------------------'
  ),

    [_QWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,  KC_SPC,MO(_SYM),MO(_NUM),MO(_NAVI)
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_HASH, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC,                      KC_CIRC, KC_PEQL, KC_PAST, KC_PPLS, KC_QUOT, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,MO(_FUNC), KC_SCLN, KC_LCBR, KC_RCBR,  KC_DLR,                KC_PMNS, KC_PIPE, KC_LBRC, KC_RBRC,   KC_NO,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD,   KC_AT, KC_BSLS,  KC_GRV, KC_EXLM,                      KC_UNDS, KC_AMPR, KC_COMM,  KC_DOT, KC_QUES, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_HASH, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC,                      KC_CIRC, KC_PEQL, KC_PAST, KC_PPLS,   KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,  KC_DLR,                      KC_PMNS,    KC_7,    KC_8,    KC_9,    KC_0, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD,   KC_AT, KC_BSLS,    KC_5, KC_EXLM,                      KC_UNDS,    KC_6, KC_COMM,  KC_DOT, KC_SLSH, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,      KC_NO,   KC_TRNS, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,  KC_NO,LGUI(KC_X),LGUI(KC_C),LGUI(KC_V),KC_NO,                      KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LCTL, KC_LGUI, KC_LSFT, KC_LALT, LGUI(KC_Z),                   KC_HOME, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_NO, KC_BTN1, KC_BTN2, KC_RALT, LGUI(LSFT(KC_Z)),              KC_END, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     LGUI(KC_SPC), KC_TRNS, KC_TRNS,      KC_NO,   KC_NO,  KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,   KC_NO, KC_MRWD, KC_MFFD, KC_MPLY,   KC_NO,                 DF(_COLE),   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE,   KC_NO,                  DF(_QWER),   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_NO,RGB_RMOD, RGB_MOD, RGB_TOG,   KC_NO,                        KC_NO,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_state(uint8_t modifiers) {
    bool active=false;

    if(get_highest_layer(default_layer_state) == _QWER) {
        active = true;
        oled_write_P(PSTR("Q"), false);
    }
    if(modifiers & MOD_MASK_SHIFT) {
        active = true;
        oled_write_P(PSTR("S"), false);
    }
    if(modifiers & MOD_MASK_CTRL) {
        active = true;
        oled_write_P(PSTR("C"), false);
    }
    if(modifiers & MOD_MASK_ALT) {
        active = true;
        oled_write_P(PSTR("A"), false);
    }
    if(modifiers & MOD_MASK_GUI) {
        active = true;
        oled_write_P(PSTR("G"), false);
    }

    if(layer_state_is(_FUNC)) {
        if(active == true) {
            oled_write_P(PSTR(" | "), false);
        }
        oled_write_ln_P(PSTR("Function"), false);
    } else if(layer_state_is(_NAVI)) {
        if(active == true) {
            oled_write_P(PSTR(" | "), false);
        }
        oled_write_ln_P(PSTR("Navigate"), false);
    } else if(layer_state_is(_NUM)) {
        if(active == true) {
            oled_write_P(PSTR(" | "), false);
        }
        oled_write_ln_P(PSTR("Numeric"), false);
    } else if(layer_state_is(_SYM)) {
        if(active == true) {
            oled_write_P(PSTR(" | "), false);
        }
        oled_write_ln_P(PSTR("Symbol"), false);
    } else {
        oled_write_ln_P(PSTR(""), false);
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
        oled_write_P(PSTR(">>> "), false);
        oled_render_state(get_mods());
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE
