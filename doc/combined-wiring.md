# Multi-desk (Uplift and Loctek) Wiring

| RJ45 | Uplift | Loctek | SoC Pin                              |
|------|--------|--------|--------------------------------------|
| 1    | MEM    | RES    | PCF 0                                |
| 2    | RX     | SWIM   | GPIO13                               |
| 3    | GND    | NA     | NC                                   |
| 4    | NA     | WAKE   | PCF 1                                |
| 5    | 5V     | RX     | GPIO14                               |
| 6    | Bit 2  | TX     | GPIO12 panel side/GPIO15 driver side |
| 7    | Bit 1  | GND    | PCF 2                                |
| 8    | Bit 0  | 5V     | PCF 3                                |
