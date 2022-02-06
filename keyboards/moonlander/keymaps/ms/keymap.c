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
    UNICODE,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

enum unicode_names {
    EACUTE,
    EACUTE_CAP,
    EGRAVE,
    EGRAVE_CAP,
    EHAT,
    EHAT_CAP,
    AGRAVE,
    AGRAVE_CAP,
    AHAT,
    AHAT_CAP,
    IHAT,
    IHAT_CAP,
    IDIA,
    IDIA_CAP,
    UHAT,
    UHAT_CAP,
    UDIA,
    UDIA_CAP,
    UACUTE,
    UACUTE_CAP,
    OHAT,
    OHAT_CAP,
    OELIG,
    OELIG_CAP,
    CCED,
    CCED_CAP,
    LQUOTE,
    LSQUOTE,
    LQUOTE_FR,
    RQUOTE,
    RSQUOTE,
    RQUOTE_FR,
    PRIME,
    DPRIME,
    BANG,
    IRONY,
    SNEK,
    LARROW,
    LDARROW,
    RARROW,
    RDARROW,
    UARROW,
    DARROW,
    TSPACE,
    NNBSPACE,
    HSPACE,
    EMDASH,
    ENDASH,
    ELLIP,
    MUL,
    NEQ,
    APPROX,
    ONEC,
    TWOC,
    THREEC,
    FOURC,
    FIVEC,
    SIXC,
    SEVENC,
    EIGHTC,
    NINEC,
    TENC,

};

const uint32_t PROGMEM unicode_map[] = {
    [EACUTE] = 0x00E9,
    [EACUTE_CAP] = 0x00C9,
    [EGRAVE] = 0x00E8,
    [EGRAVE_CAP] = 0x00C8,
    [EHAT] = 0x00EA,
    [EHAT_CAP] = 0x00CA,
    [AGRAVE] = 0x00E0,
    [AGRAVE_CAP] = 0x00C0,
    [AHAT] = 0x00E2,
    [AHAT_CAP] = 0x00C2,
    [IHAT] = 0x00EE,
    [IHAT_CAP] = 0x00CE,
    [IDIA] = 0x00EF,
    [IDIA_CAP] = 0x00CF,
    [UHAT] = 0x00FB,
    [UHAT_CAP] = 0x00DB,
    [UDIA] = 0x00FC,
    [UDIA_CAP] = 0x00DC,
    [UACUTE] = 0x00F9,
    [UACUTE_CAP] = 0x00D9,
    [OHAT] = 0x00F4,
    [OHAT_CAP] = 0x00D4,
    [OELIG_CAP] = 0x0152,
    [OELIG] = 0x0153,
    [CCED] = 0x00E7,
    [CCED_CAP] = 0x00C7,
    [LQUOTE] = 0x201C,
    [LSQUOTE] = 0x2018,
    [LQUOTE_FR] = 0x00AB,
    [RQUOTE] = 0x201D,
    [RSQUOTE] = 0x2019,
    [RQUOTE_FR] = 0x00BB,
    [PRIME] = 0x2032,
    [DPRIME] = 0x2033,
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [LARROW] = 0x2190,
    [LDARROW] = 0x21D0,
    [UARROW] = 0x2191,
    [RARROW] = 0x2192,
    [RDARROW] = 0x21D2,
    [DARROW] = 0x2193,
    [TSPACE] = 0x2009,
    [NNBSPACE] = 0x202F,
    [HSPACE] = 0x200A,
    [EMDASH] = 0x2014,
    [ENDASH] = 0x2013,
    [ELLIP] = 0x2026,
    [MUL] = 0x00D7,
    [NEQ] = 0x2260,
    [APPROX] = 0x2248,
    [ONEC] = 0x2460,
    [TWOC] = 0x2461,
    [THREEC] = 0x2462,
    [FOURC] = 0x2463,
    [FIVEC] = 0x2464,
    [SIXC] = 0x2465,
    [SEVENC] = 0x2466,
    [EIGHTC] = 0x2467,
    [NINEC] = 0x2468,
    [TENC] = 0x2469,

};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_NO,                          KC_NO,     KC_6,     KC_7,     KC_8,      KC_9,    KC_0,      KC_NO,
        KC_LGUI,        KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,    KC_NO,                     KC_NO,           KC_Y,     KC_U,     KC_I,      KC_O,    KC_P,      KC_GRV,
        KC_LCTL,        KC_A,    KC_S,    KC_D,    KC_F,       KC_G,    KC_NO,           KC_NO, KC_H,     KC_J,     KC_K,      KC_L,    KC_SCLN,   KC_QUOT,
        KC_LALT,        KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,                                                          KC_N,     KC_M,     KC_COMM,   KC_DOT,  KC_SLSH,   KC_MINUS,
        KC_NO,          UC_MOD,  KC_NO,   KC_NO,   MO(UNICODE),   KC_TAB,                                                 KC_ENTER,     MO(SYMB), MO(MOVE),  KC_NO,   KC_NO,     KC_NO,
                                          KC_LSFT,  KC_BSPC, KC_BSPC,                                                          KC_NO,    KC_ESC,   KC_SPC
    ),

    [SYMB] = LAYOUT_moonlander(
        RESET,   KC_F1,    KC_F2,        KC_F3,   KC_F4,     KC_F5,        _______,           _______, KC_F6,    KC_F7,   KC_F8,   KC_F9,         KC_F10,  KC_F11,
        _______, KC_NO,    KC_PERC,      KC_AT,   KC_TILDE,  KC_NO,        _______,           _______, KC_EQUAL, KC_LBRC, KC_RBRC, KC_NO,         KC_NO,   KC_F12,
        _______, KC_NO,    KC_EXLM,      KC_HASH, KC_ASTR,   KC_NO,        _______,           _______, KC_COLON, KC_LPRN, KC_RPRN, KC_QUESTION,   KC_PLUS, KC_NO,
        _______, KC_SLASH, KC_BACKSLASH, KC_CIRC, KC_DOLLAR, KC_AMPERSAND,                             KC_PIPE, KC_LCBR, KC_RCBR, KC_LT,          KC_GT,   KC_NO,
        _______, _______,  _______,      _______, _______,   _______,                                  _______, _______, _______, _______,        _______, KC_NO,
                                            _______, _______, _______,           _______,_______, _______
    ),

    [MOVE] = LAYOUT_moonlander(
        _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,           _______, KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,   KC_NO,
        _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  _______,            _______, KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,    KC_NO,   KC_NO,
        _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  _______,            _______, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_NO,   KC_NO,
        _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,   KC_NO,
        _______,    _______, _______, _______, _______, _______,                             _______, _______,  _______,  _______,   _______, KC_NO,
                                               _______, _______,_______,              _______,_______, _______
    ),

    [UNICODE] = LAYOUT_moonlander(
        _______, X(ONEC),   X(TWOC),            X(THREEC),           X(FOURC),             X(FIVEC),           _______,      _______, X(SIXC),           X(SEVENC),             X(EIGHTC),             X(NINEC),              X(TENC),               _______,
        _______, X(MUL),    XP(LARROW,LDARROW), X(UARROW),           X(DARROW),            XP(RARROW,RDARROW), _______,      _______, XP(OHAT,OHAT_CAP), XP(IHAT,IHAT_CAP),     XP(UHAT, UHAT_CAP),    XP(AHAT,AHAT_CAP),     X(ELLIP),              XP(PRIME,DPRIME),
        _______, X(NEQ),    X(EMDASH),          XP(NNBSPACE,TSPACE), X(HSPACE),            X(ENDASH),          _______,      _______, XP(EHAT,EHAT_CAP), XP(EACUTE,EACUTE_CAP), XP(EGRAVE,EGRAVE_CAP), XP(AGRAVE,AGRAVE_CAP), XP(UACUTE,UACUTE_CAP), XP(RSQUOTE, LSQUOTE),
        _______, X(APPROX), KC_NO,              XP(LQUOTE,LQUOTE_FR),XP(RQUOTE, RQUOTE_FR),_______,                                  _______,           XP(IDIA,IDIA_CAP),     XP(UDIA,UDIA_CAP),     XP(CCED,CCED_CAP),     XP(OELIG,OELIG_CAP),   _______,
        _______, _______, _______,  _______, _______,         _______,            _______,          _______,  _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
  ),
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

