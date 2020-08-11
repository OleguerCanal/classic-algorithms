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
- __<< k__: Multiplies by 2^k (translates bits to the left).

#### Logical
- __>>> k__: Divides by 2^k (translates bits to the right). Substitutes MSB by 0.

#### Arithmetical
- __>> k__: Roughly divides by 2^k (translates bits to the right). Substitutes MSB with the sign bit value.

## Negative Numbers

### Signed binnary integers (signed magnitude)
Use MSB (Most Significant Bit) to encode the sign of the number. (0 for positive, 1, for negative). The rest of the number is encoded as usual: `S 8 4 2 1`.

### One's Complement
Takes the positive representation of the number and inverts all bits (negation/complement). We know a value is negative since a bit is reserved for the sign (0 for positive, 1 for negative). Value: `S 8 4 2 1`

e.g: -5 would be 11010 (since 5 is 00101).

__Pros__: Easy addition and substraction: To sum a positive and a negative value you would carry a common addition.
If the answer is positive there will be an overflow (N+1 bit set to 1), otherwise it'll mean its negative. This bit is afterwards disregarded (the result is given by the first N bits).

### Two's Complement
Instead of `8 4 2 1`, the number is represented as `-8 4 2 1`. Meaning that if right-most bit is set to 1, it adds -8 to the encoded values.

__e.g__: -3 in 4-bit notation would be 1101 (-8 + 5). Notice that complement as in 5 is the complement of 3 (abs of -3) wrt to 8.

__Notice__: -k = concat(1, 2^(N-1) - k)

The addition and substraction is the same as in One's Complement.

## Floating point Binary
Efficient use of computer register to represent wide variety of numbers.

The number is expressed as a __mantissa__ and an __exponent__. I.e: number = mantissa x 2^exponent. 
The more digits in the mantissa the greater the precision, the more digits in the exponent, the wider the range.

If having a register of `N+M` positions, usually the first N contain the __mantissa__ (stored in two's complement) and the subsequent M the __exponent__ (also stored in two;s complement).

__e.g__:
Consider the number in 16-bits register (10 mantissa, 6 exponent stored in Two's Complement): `0110100000|000011`.
- Both mantissa and exponent are positive (MSBs are 0).
- Exponent is 3
- We then know the number is 0.110100000 x 2^3
- Which we can express as: 0110.100000 (shift the coma 3 positions)
- We can then convert it to decimal as: `... 2 1 0. -1 -2 ...` which means `... 4 2 1. 0.5 0.25 ...`whic results into 6.5 in base 10.

__OBS__: If both are negative the coma moves to the left but the negative-value bit continues to be negative: e.g: `11000000|111110` -> `1.1 x 2 -2` -> `0.011` meaning `1 0.5 -0.25 0.125` (negative value is kept). Then in base 10: -0.125.
