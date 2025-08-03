/* Copyright 2024 @ Keychron (https://www.keychron.com)
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

// ============================================================================
// PROFESSIONAL QMK SETTINGS - Based on Pascal Getreuer's recommendations
// ============================================================================

// Tap-Hold Configuration - Optimized to prevent accidental Space holds
#define TAPPING_TERM 175                    // Reduced base term, Space gets longer per-key term
#define TAPPING_TERM_PER_KEY               // Allow per-key tapping term customization
// PERMISSIVE_HOLD and HOLD_ON_OTHER_KEY_PRESS disabled globally for Space tap preference
#define QUICK_TAP_TERM 120                 // Quick taps register immediately as tap

// Advanced Tap-Hold Settings - Space strongly biased toward tap
#define RETRO_TAPPING                      // Send tap on release if no other key pressed
// No TAPPING_FORCE_HOLD - allows Space to favor tap in ambiguous cases

// Leader Key Configuration - Immediate execution (no timeout delay)
#define LEADER_TIMEOUT 50                  // Minimal timeout for cleanup only
#define LEADER_PER_KEY_TIMING              // Allow per-sequence timing if needed

// Tap Dance Configuration (enabled in rules.mk)
#define TAPPING_TERM_PER_KEY               // Allow different timing per tap dance

// Space Cadet Configuration (enabled in rules.mk)
// Using default Space Cadet settings (SC_LSPO = (, SC_RSPC = ))

// Performance Optimizations
// DEBOUNCE: Use more conservative setting for stability during fast typing
#undef DEBOUNCE
#define DEBOUNCE 15                        // More conservative for stability (was 10ms)
#define USB_POLLING_INTERVAL_MS 1          // 1000Hz USB polling for minimal latency
#define QMK_KEYS_PER_SCAN 4               // Process multiple keys per scan cycle

// Memory Optimizations
#define LAYER_STATE_8BIT                   // Use 8-bit layer state (supports up to 8 layers)
#define NO_ACTION_MACRO                    // Disable old macro system (use SEND_STRING instead)
#define NO_ACTION_FUNCTION                 // Disable old function system

// Feature Optimizations
#define ONESHOT_TAP_TOGGLE 2              // Number of taps to toggle one-shot
#define ONESHOT_TIMEOUT 3000              // One-shot timeout in milliseconds

// Encoder Settings (for rotary encoder)
#define ENCODER_RESOLUTION 4               // Standard encoder resolution
#define ENCODER_DEFAULT_POS 0x3           // Default encoder position

// RGB/LED Optimizations (if using RGB)
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150  // Reduce max brightness for battery life
    #define RGB_MATRIX_DEFAULT_VAL 80          // Default brightness
    #define RGB_DISABLE_WHEN_USB_SUSPENDED     // Turn off RGB when computer sleeps
#endif
