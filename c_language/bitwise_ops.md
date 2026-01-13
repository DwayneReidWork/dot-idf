---
title: Bitwise Operations
author: CW2 Richard Hailey
theme:
    name: catppuccin-mocha
---

Bitwise Operators - AND (&) [6.18]
---
# Bitwise AND Operator (&)
- performs logical AND on each pair of bits at corresponding positions
- result bit is 1 only if both input bits are 1

<!-- new_line -->

# Truth Table
```
a & b = result
0 & 0 =   0
0 & 1 =   0
1 & 0 =   0
1 & 1 =   1
```

<!-- new_line -->

# Example
```c
uint8_t a = 0b10110101;   // 0b10110101 = 181
uint8_t b = 0b11001010;   // 0b11001010 = 202
uint8_t c = a & b;        // 0b10000000 = 128
```
<!-- end_slide -->

Bitwise Operators - OR (|) [6.18]
---
# Bitwise OR Operator (|)
- performs logical OR on each pair of bits at corresponding positions
- result bit is 1 if either or both input bits are 1

<!-- new_line -->

# Truth Table
```
a | b = result
0 | 0 =   0
0 | 1 =   1
1 | 0 =   1
1 | 1 =   1
```

<!-- new_line -->

# Example
```c
uint8_t a = 0b10110101;   // 0b10110101 = 181
uint8_t b = 0b11001010;   // 0b11001010 = 202
uint8_t c = a | b;        // 0b11111111 = 255
```
<!-- end_slide -->

Bitwise Operators - XOR (^) [6.18]
---
# Bitwise XOR Operator (^)
- performs exclusive OR on each pair of bits at corresponding positions
- result bit is 1 if the input bits are different (exactly one is 1)

<!-- new_line -->

# Truth Table
```
a ^ b = result
0 ^ 0 =   0
0 ^ 1 =   1
1 ^ 0 =   1
1 ^ 1 =   0
```

<!-- new_line -->

# Example
```c
uint8_t a = 0b10110101;   // 0b10110101 = 181
uint8_t b = 0b11001010;   // 0b11001010 = 202
uint8_t c = a ^ b;        // 0b01111111 = 127
```

<!-- new_line -->

# Common Use Case
- XOR with itself clears a value: `a ^ a = 0`
- XOR is invertible: if `c = a ^ b`, then `a = c ^ b`
<!-- end_slide -->

Bitwise Operators - NOT (~) [6.18]
---
# Bitwise NOT Operator (~)
- performs logical negation on each bit
- inverts all bits: 0 becomes 1, 1 becomes 0

<!-- new_line -->

# Truth Table
```
~a = result
~0 =   1
~1 =   0
```

<!-- new_line -->

# Example
```c
uint8_t a = 0b10110101;   // 0b10110101 = 181
uint8_t b = ~a;           // 0b01001010 = 74

// Note: result depends on data type width
int8_t x = 1;             // 0b00000001
int8_t y = ~x;            // 0b11111110 = -2 (two's complement)
```

<!-- new_line -->

# Important
- NOT operator inverts bits based on the data type width
- for signed types, result is affected by two's complement representation
<!-- end_slide -->

Bitwise Operators - Left Shift (<<) [6.18]
---
# Bitwise Left Shift Operator (<<)
- shifts all bits to the left by a specified number of positions
- new bits shifted in from the right are 0
- bits shifted out from the left are discarded

<!-- new_line -->

# Example
```c
uint8_t a = 0b00001100;  // 12
uint8_t b = a << 2;       // 0b00110000 = 48
//          shift left by 2 positions
```

<!-- new_line -->

# Formula
- `a << n` is equivalent to multiplying by 2^n
- `a << 1` multiplies by 2
- `a << 3` multiplies by 8

<!-- new_line -->

# Example
```c
uint8_t x = 5;
uint8_t y = x << 1;  // 5 * 2 = 10
uint8_t z = x << 3;  // 5 * 8 = 40
```
<!-- end_slide -->

Bitwise Operators - Right Shift (>>) [6.18]
---
# Bitwise Right Shift Operator (>>)
- shifts all bits to the right by a specified number of positions
- behavior of left bits depends on signedness of data type
    - unsigned: new bits shifted in from left are 0 (logical shift)
    - signed: new bits are copies of the sign bit (arithmetic shift)

<!-- new_line -->

# Example - Unsigned
```c
uint8_t a = 0b11001100;  // 204
uint8_t b = a >> 2;       // 0b00110011 = 51
```

<!-- new_line -->

# Example - Signed
```c
int8_t x = -4;            // 0b11111100
int8_t y = x >> 1;        // 0b11111110 = -2 (sign bit extends)
```

<!-- new_line -->

# Formula
- `a >> n` is equivalent to dividing by 2^n (integer division)
- `a >> 1` divides by 2
- `a >> 3` divides by 8
<!-- end_slide -->

Bitwise Operators - Setting Flags [6.18]
---
# Setting Individual Bit Flags
- use the OR operator (|) to set specific bits to 1
- use a bitmask to specify which bit to set

<!-- new_line -->

# Example
```c
uint8_t flags = 0b00000000;
uint8_t mask = 1 << 3;     // 0b00001000 = create mask for bit 3

// set bit 3
flags = flags | mask;       // flags = 0b00001000

// shorthand
flags |= (1 << 3);          // flags |= mask
```

<!-- new_line -->

# Setting Multiple Flags
```c
uint8_t flags = 0;

// set bits 1, 3, and 5
flags |= (1 << 1);
flags |= (1 << 3);
flags |= (1 << 5);
// flags = 0b00101010 = 42
```
<!-- end_slide -->

Bitwise Operators - Removing Flags [6.18]
---
# Removing Individual Bit Flags
- use the AND operator (&) with a negated mask to clear specific bits
- use NOT (~) to invert the mask, then AND

<!-- new_line -->

# Example
```c
uint8_t flags = 0b00101110;
uint8_t mask = 1 << 2;     // 0b00000100 = create mask for bit 2

// clear bit 2
flags = flags & ~mask;      // ~mask = 0b11111011
                            // flags = 0b00101010

// shorthand
flags &= ~(1 << 2);
```

<!-- new_line -->

# Removing Multiple Flags
```c
uint8_t flags = 0b11111111;

// clear bits 0, 2, and 4
flags &= ~(1 << 0);
flags &= ~(1 << 2);
flags &= ~(1 << 4);
// flags = 0b11101010 = 234
```
<!-- end_slide -->

Bitwise Operators - Testing Flags [6.18]
---
# Testing Individual Bit Flags
- use the AND operator (&) to check if a specific bit is set
- if the result is non-zero, the bit is set (1)
- if the result is zero, the bit is not set (0)

<!-- new_line -->

# Example
```c
uint8_t flags = 0b00101010;

// test if bit 3 is set
if (flags & (1 << 3)) {
    printf("Bit 3 is set\n");
} else {
    printf("Bit 3 is not set\n");
}
```

<!-- new_line -->

# Testing Multiple Flags
```c
uint8_t flags = 0b00101010;

// check if bits 1 and 3 are set
if ((flags & (1 << 1)) && (flags & (1 << 3))) {
    printf("Both bits are set\n");
}

// check if any of bits 0, 2, 4 are set
if (flags & ((1 << 0) | (1 << 2) | (1 << 4))) {
    printf("At least one bit is set\n");
}
```
<!-- end_slide -->

Bitwise Operators - Extracting Bytes [6.18]
---
# Extracting Arbitrary Bytes from Multi-byte Data Types
- multi-byte data types (16-bit, 32-bit, 64-bit) store multiple bytes contiguously
- use right shift (>>) to position the desired byte at the least significant position
- use AND (&) with mask 0xFF (0b11111111) to extract only that byte

<!-- new_line -->

# Byte Order Considerations
- Little-endian: least significant byte is at the lowest memory address
    - Intel x86, x86-64, ARM
- Big-endian: most significant byte is at the lowest memory address
    - some network protocols, older systems

<!-- new_line -->

# Example - 32-bit Integer
```c
uint32_t value = 0x12345678;
// bytes from MSB to LSB: 12, 34, 56, 78

// extract each byte (big-endian bit positions)
uint8_t byte3 = (value >> 24) & 0xFF;  // 0x12
uint8_t byte2 = (value >> 16) & 0xFF;  // 0x34
uint8_t byte1 = (value >>  8) & 0xFF;  // 0x56
uint8_t byte0 = (value >>  0) & 0xFF;  // 0x78
```
<!-- end_slide -->

Bitwise Operators - Extracting Bytes (Continued) [6.18]
---
# Practical Example: Working with Color Values
- RGB color values are often stored as 32-bit integers
- format: 0xRRGGBB or with alpha: 0xAARRGGBB

<!-- new_line -->

# Example
```c
uint32_t color = 0xFF8040C0;  // ARGB format

uint8_t alpha = (color >> 24) & 0xFF;  // 0xFF = 255
uint8_t red   = (color >> 16) & 0xFF;  // 0x80 = 128
uint8_t green = (color >>  8) & 0xFF;  // 0x40 = 64
uint8_t blue  = (color >>  0) & 0xFF;  // 0xC0 = 192
```

<!-- new_line -->

# Using Macros for Clarity
```c
#define GET_BYTE(value, n) (((value) >> ((n) * 8)) & 0xFF)

uint32_t data = 0x12345678;
uint8_t b0 = GET_BYTE(data, 0);  // 0x78
uint8_t b1 = GET_BYTE(data, 1);  // 0x56
uint8_t b2 = GET_BYTE(data, 2);  // 0x34
uint8_t b3 = GET_BYTE(data, 3);  // 0x12
```
<!-- end_slide -->

Bitwise Operators - Constructing Multi-byte Values [6.18]
---
# Building Multi-byte Values from Individual Bytes
- inverse operation: combine individual bytes into a multi-byte integer
- use left shift (<<) to position each byte in the correct location
- use OR (|) to combine them together

<!-- new_line -->

# Example - Building 32-bit Value
```c
uint8_t byte3 = 0x12;
uint8_t byte2 = 0x34;
uint8_t byte1 = 0x56;
uint8_t byte0 = 0x78;

uint32_t value = (byte3 << 24) | (byte2 << 16) | 
                 (byte1 <<  8) | (byte0 <<  0);
// value = 0x12345678
```

<!-- new_line -->

# Using Macros
```c
#define BUILD_WORD(b3, b2, b1, b0) \
    (((uint32_t)(b3) << 24) | ((uint32_t)(b2) << 16) | \
     ((uint32_t)(b1) << 8)  | ((uint32_t)(b0)))

uint32_t color = BUILD_WORD(0xFF, 0x80, 0x40, 0xC0);
// color = 0xFF8040C0
```

<!-- new_line -->

# Real-world Use Case
- network packet construction
- image manipulation
- hardware register configuration
<!-- end_slide -->

Bitwise Operators - Common Patterns [6.18]
---
# Essential Bitwise Manipulation Patterns

<!-- column_layout: [1, 1] -->
<!-- column: 0 -->
# Set a Bit
```c
flags |= (1 << n);
```

# Clear a Bit
```c
flags &= ~(1 << n);
```

# Toggle a Bit
```c
flags ^= (1 << n);
```

# Check a Bit
```c
if (flags & (1 << n))
```

<!-- column: 1 -->
# Clear All Bits
```c
flags = 0;
```

# Set All Bits
```c
flags = 0xFF;  // for uint8_t
flags = ~0;    // for any size
```

# Extract Nibble
```c
uint8_t high = (value >> 4) & 0x0F;
uint8_t low  = value & 0x0F;
```

# Rotate Left
```c
uint8_t rotated = (value << 1) | 
                  (value >> 7);
```

<!-- end_slide -->
