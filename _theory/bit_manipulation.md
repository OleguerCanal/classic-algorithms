---
layout: post
title: "Bit Manipulation"
permalink: /theory/bit_manipulation
index: true
---
{% include start-row.html %}

## Reading binary numbers:

```
8421
0101 = 5
1010 = 10
```
## Basic operations:
__+, -, *__: Same as in base 10 but in base 2.

{% include end-row.html %}
{% include start-row.html %}

```
0110 + 0010 = 1000
0110 - 0011 = 0011
0011 * 0101 = 1111
```
{% include annotation.html %}
In case of doubt you can always convert to base 10, do operation there and convert back.

{% include end-row.html %}
{% include start-row.html %}

## Bit-wise operations:

Each bit is treated individually (no propagation as in basic operations).

- NEG: ~. $$a + ~a = 0$$
- OR: $$\mid$$.
- AND: &
- XOR: ^ (Exclusive OR: Exactly one of the values is $$1$$) a ^ a = 0, $$a ^ 0 = a. It is associative and distributive.

Practice: [Single number](https://leetcode.com/problems/single-number/)

### Bit translations
- __$$<<$$ k__: Multiplies by $$2^k$$ (translates bits to the left).

#### Logical
- __$$>>>$$ k__: Divides by $$2^k$$ (translates bits to the right). Substitutes MSB by 0.

#### Arithmetical
- __$$>>$$ k__: Roughly divides by $$2^k$$ (translates bits to the right). Substitutes MSB with the sign bit value.

Practice: [Hamming weight](https://leetcode.com/problems/number-of-1-bits/), [Reverse bits](https://leetcode.com/problems/reverse-bits/)

## Negative Numbers

### Signed binnary integers (Signed Magnitude)
Use MSB (Most Significant Bit) to encode the sign of the number. (0 for $$+$$; 1 for $$-$$).
The rest of the number is encoded as usual: `S 8 4 2 1`.

**Cons:**
- <span style="color:red">Most operations don't make sense. </span> (e.g. $$3 + (-3)$$ = `00011 + 10011` = `10110` = $$-6$$)

### One's Complement
Takes the positive representation of the number and inverts all bits (negation/complement). We know a value is negative since a bit is reserved for the sign (0 for $$+$$; 1 for $$-$$). Value: `S 8 4 2 1`

e.g: -5 would be `11010` (since 5 is `00101`).

__Pros__:
- <span style="color:green">Easy addition and subtraction: You can add a positive and a negative number using the common addition operation.</span>

If there is an overflow in the addition, we need to add 1 to the result:

e.g: in 3-bit + sign representation: $$4 + (-2)$$ = `0100` + `1101` = `1 0001` $$\rightarrow$$ `0010` = $$2$$

**Cons:**
- <span style="color:red">Negative 0:</span> (e.g. $$3 + (-3)$$ = `00011 + 11100` = `11111` = $$-0$$) This is addressd by the **two's complement**.

### Two's Complement
Instead of `8 4 2 1`, the number is represented as `-8 4 2 1`. Meaning that if right-most bit is set to 1, it adds -8 to the encoded values.

An alternative way of understanding two's complement in a similar way to one's complement: To get a negative of a value, flip all bits and add + 1.

__e.g__: -3 in 4-bit notation would be `1101` (-8 + 5). Notice that 5 is the complement of 3 (abs of -3) wrt to 8.
<!-- __Notice__: -k = concat(1, 2^(N-1) - k) -->

The addition and subtraction is the same as in One's Complement **discarding the overflows!!**

## Floating point Binary
<!-- Efficient use of computer register to represent wide variety of numbers. -->

The __number__ ($$n$$) is expressed as a __mantissa__ ($$m$$) and an __exponent__ ($$e$$). I.e: $$n = m \cdot 2^e$$.
Trade-off:
- The more digits in the **mantissa**, the greater the **precision**.
- the more digits in the **exponent**, the wider the **range**.

If having a register of `N+M` positions, usually the first N contain the __mantissa__ (stored in two's complement) and the subsequent M the __exponent__ (also stored in two;s complement).

__e.g__:
Consider the number in 16-bits register (10 mantissa, 6 exponent stored in Two's Complement): `0110100000|000011`.
- Both mantissa and exponent are positive (MSBs are 0).
- Exponent is 3
- We then know the number is $$0.110100000_2 \cdot 2^3$$
- Which we can express as: $$0.110100000_2 >> 3$$
- This is: $$0110.100000$$ (shift the coma 3 positions)
- We can then convert it to decimal as: `... 2 1 0. -1 -2 ...`
- I.e: `... 4 2 1. 0.5 0.25 ...`.
- This results into $$6.5_{10}$$.

__OBS__: If both are negative the coma moves to the left but the negative-value bit continues to be negative: e.g: `11000000|111110` = $$1.1 \cdot 2^{-2}$$ -> `0.011` meaning `... 1 0.5 -0.25 0.125 ...` (negative value is kept). Then in base 10: -0.125. You have to "remember" which was the negative value!

{% include end-row.html %}
