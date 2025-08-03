include keyboards/keychron/common/wireless/wireless.mk
include keyboards/keychron/common/keychron_common.mk

VPATH += $(TOP_DIR)/keyboards/keychron
TAP_DANCE_ENABLE = yes
COMBO_ENABLE     = yes
ENCODER_ENABLE   = yes   # knob
# Optional: shrink size
LTO_ENABLE       = yes
# Do NOT set VIA_ENABLE; VIA can’t see tap-dance/combos anyway