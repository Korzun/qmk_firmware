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
                                          KC_NO, KC_LSFT, LGUI_T(KC_SPC),MO(_SYM),MO(_NUM),MO(_NAVI)
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
                                          KC_NO, KC_LSFT, LGUI_T(KC_SPC),MO(_SYM),MO(_NUM),MO(_NAVI)
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_HASH, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC,                      KC_CIRC, KC_PEQL, KC_PAST, KC_PPLS, KC_QUOT, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,MO(_FUNC), KC_SCLN, KC_LCBR, KC_RCBR, KC_DLR,                      KC_PMNS, KC_PIPE, KC_LBRC, KC_RBRC, LGUI(KC_SPC), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD,   KC_AT, KC_BSLS,  KC_GRV, KC_EXLM,                      KC_UNDS, KC_AMPR,   KC_LT,   KC_GT, KC_QUES, KC_TRNS,
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
      KC_TRNS,   KC_NO, KC_BTN1, KC_BTN2,   KC_NO, LGUI(LSFT(KC_Z)),              KC_END, KC_WH_R, KC_WH_D, KC_WH_U, KC_WH_L, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,      KC_NO,   KC_NO,  KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,   KC_NO, KC_MRWD, KC_MFFD, KC_MPLY,   KC_NO,                    DF(_COLE),   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE,   KC_NO,                    DF(_QWER),   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_NO,RGB_RMOD, RGB_MOD, RGB_TOG,   KC_NO,                        KC_NO,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
void oled_render_icon(const char icon[4][24], uint8_t position) {
    oled_set_cursor(position * 4, 0);
    oled_write_raw_P(icon[0], sizeof(icon[0]));
    oled_set_cursor(position * 4, 1);
    oled_write_raw_P(icon[1], sizeof(icon[1]));
    oled_set_cursor(position * 4, 2);
    oled_write_raw_P(icon[2], sizeof(icon[2]));
    oled_set_cursor(position * 4, 3);
    oled_write_raw_P(icon[3], sizeof(icon[3]));
}

void oled_render_command_icon(uint8_t col) {
    static const char PROGMEM icon[4][24] = {
        {
            0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
            0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0,
            0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x1f, 0x3f, 0x3f, 0x39, 0x31, 0x33,
            0xff, 0xff, 0x30, 0x30, 0x30, 0x30, 0xff, 0xff,
            0x33, 0x31, 0x39, 0x3f, 0x3f, 0x1f, 0x00, 0x00
        },
        {
            0x00, 0x00, 0xf8, 0xfc, 0xfc, 0x9c, 0x8c, 0xcc,
            0xff, 0xff, 0x0c, 0x0c, 0x0c, 0x0c, 0xff, 0xff,
            0xcc, 0x8c, 0x9c, 0xfc, 0xfc, 0xf8, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03,
            0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03,
            0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00
        }
    };
    oled_render_icon(icon, col);
}

void oled_render_colemak_icon(uint8_t col) {
    static const char PROGMEM icon[4][24] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0,
            0x78, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x78,
            0x70, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f,
            0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c,
            0x1e, 0x0f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };
    oled_render_icon(icon, col);
}

void oled_render_control_icon(uint8_t col) {
    static const char PROGMEM icon[4][24] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0,
            0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03,
            0x07, 0x07, 0x0f, 0x1e, 0x3c, 0x78, 0xf0, 0xf0,
            0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0,
            0xe0, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0x0f, 0x0f,
            0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03,
            0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };
    oled_render_icon(icon, col);
}

void oled_render_option_icon(uint8_t col) {
    static const char PROGMEM icon[4][24] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
            0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf8, 0x7c, 0x3f,
            0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc,
            0xfe, 0x1f, 0x0f, 0x03, 0x01, 0x00, 0x00, 0xfe,
            0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
            0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };
    oled_render_icon(icon, col);
}

void oled_render_qwerty_icon(uint8_t col) {
    static const char PROGMEM icon[4][24] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8,
            0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x78,
            0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f,
            0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1e,
            0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };
    oled_render_icon(icon, col);
}

void oled_render_shift_icon(uint8_t col) {
    static const char PROGMEM icon[4][24] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
            0x0f, 0x1e, 0x1e, 0x3c, 0x78, 0xf0, 0xf0, 0xe0,
            0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
            0xf0, 0x78, 0x78, 0x3c, 0x1e, 0x0f, 0x0f, 0x07,
            0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };
    oled_render_icon(icon, col);
}

void oled_clear_icon(uint8_t col) {
    static const char PROGMEM icon[4][24] = {
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        },
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };
    oled_render_icon(icon, col);
}

void oled_render_mods(uint8_t modifiers) {
    // Control
    if(modifiers & MOD_MASK_CTRL) {
        oled_render_control_icon(4);
    } else {
        oled_clear_icon(4);
    }

    // Shift
    if(modifiers & MOD_MASK_SHIFT) {
        oled_render_shift_icon(3);
    } else {
        oled_clear_icon(3);
    }

    // Command
    if(modifiers & MOD_MASK_GUI) {
        oled_render_command_icon(2);
    } else {
        oled_clear_icon(2);
    }

    // Option
    if(modifiers & MOD_MASK_ALT) {
        oled_render_option_icon(1);
    } else {
        oled_clear_icon(1);
    }

    // Base Layer
    if(get_highest_layer(default_layer_state) == _QWER) {
        oled_render_qwerty_icon(0);
    } else {
        oled_render_colemak_icon(0);
    }
}

void oled_render_layer(void) {
    if(layer_state_is(_FUNC)) {
        oled_write_ln_P(PSTR("Function"), false);
    } else if(layer_state_is(_NAVI)) {
        oled_write_ln_P(PSTR("Navigate"), false);
    } else if(layer_state_is(_NUM)) {
        oled_write_ln_P(PSTR("Numeric"), false);
    } else if(layer_state_is(_SYM)) {
        oled_write_ln_P(PSTR("Symbol"), false);
    } else {
        oled_write_ln_P(PSTR("Base"), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer();
    } else {
        oled_render_mods(get_mods());
    }
    return false;
}
#endif // OLED_ENABLE
