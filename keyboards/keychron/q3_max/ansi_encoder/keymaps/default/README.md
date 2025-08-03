# Professional Keychron Q3 Max Keymap

This keymap implements **professional-grade ergonomic features** based on modern keyboard science and developer workflow optimization. Designed for Ruby developers and power users who prioritize efficiency, comfort, and reduced cognitive load.

## Professional Features

### 1. Ultimate Caps Lock: Control/Escape Mod-Tap 🎯
**The single most impactful ergonomic improvement you can make.**
- **Tap Caps Lock**: Sends `Escape` (perfect for Vim, dismissing dialogs)
- **Hold Caps Lock**: Acts as `Control` (eliminates pinky strain for Ctrl shortcuts)
- **Why it's revolutionary**:
  - 🧠 **Cognitive**: Escape on home row without two-key combos
  - 💪 **Ergonomic**: Control becomes effortless, reducing RSI risk
  - ⚡ **Efficiency**: Terminal shortcuts (`Ctrl+C`, `Ctrl+D`) become lightning fast

### 2. Space Layer Navigation & Symbol System 🚀
**Core Concept**: Hold Space to activate a unified navigation and symbol layer
- **Space Key Behavior**:
  - **Tap**: Normal space character
  - **Hold**: Activates SPACE_NAV layer for navigation and symbols

#### **Professional Navigation & Productivity Layout**
```
Enhanced Navigation Cluster:
Y = Cmd+Left (line start)    U = Opt+Left (word left)    I = Opt+Right (word right)    O = Cmd+Right (line end)
H = Left Arrow  ←            J = Down Arrow  ↓           K = Up Arrow    ↑             L = Right Arrow →

Ruby Developer Symbols (Left Side):
Q = ! (bang/exclamation)
A = @ (at symbol - decorators)
S = _ (underscore - critical for Ruby)
D = : (colon - for symbols/hashes)
F = $ (dollar - for variables)
G = # (hash - for comments)

Programming Symbols (Right Side):
U I O P = Opt+← Opt+→ Cmd+← Cmd+→ (navigation)
J K L ; = ← ↓ ↑ → (Vim arrows)
M , . / = < > , . (angle brackets and punctuation)
Tab = Menu key (context menu)
Right Alt/Cmd = Menu key (alternative positions)

Enhanced Features:
E = = (equals sign for easy access)
```

#### **Symbol Access (Right Hand)**
```
Opening Brackets (Top Row UIOP):
U = (
I = [
O = {
P = <

Closing Brackets (Home Row JKL;):
J = )
K = ]
L = }
; = >

Operators:
Y = +
H = -
N = _
M = /
/ = \
' = "
```

#### **Complete Enhanced Space Layer Layout**
```
┌─────────────────────────────────────────────────────────────┐
│     │     │     │     │     │     │     │ [   │ ]   │ {   │ }   │     │     │
├─────────────────────────────────────────────────────────────┤
│     │ !   │ @   │ #   │ $   │ %   │ ^   │ &   │ *   │ (   │ )   │ -   │ =   │
├─────────────────────────────────────────────────────────────┤
│MENU │ !   │ =   │     │     │     │ O←  │ O→  │ C←  │ C→  │ +   │ |   │ \   │     │
├─────────────────────────────────────────────────────────────┤
│ @   │ _   │ :   │ $   │ #   │     │ ←   │ ↓   │ ↑   │ →   │ ;   │ '   │       │
├─────────────────────────────────────────────────────────────┤
│PgUp │PgDn │     │     │     │     │     │ <   │ >   │ ,   │ .   │ `   │ ~     │
├─────────────────────────────────────────────────────────────┤
│     │     │     │           SPACE           │MENU │MENU │     │     │     │     │
└─────────────────────────────────────────────────────────────┘

Legend:
- ←↓↑→ = Vim arrows (HJKL) | O←O→ = Option+Left/Right (word jumps) | C←C→ = Cmd+Left/Right (line jumps)
- Enhanced left side: Ruby symbols (! @ _ : $ #) + quick access
- Right side: Programming symbols and enhanced navigation
- Multiple Application/Menu key positions for reliability (Tab, Right Alt, Right Cmd)
- Uses KC_APPLICATION for better context menu compatibility
- Space Cadet Shift still handles parentheses via shift taps

**Ruby Developer Combos:**
- J+K = Escape | D+F = "->" | B+P = "binding.pry" | S+I = "#{}" | A+N = "&&" | O+R = "||"
```

### 2. Space Cadet Shift (SC_LSPO/SC_RSPC)
- **Left Shift**: Hold for shift, tap for `(`
- **Right Shift**: Hold for shift, tap for `)`
- Uses QMK's built-in Space Cadet Shift feature
- These replace the standard left and right shift keys on both MAC_BASE and WIN_BASE layers

### 3. Tap Dance Actions
- **Semicolon/Colon**: Single tap for `;`, double tap for `:`
- **Quote/Double Quote**: Single tap for `'`, double tap for `"`
- These replace the standard semicolon and quote keys on both base layers

### 4. Professional Ruby Developer Combos 💎
**Optimized for Ruby/Rails development workflow**

#### **Core Combos:**
- **J+K Combo**: `Escape` (Vim standard)
- **D+F Combo**: `->` (lambda arrow - Ruby blocks and lambdas)

#### **Advanced Ruby Combos:**
- **B+P Combo**: `binding.pry` (Ruby debugging - instant breakpoint)
- **S+I Combo**: `#{}` (Ruby string interpolation with cursor inside)
- **A+N Combo**: `&&` (logical AND operator)
- **O+R Combo**: `||` (logical OR operator)

These combos eliminate finger gymnastics for the most common Ruby symbols and debugging workflows.

### 5. Five Layers
- **MAC_BASE**: Default Mac layout with custom features
- **MAC_FN**: Mac function layer (accessed via Fn key)
- **WIN_BASE**: Default Windows layout with custom features
- **WIN_FN**: Windows function layer (accessed via Fn key)
- **SPACE_NAV**: Navigation and symbol layer (accessed by holding Space)

## Configuration

### Timing Settings
- **Tapping Term**: 200ms (time to distinguish between tap and hold)
- **Combo Term**: 50ms (time window for combo activation)
- **Permissive Hold**: Enabled for better mod-tap behavior
- **Space Layer**: Uses Layer-Tap (LT) for reliable tap/hold detection

### Space Layer Configuration
```c
// Space key behavior
LT(SPACE_NAV, KC_SPC)  // Tap = space, Hold = activate navigation layer

// Optional timing adjustments
#define TAPPING_TERM 200        // Adjust if Space layer activates too quickly/slowly
#define HOLD_ON_OTHER_KEY_PRESS // Prefer hold when other keys are pressed
```

### Hardware Compatibility
- Uses `LAYOUT_tkl_ansi` macro specific to Q3 Max
- Compatible with Q3 Max's 6x17 matrix configuration
- Preserves all Keychron-specific features (wireless, RGB, etc.)
- Encoder support maintained for volume/RGB control
- Space Layer works across all base layers (MAC/WIN)

## Usage Examples

### Space Layer Navigation
```
Text Navigation:
- Hold Space + H/J/K/L → Arrow keys (Vim-style)
- Hold Space + A → Home (beginning of line)
- Hold Space + F → End (end of line)
- Hold Space + S → Page Up
- Hold Space + D → Page Down

Word Movement:
- Hold Space + W → Jump word left (Ctrl+Left)
- Hold Space + E → Jump word right (Ctrl+Right)

Symbol Insertion:
- Hold Space + U → Insert [
- Hold Space + I → Insert {
- Hold Space + O → Insert <
- Hold Space + P → Insert >
- Hold Space + K → Insert ]
- Hold Space + L → Insert }

Operators & Special Characters:
- Hold Space + 1 → Insert !
- Hold Space + 2 → Insert @
- Hold Space + 3 → Insert #
- Hold Space + 4 → Insert $
- Hold Space + 5 → Insert %
- Hold Space + 6 → Insert ^
- Hold Space + 7 → Insert &
- Hold Space + 8 → Insert *
- Hold Space + 9 → Insert +
- Hold Space + 0 → Insert =
- Hold Space + - → Insert -
- Hold Space + = → Insert _
- Hold Space + / → Insert /
- Hold Space + Shift → Insert \
- Hold Space + ' → Insert "

Menu Key:
- Hold Space + Right Alt → Menu/Application key
```

### Other Features
```
Space Cadet Shift:
- Tap Left Shift → Insert (
- Tap Right Shift → Insert )
- Hold Shift → Normal shift behavior

Tap Dance:
- Tap ; → Insert ;
- Double-tap ; → Insert :
- Tap ' → Insert '
- Double-tap ' → Insert "

Combos:
- Press J+K together → Escape
```

## Building and Flashing

To build this keymap:
```bash
make keychron/q3_max/ansi_encoder:default
```

To flash to your keyboard:
```bash
make keychron/q3_max/ansi_encoder:default:flash
```

## Why This Layout?

### Ergonomic Benefits
- **Zero Hand Movement**: Navigate and insert symbols without leaving home row
- **Vim Compatibility**: HJKL navigation feels natural for Vim users
- **Logical Grouping**: Navigation on left hand, symbols on right hand
- **Spatial Relationships**: Opening brackets above closing brackets for intuitive pairing

### Productivity Gains
- **Faster Navigation**: Direct access to arrows, word jumps, and page movement
- **Efficient Symbol Input**: Common programming symbols at fingertips
- **Reduced RSI Risk**: Minimal hand movement and stretching
- **Consistent Across Layers**: Space Layer works on both Mac and Windows base layers

### Comparison with Traditional Layouts
| Feature | Traditional | This Layout |
|---------|-------------|-------------|
| **Arrow Access** | Dedicated arrow cluster | Home row (HJKL) |
| **Symbol Access** | Number row + Shift | Dedicated right-hand positions |
| **Hand Movement** | Frequent reaching | Minimal movement from home |
| **Learning Curve** | Familiar but inefficient | Moderate learning, high efficiency |
| **Vim Compatibility** | Requires mode switching | Native HJKL support |

## Safety Notes

This keymap has been specifically adapted for the Q3 Max hardware to avoid the issues that can occur when using incompatible layouts. The matrix configuration and pin assignments match the Q3 Max specifications exactly.

## Customization

### Space Layer Customization
You can modify the Space Layer to suit your workflow:

```c
// Add more symbols to unused positions
[SPACE_NAV] = LAYOUT_tkl_ansi(
    // Add symbols to number row
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______, _______, _______,
    // ... rest of layout
);

// Alternative: One-shot Space Layer
OSL(SPACE_NAV)  // Tap to activate layer for next keystroke only

// Smart bracket pairs (advanced)
enum custom_keycodes {
    CP_LPAREN = SAFE_RANGE,  // Outputs () with cursor inside
    CP_LBRACK,               // Outputs [] with cursor inside
    CP_LBRACE,               // Outputs {} with cursor inside
};
```

### General Customization Options
1. **Timing adjustments**: Modify `TAPPING_TERM` in `config.h`
2. **Add more tap dance actions**: Extend `tap_dance_actions[]`
3. **Create additional combos**: Add to `key_combos[]`
4. **Modify layer layouts**: Adjust key positions in `keymap.c`
5. **Space Cadet behavior**: See QMK Space Cadet documentation
6. **Space Layer symbols**: Rearrange or add symbols to SPACE_NAV layer

### Advanced Features
```c
// Layer indicators (optional)
layer_state_t layer_state_set_user(layer_state_t state) {
    // Add LED indicators for Space Layer activation
    return state;
}

// Custom symbol macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CP_LPAREN:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);  // Cursor inside parentheses
            }
            return false;
    }
    return true;
}
```

All features are implemented using standard QMK functionality and should be stable and reliable.
