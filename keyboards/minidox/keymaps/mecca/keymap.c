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


/* This makes it easier for fast typists to use dual-function keys. 
   Without this, if you let go of a held key inside the tapping term, it won't register.
*/ 
#define PERMISSIVE_HOLD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _DVORAK
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | Shift| SYM  |    |OTH   | Bkspc| Del  |
 *    Hold key      `-ESC---- Tab | Space|    |Enter |------+------.
 *    for Esc or Space            |      |    |      |
 *    or Bkspc or Tab             `------'    `------'
 */
[_DVORAK] = KEYMAP( \
  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    \
  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \

 CTL_T(KC_ESC), SFT_T(KC_TAB),LT(_OTHERS, KC_SPACE), \
                                                   	   LT(_SYMBOLS, KC_ENT), KC_BSPACE, ALT_T(KC_DEL)                 \
),

/* _SYMBOLS
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  !   |  @   |  {   |   }  |  - _ |           |  / ?|   7  |   8  |   9  |   *  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   #  |  $   |  (   |   )  |  -   |           |  \ | |   4  |   5  |   6  |  = + |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  %   |  ^   |  [   |  ]   |      |           |      |   1  |   2  |   3  |  `   |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYMBOLS] = KEYMAP( \
  KC_EXLM,  KC_AT,  KC_LCBR, KC_RCBR,   KC_MINS,      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_ASTR,    \
  KC_HASH,  KC_DLR,   KC_LPRN, KC_RPRN, KC_MINS,      KC_BSLS,    KC_4,    KC_5,    KC_6, KC_EQUAL, \
  KC_PERC,  KC_CIRC,  KC_LBRC, KC_RBRC, _______,         KC_0,    KC_1,    KC_2,    KC_3, KC_GRV, \
                      _______, _______, _______,      _______, _______, _______                    \
),

/* _OTHERS
 *
 *      ,----------------------------------. ,----------------------------------.      
 *      | PGDN | END  |  UP  | HOME | PGUP ||  F1  |  F2  |  F3  |  F4  |  F5  |      
 *      |------+------+------+------+------| |------+------+------+------+------|      
 *      |      |  LEFT| DOWN | RIGHT|   ~  | |  F6  |  F7  |  F8  |  F9  |  F10 |      
 *      |------+------+------+------+------| |------+------+------+------+------|      
 *      |      |      |      |      |      | |  F11 | F12  |      |      | Caps |      
 *      `----------------------------------' `----------------------------------'      
 *                   ,--------------------.   ,------,-------------. 
 *                   |      | LOWER|      |   |      | RAISE|      | 
 *                   `-------------|      |   |      |------+------. 
 *                                 |      |   |      |               
 *                                 `------'   `------'               
 */
[_OTHERS] = KEYMAP( \
  KC_PGDN, KC_END,   KC_UP,   KC_HOME, KC_PGUP,       KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5, \
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RCBR,       KC_F6,     KC_F7,   KC_F8,   KC_F9,  KC_F10, \
  _______, _______, _______,  KC_PIPE,  KC_DQT,      KC_F11,   KC_F12, _______, _______, KC_CAPS,\
                    _______, _______, _______ ,     _______, _______, _______\
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
[_UNUSED] =  KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_UP,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, RGB_SAI, RGB_SAD,      _______, KC_LEFT, KC_DOWN, KC_RGHT, CALTDEL, \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,      RGB_VAI, RGB_VAD, KC_F8, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
)
};
