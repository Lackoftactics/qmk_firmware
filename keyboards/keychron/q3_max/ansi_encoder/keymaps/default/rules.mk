# ============================================================================
# PROFESSIONAL QMK FEATURE CONFIGURATION
# ============================================================================

# Core Features
SPACE_CADET_ENABLE = yes           # Space Cadet Shift functionality
TAP_DANCE_ENABLE = yes             # Tap Dance for semicolon/quote
COMBO_ENABLE = no                  # Disabled for clean fast typing experience
LEADER_ENABLE = yes                # Leader key for Ruby shortcuts
ENCODER_MAP_ENABLE = yes           # Rotary encoder support

# Performance Optimizations
LTO_ENABLE = no                    # Disabled due to Keychron wireless compatibility
CONSOLE_ENABLE = no                # Disable console for smaller firmware
COMMAND_ENABLE = no                # Disable command feature for smaller firmware
MOUSEKEY_ENABLE = no               # Disable mouse keys (not used)
EXTRAKEY_ENABLE = yes              # Keep media keys enabled

# Advanced Features (Professional)
KEY_OVERRIDE_ENABLE = no           # Disabled (not used in this keymap)
CAPS_WORD_ENABLE = yes             # Enable Caps Word for better typing
REPEAT_KEY_ENABLE = yes            # Enable repeat key functionality
AUTO_SHIFT_ENABLE = no             # Disabled (conflicts with our tap-hold setup)

# Memory Optimizations
GRAVE_ESC_ENABLE = no              # Disabled (not used)
MAGIC_ENABLE = no                  # Disabled (can cause key swapping issues)
SPACE_CADET_ENABLE = yes           # Re-enable (needed for our setup)

# Wireless Optimizations (for Keychron)
SLEEP_LED_ENABLE = no              # Disabled for power saving
NO_USB_STARTUP_CHECK = yes         # Faster startup for wireless
