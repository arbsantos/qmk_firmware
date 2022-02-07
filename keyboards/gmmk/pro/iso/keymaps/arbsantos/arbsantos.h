/* Copyright 2021 André Santos (@arbsantos)
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
 *
 */

struct RGB {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

// Macro Declarations
enum macros{
    TIL_A,
    TIL_O,
    ACCENT_C,
    NXT_COLOR,
    PRV_COLOR,
    WHITE,
    RED,
    BLUE,
    GREEN,
    ORANGE,
    TURQUOISE,
    PURPLE,
    YELLOW,
    CORAL,
    AZURE,
};

// Layers
#define _BASE 0
#define _FN1 1
#define _RGB_OPTS 2

#define ARRAYSIZE(arr)  sizeof(arr)/sizeof(arr[0])
