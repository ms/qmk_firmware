/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MOVE,  // movement
    MDIA,  // media keys
    UNICODE,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    LARROW,
    TSPACE,
    HSPACE,
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [LARROW] = 0x2192,
    [TSPACE] = 0x2009,
    [HSPACE] = 0x200A,

};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,               KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_NO,           KC_NO,  KC_6,     KC_7,    KC_8,      KC_9,    KC_0,      KC_NO,
        KC_LGUI,              KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,    KC_NO,           KC_NO,  KC_Y,     KC_U,    KC_I,      KC_O,    KC_P,      KC_GRV,
        MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,       KC_G,    KC_NO,           KC_NO,  KC_H,     KC_J,    KC_K,      KC_L,    KC_SCLN,   KC_QUOT,
        KC_LALT,              KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,                             KC_N,     KC_M,    KC_COMM,   KC_DOT,  KC_SLSH,   KC_MINUS,
        KC_NO,                KC_NO,   KC_NO,   KC_NO,   MO(UNICODE),KC_NO,                            KC_ENTER, MO(SYMB),MO(MOVE),  KC_NO,   KC_NO,     KC_NO,
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_TAB,    KC_NO,   KC_LSFT
    ),

    [SYMB] = LAYOUT_moonlander(
        RESET,   KC_F1,    KC_F2,        KC_F3,   KC_F4,     KC_F5,        _______,           _______, KC_F6,    KC_F7,   KC_F8,   KC_F9,         KC_F10,  KC_F11,
        _______, KC_NO,    KC_PERC,      KC_AT,   KC_TILDE,  KC_NO,        _______,           _______, KC_EQUAL, KC_LBRC, KC_RBRC, KC_UNDS,       KC_NO,   KC_F12,
        _______, KC_NO,    KC_EXLM,      KC_HASH, KC_ASTR,   KC_NO,        _______,           _______, KC_COLON, KC_LPRN, KC_RPRN, KC_QUESTION,   KC_PLUS, KC_NO,
        _______, KC_SLASH, KC_BACKSLASH, KC_CIRC, KC_DOLLAR, KC_AMPERSAND,                             KC_PIPE, KC_LCBR, KC_RCBR, KC_LT,          KC_GT,   KC_NO,
        _______, _______,  _______,      _______, _______,   _______,                                  _______, _______, _______, _______,        _______, KC_NO,
                                            _______, _______, _______,           _______,_______, _______
    ),

    [MOVE] = LAYOUT_moonlander(
        _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,           _______, KC_NO,   KC_NO,    KC_NO,    KC_NO,     KC_NO,   KC_NO,
        _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  _______,            _______, KC_NO,   KC_PGDN,  KC_PGUP,  KC_NO,     KC_NO,   KC_NO,
        _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  _______,            _______, KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT,  KC_NO,   KC_NO,
        _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_NO,    KC_NO,    KC_NO,     KC_NO,   KC_NO,
        _______,    _______, _______, _______, _______, _______,                             _______, _______,  _______,  _______,   _______, KC_NO,
                                               _______, _______,_______,              _______,_______, _______
    ),

    [UNICODE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, X(LARROW), _______, _______,           _______, _______, X(IRONY), _______, _______, _______, _______,
        _______, _______, _______, X(TSPACE), X(HSPACE), _______, _______,           _______, _______, X(SNEK),  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          _______,  _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
  ),
    /*


    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
  rgb_matrix_set_flags(LED_FLAG_NONE);
}

