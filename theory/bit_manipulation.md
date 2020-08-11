# Bit Manipulation

## Reading binary numbers:

```
8421
0101 = 5
1010 = 10
```
## Basic operations:
__+, -, *__: Same as in base 10 but in base 2.

```
0110 + 0010 = 1000
0110 - 0011 = 0011
0011 * 0101 = 1111
```
__OBS__: In case of doubt you can always convert to base 10, do operation there and convert back.

## Bit-wise operations:
- NEG __~__
- OR __|__
- AND __&__
- XOR __^__ (Exclusive OR)

Remember that each bit is treated individually.

### Bit translations
- __>> k__: Divides by 2^k (translates bits to the right)
- __<< k__: Multiplies by 2^k (translates bits to the left)

## Two's Complement and Negative Numbers

### Two's Complement

Way to represent negative numbers. Instead of 8 4 2 1, the number is represented as -8 4 2 1. Meaning if right-most

