/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

// Tapping settings from original config
#define TAPPING_TERM 200
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

// Set the number of layers for VIA
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#ifdef OLED_DRIVER_ENABLE
  // Reverted to 128x64 to match the original rev3 configuration
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 30000
#endif

// RGB Matrix settings for rev4's per-key RGB
#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES      // reacts to keypresses
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   define ENABLE_RGB_MATRIX_CYCLE_ALL
#   define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL
#   define RGB_MATRIX_DEFAULT_HUE 0
#   define RGB_MATRIX_DEFAULT_SAT 255
#   define RGB_MATRIX_DEFAULT_VAL 150 // Set brightness
#   define RGB_MATRIX_DEFAULT_SPD 30
#endif

// To determine the handedness of the halves, you can use one of the options below.
// The EE_HANDS option saves the handedness to EEPROM which is the easiest to use.
// You can also use MASTER_LEFT or MASTER_RIGHT to explicitly set the handedness.
#define MASTER_LEFT

// The rev3 options below are generally not needed for rev4
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

