/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
 * Copyright 2021 André Santos (@arbsantos)
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
 *
 */

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"
#include "arbsantos.h"

/*
 * ______ _____ ______   _____ _____ _   _ ___________ _____ _      _      ___________
 * | ___ \  __ \| ___ \ /  __ \  _  | \ | |_   _| ___ \  _  | |    | |    |  ___| ___ \
 * | |_/ / |  \/| |_/ / | /  \/ | | |  \| | | | | |_/ / | | | |    | |    | |__ | |_/ /
 * |    /| | __ | ___ \ | |   | | | | . ` | | | |    /| | | | |    | |    |  __||    /
 * | |\ \| |_\ \| |_/ / | \__/\ \_/ / |\  | | | | |\ \\ \_/ / |____| |____| |___| |\ \
 * \_| \_|\____/\____/   \____/\___/\_| \_/ \_/ \_| \_|\___/\_____/\_____/\____/\_| \_|
 */

struct RGB ACCENT = {0xFF, 0x00, 0x00};

int current_color = 16; // white
int color_size = 19; // number of HSV colors on color.h

void set_accent(uint8_t r, uint8_t g, uint8_t b){
  ACCENT.r = r;
  ACCENT.g = g;
  ACCENT.b = b;
}

void set_current_color(int new_color){
  current_color = new_color;
}

void update_leds(void){
  switch (current_color){
    case 0:
      rgb_matrix_sethsv(HSV_AZURE);
      break;

    case 1:
      rgb_matrix_sethsv(HSV_BLUE);
      break;

    case 2:
      rgb_matrix_sethsv(HSV_CHARTREUSE);
      break;

    case 3:
      rgb_matrix_sethsv(HSV_CORAL);
      break;

    case 4:
      rgb_matrix_sethsv(HSV_CYAN);
      break;

    case 5:
      rgb_matrix_sethsv(HSV_GOLD);
      break;

    case 6:
      rgb_matrix_sethsv(HSV_GOLDENROD);
      break;

    case 7:
      rgb_matrix_sethsv(HSV_GREEN);
      break;

    case 8:
      rgb_matrix_sethsv(HSV_MAGENTA);
      break;

    case 9:
      rgb_matrix_sethsv(HSV_ORANGE);
      break;

    case 10:
      rgb_matrix_sethsv(HSV_PINK);
      break;

    case 11:
      rgb_matrix_sethsv(HSV_PURPLE);
      break;

    case 12:
      rgb_matrix_sethsv(HSV_RED);
      break;

    case 13:
      rgb_matrix_sethsv(HSV_SPRINGGREEN);
      break;

    case 14:
      rgb_matrix_sethsv(HSV_TEAL);
      break;

    case 15:
      rgb_matrix_sethsv(HSV_TURQUOISE);
      break;

    case 16:
      rgb_matrix_sethsv(HSV_WHITE);
      break;

    case 17:
      rgb_matrix_sethsv(HSV_YELLOW);
      break;

    case 18:
      rgb_matrix_sethsv(HSV_OFF);
      break;

    default:
      break;
  }
}

void increase_color(void){
  if(current_color == (color_size - 1))
    current_color = 0;
  else
    current_color++;
}

void decrease_color(void){
  if(current_color == 0)
    current_color = (color_size - 1);
  else
    current_color--;
}

void update_led_with_accent_color(int led){
  rgb_matrix_set_color(led, ACCENT.r, ACCENT.g, ACCENT.b);
}
// end rgb controller

/*
 * ___  ___
 * |  \/  |
 * | .  . | __ _  ___ _ __ ___  ___
 * | |\/| |/ _` |/ __| '__/ _ \/ __|
 * | |  | | (_| | (__| | | (_) \__ \
 * \_|  |_/\__,_|\___|_|  \___/|___/
 */

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
  switch(id) {
    case ACCENT_C:
      if (record->event.pressed) {
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          register_code(KC_C);
          unregister_code(KC_C);
          return false;
      }
      break;

    case NXT_COLOR:
      if (record->event.pressed) {
        increase_color();
        update_leds();
        return false;
      }
      break;

    case PRV_COLOR:
      if (record->event.pressed) {
        decrease_color();
        update_leds();
        return false;
      }
      break;

    case WHITE:
      if (record->event.pressed) {
        set_current_color(16);
        update_leds();
        set_accent(RGB_RED);
        return false;
      }
      break;

    case RED:
      if (record->event.pressed) {
        set_current_color(12);
        update_leds();
        set_accent(RGB_WHITE);
        return false;
      }
      break;

    case BLUE:
      if (record->event.pressed) {
        set_current_color(1);
        update_leds();
        return false;
      }
      break;

    case GREEN:
      if (record->event.pressed) {
        set_current_color(7);
        update_leds();
        return false;
      }
      break;

    case ORANGE:
      if (record->event.pressed) {
        set_current_color(9);
        update_leds();
        return false;
      }
      break;

    case TURQUOISE:
      if (record->event.pressed) {
        set_current_color(15);
        update_leds();
        return false;
      }
      break;

    case PURPLE:
      if (record->event.pressed) {
        set_current_color(11);
        update_leds();
        return false;
      }
      break;

    case YELLOW:
      if (record->event.pressed) {
        set_current_color(17);
        update_leds();
        return false;
      }
      break;

    case CORAL:
      if (record->event.pressed) {
        set_current_color(3);
        update_leds();
        return false;
      }
      break;

    case AZURE:
      if (record->event.pressed) {
        set_current_color(0);
        update_leds();
        return false;
      }
      break;
  }
  return MACRO_NONE;
};
// end macros

/*
 *  _                             _
 * | |                           | |
 * | |     __ _ _   _  ___  _   _| |_
 * | |    / _` | | | |/ _ \| | | | __|
 * | |___| (_| | |_| | (_) | |_| | |_
 * \_____/\__,_|\__, |\___/ \__,_|\__|
 *               __/ |
 *              |___/
 */
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,        KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,        KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC,                         KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, KC_NUHS,       KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,                KC_RSFT, KC_UP,   KC_HOME,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             MO(_FN1), KC_RGUI, MO(_RGB_OPTS), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN1] = LAYOUT(
        _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, _______, _______, _______, _______, _______, _______, _______, _______,       _______,              _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       RESET,                _______,
        _______, _______, _______, KC_MYCM, _______,     _______, _______, _______, _______, _______, _______, _______, _______,                         _______,
        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,       _______,          _______,
        _______, _______, _______, _______, M(ACCENT_C), _______, _______, NK_TOGG, _______, _______, _______, _______,                _______, RGB_MOD, KC_END,
        _______, _______, _______,                                _______,                            KC_TRNS, _______, KC_TRNS,       RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [_RGB_OPTS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,
        _______, M(WHITE), M(RED), M(BLUE), M(GREEN), M(ORANGE), M(TURQUOISE), M(PURPLE), M(YELLOW), M(CORAL), M(AZURE), _______, _______, RESET, _______,
        _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_R, _______, _______, _______, RGB_M_SW, RGB_M_SN, RGB_M_P, _______, _______,                    _______,
        _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, RGB_M_G, _______, _______, RGB_M_K, _______, _______, _______, _______, _______,             _______,
        _______, RGB_M_T, _______, RGB_M_X, _______, _______, RGB_M_B, _______, _______, M(PRV_COLOR), M(NXT_COLOR), _______, _______,   RGB_MOD, KC_END,
        _______, _______, _______,                            RGB_TOG,                            KC_TRNS , _______, KC_TRNS , RGB_SPD, RGB_RMOD, RGB_SPI
    ),

};
// clang-format on

/*
 *  _____                    _
 * |  ___|                  | |
 * | |__ _ __   ___ ___   __| | ___ _ __
 * |  __| '_ \ / __/ _ \ / _` |/ _ \ '__|
 * | |__| | | | (_| (_) | (_| |  __/ |
 * \____/_| |_|\___\___/ \__,_|\___|_|
 */

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif // ENCODER_ENABLE

/*
 *  _                                 _ _     _
 * | |                               | (_)   | |
 * | |     __ _ _   _  ___ _ __ ___  | |_ ___| |_ ___ _ __   ___ _ __
 * | |    / _` | | | |/ _ \ '__/ __| | | / __| __/ _ \ '_ \ / _ \ '__|
 * | |___| (_| | |_| |  __/ |  \__ \ | | \__ \ ||  __/ | | |  __/ |
 * \_____/\__,_|\__, |\___|_|  |___/ |_|_|___/\__\___|_| |_|\___|_|
 */

#ifdef RGB_MATRIX_ENABLE
  // Capslock, Scroll lock and Numlock  indicator on Left side lights.
  void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)){

      case _BASE:
        // highlight caps led if caps lock
        if (host_keyboard_led_state().caps_lock) {
          update_led_with_accent_color(LED_CAPS);
        }
        break;

      case _FN1:
        // highlight the function key
        for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_FN); i++) {
          update_led_with_accent_color(LED_LIST_FN[i]);
        }
        break;

      default:
        break;

    }
  }
#endif // RGB_MATRIX_ENABLE
