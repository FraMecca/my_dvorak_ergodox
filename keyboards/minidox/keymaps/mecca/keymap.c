#include "minidox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK  0
#define _SYMBOLS 1
#define _OTHERS  2
#define _UNUSED  16

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines CTRL ALT CANC
#define CALTDEL LCTL(LALT(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | Shift| OTH  |    |SYM   | ENTER| Del  |
 *    Hold key      `-ESC----Space| Bkspc|    |Tab   |------+------.
 *    for Esc or Space            |      |    |      |
 *    or Bkspc or Tab             `------'    `------'
 */
[_QWERTY] = KEYMAP( \
  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    \
  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
  \
 CTL_T(KC_ESC), SFT_T(KC_SPC),LT(_OTHERS, KC_BSPACE),  
 \                                                 LT(_SYMBOLS, KC_TAB), KC_ENT, KC_DEL                 \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  !   |  @   |  {   |   }  |  - _ |           |   0  |   7  |   8  |   9  |   *  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   #  |  $   |  (   |   )  |      |           |  \ | |   4  |   5  |   6  |  = + |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  %   |  ^   |  [   |  ]   |      |           |      |   1  |   2  |   3  |   / ?|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = KEYMAP( \
  KC_EXLM,  KC_AT,  KC_LCBR, KC_RCBR,   KC_MINS,         KC_0,    KC_7,    KC_8,    KC_9, KC_ASTR,    \
  KC_HASH,  KC_DLR,   KC_LPRN, KC_RPRN, _______,      KC_BSLS,    KC_4,    KC_5,    KC_4, KC_PLUS, \
  KC_PERC,  KC_CIRC,  KC_LBRC, KC_RBRC, _______,      _______,    KC_1,    KC_2,    KC_3, KC_SLSH, \
                      _______, _______, _______,      _______, _______, _______                    \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  PGUP| HOME |  UP  | END  | PGDN  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |           |      |  LEFT| DOWN | RIGHT|   ~  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 | F12  |      |      | Caps |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = KEYMAP( \
  KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_PGUP, KC_HOME, KC_UP, KC_END,     KC_PGDN, \
  KC_F6,     KC_F7,   KC_F8,   KC_F9,  KC_F10,      _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RCBR, \
  KC_F11,   KC_F12, _______, _______, KC_CAPS,      _______, _______, _______, KC_PIPE,  KC_DQT, \
                    _______, _______, _______,      _______, _______, _______                    \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  Up  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |RGBSAI|RGBSAD|           |      | Left | Down |Right |caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|RGBTOG|RGBMOD|RGBHUI|RGBHUD|           |RGBVAI|RGBVAD|  F8  |Taskmg|      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_UP,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, RGB_SAI, RGB_SAD,      _______, KC_LEFT, KC_DOWN, KC_RGHT, CALTDEL, \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,      RGB_VAI, RGB_VAD, KC_F8, TSKMGR,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
)
};
