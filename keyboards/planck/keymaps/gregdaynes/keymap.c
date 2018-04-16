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


#define NAV MO(1)
#define NUM MO(2)
#define FN  MO(3)
#define SPC MT(MOD_LSFT, KC_SPC)

#define CTRLA LCTL(KC_A)
#define CTRLZ LCTL(KC_Z)
#define CHNKA KC_LALT
#define CHNKS LALT(KC_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  {   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  }   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |  NAV | Num  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC},
  {FN,      KC_LCTL, KC_LALT, KC_LGUI, NAV,     NUM,     _______, SPC,     _______, _______, _______, _______}
},

/*
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |      |      |  Up  |      |      |  *   |   =  |  7   |  8   |  9   |  `   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | TMUX | LeFt | Down |Right | BSPC | Del  |   _  |  4   |  5   |  6   |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  (   |  BG  |      | SAlt | Alt  |      |      |   -  |  1   |  2   |  3   |  )   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  0   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[1] = {
  {KC_TILD, _______, _______, KC_UP,   _______, _______, KC_ASTR, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_GRV},
  {_______, CTRLA,  KC_LEFT,  KC_DOWN, KC_RGHT, KC_BSPC, KC_DEL,  KC_UNDS, KC_4,    KC_5,    KC_6,    KC_QUOT},
  {KC_LPRN, CTRLZ,  _______,  _______, _______, _______, _______, KC_MINS, KC_1,    KC_2,    KC_3,    KC_RPRN},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |      |      |      |      |      |  *   |  =   |   &  |  *   |      |  `   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      | BSPC | Del  |  _   |   $  |  %   |  ^   |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  (   |      |      |      |      |      |      |  -   |   !  |  @   |  #   |  )   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = {
  {KC_TILD, _______, _______, _______, _______, _______, KC_ASTR, KC_EQL,  KC_AMPR, KC_ASTR, _______, KC_GRV},
  {_______, _______, _______, _______, _______, KC_BSPC, KC_DEL,  KC_UNDS,  KC_DLR,  KC_PERC, KC_CIRC, KC_QUOT},
  {KC_LPRN, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EXLM, KC_AT,   KC_HASH, KC_RPRN},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
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
  {_______, RESET,   _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12},
  {_______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MFFD, KC_VOLD, KC_VOLU, KC_MPLY}
}


};
