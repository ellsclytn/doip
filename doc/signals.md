# Control Signals - Uplift

All wires operate with active `LOW` (`0`), inactive `HIGH` (`1`). In other words, without any interaction, all signal lines would be `HIGH`. For Lower, Raise, and Memory recall operations, only three wires are needed. The rest should stay `HIGH`:

| Button   | 8 (Yellow) | 7 (Green) | 6 (Purple) |
|----------|------------|-----------|------------|
| Lower    | 0          | 1         | 1          |
| Raise    | 1          | 0         | 1          |
| Memory 1 | 0          | 0         | 1          |
| Memory 2 | 1          | 1         | 0          |
| Memory 3 | 0          | 1         | 0          |
| Memory 4 | 1          | 0         | 0          |

Memory set (the "M" button) is performed by pulling the Clear wire `LOW`.
