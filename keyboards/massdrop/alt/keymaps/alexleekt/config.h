#pragma once

#define FORCE_NKRO // force n-key rollover

// https://beta.docs.qmk.fm/using-qmk/software-features/feature_debounce_type
#define DEBOUNCE 5

// https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_mouse_keys
#define MOUSEKEY_INTERVAL 16 // refresh every 16 frames
#define MOUSEKEY_DELAY 0 // no delay when pressing the movement key
#define MOUSEKEY_MAX_SPEED 8 // controls mousekey max speed
#define MOUSEKEY_WHEEL_DELAY 0 // no delay when pressing wheel movement key

// https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys
#define ONESHOT_TIMEOUT 3000

#define TAPPING_TOGGLE 2

// https://beta.docs.qmk.fm/using-qmk/software-features/feature_auto_shift
#define AUTO_SHIFT_TIMEOUT 150

// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix#additional-config-h-options-id-additional-configh-options
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_JELLYBEAN_RAINDROPS // Sets the default mode, if none has been set
#define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended

#define CUSTOM_RGB_MATRIX_USER_PREFERRED_MODE RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Sets the default mode, if none has been set
#define CUSTOM_KEYPRESS_CHANGE_HUE_EVERY_N_STROKES 4 // change hue every N key-strokes
