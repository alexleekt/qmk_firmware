#include QMK_KEYBOARD_H
#include "print.h"

#define CTL_ESC LCTL_T(KC_ESC)      // Tap for ESC, hold for CTRL
#define MD_LOCK LCTL(LGUI(KC_Q))    // MacOS lock screen shortcut
#define MO_FUNC MO(_FUNCTION)       // Hold for function layer
#define LT_MKBSL LT(_MOUSEKEYS, KC_BSLS) // backslash when tapped, mouse keys Layer when held
#define TG_MKEYS TG(_MOUSEKEYS)     // Toggles mouse keys mode

enum custom_keycodes {
    MD_BOOT = SAFE_RANGE,   // Restart into bootloader after hold timeout
    HK_COSL,                // Clear held-down keys
    QWERTY,                 // Switch to QWERTY layout
    COLEMAK,                // Switch to Colemak Mod-DH layout
    MOUSE,                  // Switch to Mouse Keys layout
    KC_CCCV,                // Single tap copy and paste
    KC_HMEND,               // KC home-end
};

enum custom_layers {
    _QWERTY = 0,
    _COLEMAK,
    _MOUSEKEYS,
    _FUNCTION,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬────────────┬───────┐
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * │   `   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │   -   │   =   │ BackSpace  │  Del  │
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * ├───────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬─────────┼───────┤
     * │          │       │       │       │       │       │       │       │       │       │       │       │       │         │       │
     * │    Tab   │   Q   │   W   │   E   │   R   │   T   │   Y   │   U   │   I   │   O   │   P   │   [   │   ]   │    \    │ Home  │
     * │          │       │       │       │       │       │       │       │       │       │       │       │       │         │  End  │
     * ├──────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─────────┼───────┤
     * │            │       │       │       │       │       │       │       │       │       │       │       │               │       │
     * │  Ctrl/Esc  │   A   │   S   │   D   │   F   │   G   │   H   │   J   │   K   │   L   │   ;   │   '   │    Return     │ PgUp  │
     * │            │       │       │       │       │       │       │       │       │       │       │       │               │       │
     * ├────────────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴───────┬───────┼───────┤
     * │               │       │       │       │       │       │       │       │       │       │       │            │       │       │
     * │     Shift     │   Z   │   X   │   C   │   V   │   B   │   N   │   M   │   ,   │   .   │   /   │   Shift    │  Up   │ PgDn  │
     * │               │       │       │       │       │       │       │       │       │       │       │            │       │       │
     * ├─────────┬─────┴───┬───┴─────┬─┴───────┴───────┴───────┴───────┴───────┴─────┬─┴───────┼───────┴─┬──┬───────┼───────┼───────┤
     * │         │         │         │                                               │ Toggle  │         │▒▒│       │       │       │
     * │  Ctrl   │   GUI   │   Alt   │                     Space                     │  Mouse  │  Func   │▒▒│ Left  │ Down  │ Right │
     * │         │         │         │                                               │  Layer  │         │▒▒│       │       │       │
     * └─────────┴─────────┴─────────┴───────────────────────────────────────────────┴─────────┴─────────┴──┴───────┴───────┴───────┘
     */
    [_QWERTY] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,LT_MKBSL,KC_HMEND,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             TG_MKEYS,MO_FUNC, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_COLEMAK] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,LT_MKBSL,KC_HMEND,
        CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_B,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             TG_MKEYS,MO_FUNC, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Function layer
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬────────────┬───────┐
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * │  Esc  │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │    Del     │ Mute  │
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * ├───────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬─────────┼───────┤
     * │          │       │       │       │       │       │       │       │       │       │       │       │       │         │       │
     * │          │QWERTY │       │       │       │       │       │       │       │       │ PrtSc │ ScrLk │ Pause │         │  End  │
     * │          │       │       │       │       │       │       │       │       │       │       │       │       │         │       │
     * ├──────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─────────┼───────┤
     * │            │       │       │       │       │       │       │       │       │ (Mac) │       │       │               │       │
     * │  CapsLock  │       │       │       │       │       │       │       │       │ Lock  │       │       │  Media Play   │ Vol+  │
     * │            │       │       │       │       │       │       │       │       │       │       │       │               │       │
     * ├────────────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴───────┬───────┼───────┤
     * │               │       │       │       │       │       │       │ Toggle│       │       │       │            │       │       │
     * │               │       │       │COLEMAK│       │Restart│       │ Mouse │       │       │       │            │ PgUp  │ Vol-  │
     * │               │       │       │       │       │       │       │ Layer │       │       │       │            │       │       │
     * ├─────────┬─────┴───┬───┴─────┬─┴───────┴───────┴───────┴───────┴───────┴─────┬─┴───────┼───────┴─┬──┬───────┼───────┼───────┤
     * │         │         │         │                                               │         │         │▒▒│       │       │       │
     * │         │         │         │               Clear modifiers                 │         │         │▒▒│ Home  │ PgDn  │  End  │
     * │         │         │         │                                               │         │         │▒▒│       │       │       │
     * └─────────┴─────────┴─────────┴───────────────────────────────────────────────┴─────────┴─────────┴──┴───────┴───────┴───────┘
     */
    [_FUNCTION] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_AUDIO_MUTE,
        _______,  QWERTY, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, MD_LOCK, _______, _______,          KC_MEDIA_PLAY_PAUSE, KC_VOLU,
        _______, _______, _______, COLEMAK, _______, MD_BOOT, _______,TG_MKEYS, _______, _______, _______, _______,          KC_PGUP, KC_VOLD,
        _______, _______, _______,                            HK_COSL,                            _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

    /* Mouse Layer, toggle with right alt, or toggle with FN-m, or when holding \
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬────────────┬───────┐
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * ├───────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬─────────┼───────┤
     * │          │ MOUSE │ MOUSE │ MOUSE │ MOUSE │       │       │       │       │       │       │ MOUSE │ MOUSE │  MOUSE  │       │
     * │          │ Wheel │       │ Wheel │ Wheel │       │       │       │       │       │       │       │       │  Layer  │       │
     * │          │ Left  │  Up   │ Right │  Up   │       │       │       │       │       │       │ R clk │ L clk │  (hold) │       │
     * ├──────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─────────┼───────┤
     * │    Unset   │ MOUSE │ MOUSE │ MOUSE │ MOUSE │       │       │ MOUSE │ MOUSE │       │       │       │               │       │
     * │    Layer   │       │       │       │ Wheel │       │       │       │       │       │       │       │               │       │
     * │            │ Left  │ Down  │ Right │ Down  │       │       │ L clk │ R clk │       │       │       │               │       │
     * ├────────────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴───────┬───────┼───────┤
     * │               │       │       │       │       │       │       │       │       │       │       │            │       │       │
     * │               │       │       │       │       │       │       │       │       │       │       │            │       │       │
     * │               │       │       │       │       │       │       │       │       │       │       │            │       │       │
     * ├─────────┬─────┴───┬───┴─────┬─┴───────┴───────┴───────┴───────┴───────┴─────┬─┴───────┼───────┴─┬──┬───────┼───────┼───────┤
     * │         │         │  MOUSE  │                                               │         │         │▒▒│       │       │       │
     * │         │         │  R clk  │              MOUSE Left Click                 │         │         │▒▒│       │       │       │
     * │         │         │         │                                               │         │         │▒▒│       │       │       │
     * └─────────┴─────────┴─────────┴───────────────────────────────────────────────┴─────────┴─────────┴──┴───────┴───────┴───────┘
    */
    [_MOUSEKEYS] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______, _______, _______, _______, _______, _______, KC_BTN2, KC_BTN1, _______, _______,
       TG_MKEYS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, KC_BTN2,                            KC_BTN1,                            _______, _______, _______, _______, _______
    ),

    /* Template
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬────────────┬───────┐
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * │       │       │       │       │       │       │       │       │       │       │       │       │       │            │       │
     * ├───────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬─────────┼───────┤
     * │          │       │       │       │       │       │       │       │       │       │       │       │       │         │       │
     * │          │       │       │       │       │       │       │       │       │       │       │       │       │         │       │
     * │          │       │       │       │       │       │       │       │       │       │       │       │       │         │       │
     * ├──────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─────────┼───────┤
     * │            │       │       │       │       │       │       │       │       │       │       │       │               │       │
     * │            │       │       │       │       │       │       │       │       │       │       │       │               │       │
     * │            │       │       │       │       │       │       │       │       │       │       │       │               │       │
     * ├────────────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴──┬────┴───────┬───────┼───────┤
     * │               │       │       │       │       │       │       │       │       │       │       │            │       │       │
     * │               │       │       │       │       │       │       │       │       │       │       │            │       │       │
     * │               │       │       │       │       │       │       │       │       │       │       │            │       │       │
     * ├─────────┬─────┴───┬───┴─────┬─┴───────┴───────┴───────┴───────┴───────┴─────┬─┴───────┼───────┴─┬──┬───────┼───────┼───────┤
     * │         │         │         │                                               │         │         │▒▒│       │       │       │
     * │         │         │         │                                               │         │         │▒▒│       │       │       │
     * │         │         │         │                                               │         │         │▒▒│       │       │       │
     * └─────────┴─────────┴─────────┴───────────────────────────────────────────────┴─────────┴─────────┴──┴───────┴───────┴───────┘
    [X] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    */
};

bool has_processed_record_user;
uint16_t key_timer;
uint16_t key_press_count = 0;
uint16_t key_press_change_hue_every_n_strokes = 1; // lower number is faster hue change
#ifdef CUSTOM_KEYPRESS_CHANGE_HUE_EVERY_NUM_STROKES
    key_press_change_hue_every_n_strokes = CUSTOM_KEYPRESS_CHANGE_HUE_EVERY_N_STROKES;
#endif

// https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions#layer-change-code-id-layer-change-code
layer_state_t layer_state_set_user(layer_state_t state) {
    #ifdef CUSTOM_RGB_MATRIX_USER_PREFERRED_MODE
        switch (get_highest_layer(state)) {
            case _FUNCTION:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
                break;
            default:
                rgb_matrix_mode_noeeprom(CUSTOM_RGB_MATRIX_USER_PREFERRED_MODE);
                break;
        }
    #endif
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
        uprintf("process_record_user: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif
    #ifdef CUSTOM_RGB_MATRIX_USER_PREFERRED_MODE
        if (!has_processed_record_user) {
            rgb_matrix_mode_noeeprom(CUSTOM_RGB_MATRIX_USER_PREFERRED_MODE);
            has_processed_record_user = true;
        }
    #endif
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return true;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return true;
        case MOUSE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MOUSEKEYS);
            }
            return true;
        case HK_COSL:
            clear_keyboard();
            reset_oneshot_layer();
            return true;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {
                if (timer_elapsed(key_timer) >= TAPPING_TERM) {
                    reset_keyboard();
                }
            }
            return false;
        case KC_CCCV:
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {
                if (timer_elapsed(key_timer) >= TAPPING_TERM) {
                    tap_code16(LCTL(KC_C));
                } else {
                    tap_code16(LCTL(KC_V));
                }
            }
            return true;
        case KC_HMEND:
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {
                if (timer_elapsed(key_timer) <= TAPPING_TERM) {
                    tap_code16(KC_HOME);
                } else {
                    tap_code16(KC_END);
                }
            }
            return true;
        default:
            key_press_count++;
            if (key_press_count%key_press_change_hue_every_n_strokes == 0) {
                key_press_count = 0;
                rgb_matrix_increase_hue_noeeprom();
            }
            return true; //Process all other keycodes normally
    }
}

// https://beta.docs.qmk.fm/using-qmk/guides/custom_quantum_functions#keyboard-idling-wake-code
void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}
