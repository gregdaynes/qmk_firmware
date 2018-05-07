/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define FN MO(3)
#define SPCLNAV LT(1, KC_SPC)
#define SPCRNAV LT(2, KC_SPC)
#define LSPA SFT_T(KC_LBRC)
#define RSPA SFT_T(KC_RBRC)
#define CTLA LCTL(KC_A)
#define CTLZ LCTL(KC_Z)
#define CTLC LCTL(KC_C)
#define GUIX LGUI(KC_X)
#define GUIV LGUI(KC_V)
#define GUIESC GUI_T(KC_ESC)
#define GUIENT GUI_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------.             ,---------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |             |  Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+             +-----+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |             |  H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+             +-----+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |             |  N  |   M  |   ,  |   .  |   /  |
 * ,------+------+------+------+------+             +-----+------+------+------+------'
 *        | Ctrl | Cmd  |SpcNav|  SLP |             | SRP |SpcNav| Cmd  |  Alt |
 *        `---------------------------'             `--------------------------'
 */
[0] = {
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P   },
  {KC_A,    KC_S,    KC_D,    KC_F,    KC_G, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
  {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
  {_______, KC_LCTL, GUIESC,  SPCLNAV, LSPA, _______, _______, RSPA,    SPCRNAV, GUIENT, KC_RALT, KC_NO  }
},

/* Nav
 * ,----------------------------------.             ,---------------------------------.
 * |  `~  |   ^  |  UP  |  $   |  TAB |             | =+  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+             +-----+------+------+------+------|
 * | ESC  | LEFT | DOWN |RIGHT | Bksp |             | -_  |   4  |   5  |   6  |  '"  |
 * |------+------+------+------+------+             +-----+------+------+------+------|
 * | CTLZ | CmdX | CTLC | CmdV |  Ent |             |  *  |   1  |   2  |   3  |  \|  |
 * ,------+------+------+------+------+             +-----+------+------+------+------'
 *        |      |      |SpcNav|      |             |     |SpcNav|      |      |
 *        `---------------------------'             `--------------------------'
 */
[1] = {
  {KC_GRV,  KC_CIRC, KC_UP,   KC_DLR,  KC_TAB,  _______, _______, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_0},
  {CTLA,    KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______, _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_QUOT},
  {CTLZ,    GUIX,    CTLC,    GUIV,    KC_ENT,  _______, _______, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_BSLS},
  {_______, _______, _______, SPCLNAV, _______, _______, _______, _______, FN,      _______, _______, _______}
},

[2] = {
  {KC_GRV,  KC_CIRC, KC_UP,   KC_DLR,  KC_TAB,  _______, _______, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_0},
  {KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______, _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_QUOT},
  {CTLZ,    GUIX,    CTLC,    GUIV,    KC_ENT,  _______, _______, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_BSLS},
  {_______, _______, _______, FN,      _______, _______, _______, _______, SPCRNAV, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  F4  |  F5  |  F6  | F11  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  F1  |  F2  |  F3  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[3] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10 },
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11 },
  {KC_MPRV, KC_MFFD, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12 },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};
