#pragma once

#define FORCE_NKRO // force n-key rollover
#define DEBOUNCE 5

#define MOUSEKEY_INTERVAL 16 // refresh every 16 frames
#define MOUSEKEY_DELAY 0 // no delay when pressing the movement key
#define MOUSEKEY_MAX_SPEED 8 // controls mousekey max speed
#define MOUSEKEY_WHEEL_DELAY 0 // no delay when pressing wheel movement key

#define ONESHOT_TIMEOUT 3000

#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Sets the default mode, if none has been set
#define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended
