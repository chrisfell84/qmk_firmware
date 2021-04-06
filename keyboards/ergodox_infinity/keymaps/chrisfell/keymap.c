#include QMK_KEYBOARD_H
#include "version.h"

enum custom_layers {
    BASE,   // default layer
    SYMB,   // symbols
    MDIA,   // media keys
};


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |  Bksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   "  |   ,  |   .  |   P  |   Y  |  L1  |           |  L1  |   F  |   G  |   C  |   R  |   L  |  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   /    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | Shift  |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt  | GUI  | Brite| L1   |                                       |  L2  | Left | Down |  Up  |Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| Enter  |Space |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,    KC_3,    KC_4,    KC_5,   KC_LEFT,
        KC_TAB,         KC_QUOT,      KC_COMM, KC_DOT,  KC_P,    KC_Y,   MO(SYMB),
        KC_ESC,         KC_A,         KC_O,    KC_E,    KC_U,    KC_I,
        KC_LSFT,        KC_SCLN,      KC_Q,    KC_J,    KC_K,    KC_X,   ALL_T(KC_NO),
        KC_LCTL,        KC_LALT,      KC_LGUI, BACKLIT, MO(SYMB),
                                                           ALT_T(KC_APP),KC_LGUI,
                                                                         KC_HOME,
                                                        KC_SPC,  KC_BSPC,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,     KC_8,    KC_9,    KC_0,  KC_BSPC,
             MO(SYMB),    KC_F,   KC_G,     KC_C,    KC_R,    KC_L,  KC_BSPC,
                          KC_D,   KC_H,     KC_T,    KC_N,    KC_S,  KC_SLSH,
             MEH_T(KC_NO),KC_B,   KC_M,     KC_W,    KC_V,    KC_Z,  KC_ENT,
                                  MO(MDIA), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
             KC_LALT,     CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,     KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |      ~  |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |  Bksp  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |      ~  |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |  Del   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Del   |   F1 |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   _  |   +  |   {  |   }  |   |    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   F7 |  F8  |  F9  |  F10 |  F11 |      |           |      |  F12 |      |      | End  | Home |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |EEP_RST|      |      |      |      |                                       |      | Next | Vol- | Vol+ | Play |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Brit+|       | Hue+ |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | Brit-|       | Hue- |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, 
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
       KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   
       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
       EEP_RST, _______, _______, _______, _______, 
                                                    RGB_MOD, _______,
                                                             RGB_VAI,
                                           _______, _______, RGB_VAD,
       // right hand
       _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
       _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
                KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
       _______, KC_F12,  _______, _______, KC_HOME, KC_END,  _______,
                         _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
       RGB_TOG, _______,
       RGB_HUI,
       RGB_HUD, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |     `  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  Bksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |     `  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Del  |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   -  |   =  |   [  |   ]  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |  F10 |  F11 |      |           |      |  F12 |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | Home | PgDn | PgUp | End  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
    // left hand
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
       KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
       _______, _______, _______, _______, _______, 
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
    // right hand
       _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
       _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
                KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
       _______, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
                         _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
       _______, _______,
       _______,
       _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef __AVR__
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef __AVR__
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
