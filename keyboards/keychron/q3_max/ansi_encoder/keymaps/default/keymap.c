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

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    SPACE_NAV,  // Space-held layer for navigation and symbols
};

// Tap Dance declarations
enum tap_dance_codes {
    TD_SCLN_COLN,  // Semicolon on single tap, colon on double tap
    TD_QUOT_DQUO,  // Quote on single tap, double quote on double tap
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_QUOT_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
};

// Leader Key System - Using Siri/Cortana button for Ruby development shortcuts
// Press Leader (Siri/Cortana), then two-letter combo for immediate execution:
// Leader + B + P = binding.pry
// Leader + R + S = rspec
// Leader + I + T = it '' do ... end
// Leader + L + T = let(:) { cursor_here }
// Leader + E + X = expect()
// Leader + P + T = puts

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, UG_VALD,  UG_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  QK_LEAD,  UG_NEXT,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     TD(TD_SCLN_COLN), TD(TD_QUOT_DQUO), KC_ENT,
        SC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              SC_RSPC,              KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               LT(SPACE_NAV, KC_SPC),                 KC_RCMMD, KC_ROPTN, KC_APP,     KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     UG_TOGG,    _______,  _______,  UG_TOGG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        UG_TOGG,  UG_NEXT,  UG_VALU,  UG_HUEU,  UG_SATU,  UG_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  UG_PREV, UG_VALD,  UG_HUED,  UG_SATD,  UG_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  QK_LEAD,  UG_NEXT,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     TD(TD_SCLN_COLN), TD(TD_QUOT_DQUO), KC_ENT,
        SC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              SC_RSPC,              KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                LT(SPACE_NAV, KC_SPC),                 KC_RALT,  KC_RWIN,  KC_APP,     KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  UG_VALD,  UG_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    UG_TOGG,    _______,  _______,  UG_TOGG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        UG_TOGG,  UG_NEXT,  UG_VALU,  UG_HUEU,  UG_SATU,  UG_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  UG_PREV, UG_VALD,  UG_HUED,  UG_SATD,  UG_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),

    [SPACE_NAV] = LAYOUT_tkl_ansi(
        // Top row - Brackets and symbols (no numpad)
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,  _______,  _______,    _______,    _______,  _______,  _______,
        // Number row - Enhanced symbols and operators
        _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_MINS,  KC_EQL,     _______,    _______,  _______,  _______,
        // QWERTY row - Enhanced navigation and symbols
        KC_APPLICATION, KC_EXLM, KC_EQL, _______, _______, _______, LALT(KC_LEFT), LALT(KC_RGHT), LCMD(KC_LEFT), LCMD(KC_RGHT), KC_PLUS, KC_PIPE, KC_BSLS, _______, _______, _______, _______,
        // HOME ROW - Enhanced Ruby symbols + VIM NAVIGATION (HJKL)
        KC_AT,    KC_UNDS,  KC_COLN,  KC_DLR,   KC_HASH,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_SCLN,  KC_QUOT,            _______,
        // Bottom row - Page movement and angle brackets
        KC_PGUP,            KC_PGDN,  _______,  _______,  _______,  _______,  KC_LT,    KC_GT,    KC_COMM,  KC_DOT,   KC_GRV,             KC_TILD,              _______,
        // Control row - Menu button and Fn layer access
        _______,  _______,  _______,                                _______,                                KC_APPLICATION, KC_APPLICATION, MO(MAC_FN), _______, _______, _______, _______),
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [SPACE_NAV] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // ENCODER_MAP_ENABLE

// Professional per-key tapping term configuration - Space biased toward tap
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(SPACE_NAV, KC_SPC):
            return 195;  // Longer term for Space to prevent accidental holds during fast typing
        case SC_LSPO:
        case SC_RSPC:
            return 180;  // Slightly faster for Space Cadet (other keys stay snappy)
        case TD(TD_SCLN_COLN):
        case TD(TD_QUOT_DQUO):
            return 220;  // Faster tap dance for responsiveness
        default:
            return TAPPING_TERM;  // Default 175ms (from config.h)
    }
}

// Professional per-key permissive hold configuration - Space strongly favors tap
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(SPACE_NAV, KC_SPC):
            return false;  // NEVER prefer hold - Space favors tap unless clearly held
        case SC_LSPO:
        case SC_RSPC:
            return false;  // No permissive hold for predictable behavior during fast typing
        default:
            return false;  // Default: favor tap over hold in ambiguous cases
    }
}

// Professional hold-on-other-key-press configuration - Space strongly biased toward tap
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(SPACE_NAV, KC_SPC):
            return false;  // NEVER immediately activate hold - prevents accidental holds during space+letter sequences
        default:
            return false;  // Default behavior for all keys
    }
}

// Professional retro tapping configuration
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(SPACE_NAV, KC_SPC):
            return true;   // Send space on release if no other key was pressed
        default:
            return false;  // Default behavior
    }
}

// All combo processing removed for clean typing experience

// Leader Key State Tracking for Immediate Two-Key Ruby Sequences
static bool leader_active = false;
static uint16_t leader_first_key = KC_NO;

// Execute leader sequence immediately when second key is pressed
static bool execute_leader_sequence(uint16_t first_key, uint16_t second_key) {
    if (first_key == KC_B && second_key == KC_P) {
        // BP = binding.pry
        SEND_STRING("binding.pry");
        return true;
    } else if (first_key == KC_R && second_key == KC_S) {
        // RS = rspec
        SEND_STRING("rspec");
        return true;
    } else if (first_key == KC_I && second_key == KC_T) {
        // IT = it '' do ... end
        SEND_STRING("it '' do");
        tap_code(KC_ENT);
        SEND_STRING("  ");
        tap_code(KC_ENT);
        SEND_STRING("end");
        tap_code(KC_UP);
        tap_code(KC_UP);
        tap_code(KC_END);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        return true;
    } else if (first_key == KC_L && second_key == KC_T) {
        // LT = let(:) { cursor_here }
        SEND_STRING("let(:) { }");
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        return true;
    } else if (first_key == KC_E && second_key == KC_X) {
        // EX = expect()
        SEND_STRING("expect()");
        tap_code(KC_LEFT);
        return true;
    } else if (first_key == KC_P && second_key == KC_T) {
        // PT = puts
        SEND_STRING("puts ");
        return true;
    }
    return false;
}

// Leader key sequences - handled in process_record_user for immediate execution
void leader_end_user(void) {
    // This function is kept for compatibility but sequences are handled immediately
    // in process_record_user for zero-delay execution
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    // Handle immediate leader key execution (two-key Ruby sequences)
    if (keycode == QK_LEAD && record->event.pressed) {
        leader_active = true;
        leader_first_key = KC_NO;
        return true;
    }

    // If leader is active and this is a key press
    if (leader_active && record->event.pressed) {
        if (leader_first_key == KC_NO) {
            // This is the first key after leader
            leader_first_key = keycode;
            return false; // Don't send the first key
        } else {
            // This is the second key - execute sequence immediately
            if (execute_leader_sequence(leader_first_key, keycode)) {
                // Sequence executed successfully
                leader_active = false;
                leader_first_key = KC_NO;
                return false; // Don't send the second key
            } else {
                // Invalid sequence - reset and allow normal key processing
                leader_active = false;
                leader_first_key = KC_NO;
                return true; // Allow normal key processing
            }
        }
    }

    // Reset leader state on key release when leader is active
    if (leader_active && !record->event.pressed) {
        return false; // Don't send key releases during leader sequence
    }

    return true;
}
