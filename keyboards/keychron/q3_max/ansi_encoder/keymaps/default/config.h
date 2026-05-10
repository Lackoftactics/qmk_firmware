#pragma once

// ─── Latency / responsiveness ──────────────────────────────────────────────
#define USB_POLLING_INTERVAL_MS 1

// ─── Tap-hold behaviour ────────────────────────────────────────────────────
#define TAPPING_TERM 175
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD

// ─── SEND_STRING reliability in fussy apps (Slack, web inputs) ────────────
#define TAP_CODE_DELAY 5

// ─── NKRO: never silently degrade to 6KRO after transport switch / wake ───
#define FORCE_NKRO

// ─── Chatter resistance (Keychron's asymmetric algorithm) ─────────────────
//     Press fires instantly (zero lag); release defers DEBOUNCE ms to ignore
//     contact bounce on aging switches.
#define DEFAULT_DEBOUNCE_TYPE DEBOUNCE_ASYM_EAGER_DEFER_PER_KEY
#undef DEBOUNCE
#define DEBOUNCE 5

// ─── Instant wake from idle — eliminate dropped first keystrokes ──────────
#define STOP_MODE_LOW_POWER_DEEPSLEEP FALSE
