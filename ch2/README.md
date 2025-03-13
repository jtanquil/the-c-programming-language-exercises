## Chapter 2 Notes

---

### Data Types in C

- `char`: a single byte, capable of holding one character in the local character set
- `int`: an integer, reflecting the size of integers on the host machine
- `float` and `double` are single and double-precision floating point numbers, respectively

These data types can also have the following qualifiers applied to them:

- `short` and `long` apply to integers and provide different lengths of integers when pracftical. The size of `short`, `long` and unqualified `int`s depends on the compiler, subject to the following restrictions: `short`s and `int`s are at least 16 bits, `short`s are no longer than `int`s, `int`s are no longer than `long`s, which are at least 32 bits.

- `unsigned` and `signed` qualifiers apply to `char`s or any type of `int`. `unsigned` values are nonnegative, ranging from `0` to `2^n - 1` where `n` is the number of bits in that type. `signed` values range from `-2^(n - 1)` to `2^(n - 1) - 1` (in a two's complement machine).

- `long` can also apply to `double`, so `float`, `double` and `long double` can represent three different possible sizes.

### Constants and Literals

- `1234` is an `int` constant.
- `1234l` an `1234L` are `long` constants; an integer too big to fit into an `int` will also be interpreted as a `long` constant.
- `1234u` and `1234U` are `unsigned` constants; this can be combined with `l/L` (so `1234Ul` is an `unsigned long` constant)
- integer values can be specified in octal with a leading `0`, or in hexadecimal with a leading `0x` or `0X`. These can also be made `long` and/or `unsigned`.

- a character constant is written as one character in single quotes, like `'a'`; its value is the numeric value of the character in the machine's character set (typically ASCII).
- there are escape sequences for arbitrary byte-sized bit patterns: `\ooo` where the `o` are octal digits (from `0` to `7`), or `\xhh` where the `h` are hexadecimal digits (from `0` to `9`, `a` to `f` or `A` to `F`)

- constant expressions are expressions that only involve constants, and these expressions are evaluated at compile time. They can be used in any place where a constant can occur.

- **enumeration constants** are lists of constant integer values:

```
enum boolean { NO, YES };
```

This assigns `NO` to the value `0` and `YES` to the value `1`; by default `enum`s will assign values from this increasing integer sequence in order. It is also possible to specify values for all or some of the names in the `enum`:

```
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t' };
enum months = { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
/* this assigns FEB to 2, MAR to 3, etc... */
```

Names in an `enum` must be distinct, but values don't need to be distinct. `enum`s provide an alternative to `#define` statements with the advantage that the values can be generated for you.

### Declarations and `const`

- if an automatic (local) variable is not explicitly initialized, then they will initially contain undefined (garbage) values.
- external and static variables are initialized to zero by default.

- the `const` qualifier can be applied to any declaration to specify that its value will not be changed. For arrays, the `const` qualifier means its elements will not be altered.
- the `const` declaration can be used with array arguments, to indicate that the function call will not change the array.
- what happens in an attempt to change a `const` is implementation-dependent.

### Arithmetic, Logical and Relational Operators

- behave as normal
- `%` cannot be applied to `float` or `double`
- `/` performs truncation
- details of these (direction of truncation, sign of the result of `%`) are implementation-dependent
- relational and logical operators return `0` if false, `1` if true

### Type Conversion

- in general, "narrower" operands are converted into "wider" operands without losing information (for example, adding an `int` to a `float` converts the `int` operand into a `float`)
- type conversions are complicated by the presence of `unsigned` and `signed` quantities:
  - converting a `char` into an `int` can produce a negative integer on some machines, and it never can in others
  - comparisons between `signed` and `unsigned` values are also machine-dependent, based on the sizes of various integer types
- assignment expressions can cause type conversion: the value of the right-hand side is converted to the type of the left, which is the type of the result
- converting a `long` into a `short` causes truncation of the higher-order bits
- **explicit type coercion**: `(type-name) expression` coerces the value of `expression` into `type-name`; this is a unary expression called a cast
  - this can be used to cast arguments passed to functions into a certain type if the function expects that type, but this is unnecessary if the function prototype declares these arguments (as they should); the declaration causes automatic type coercion of any arguments when the function is called
  - without a function prototype, arguments in function calls perform the following type coercions: `char` and `short` become `int`, and `float` becomes `double`

### Bitwise Operations

- `&`: bitwise AND, can turn off bits: `x & 077` flips off all but the rightmost 6 bits of `x`
- `|`: bitwise inclusive OR, can turn on bits: `x | 077` flips on the rightmost 6 bits of `x`
- `^`: bitwise XOR, bits in `a ^ b` are `1` if the corresponding bits in `a` and `b` are different and `0` if they're the same
- `<<`: left shift - `x << n` shifts `x` `n` bits to the left
  - `n` must be a positive integer
- `>>`: right shift - `x >> n` shifts `x` `n` bits to the right
  - if `x` is unsigned, then the vacated bits will be `0`
  - if `x` is signed, depending on the machine, the vacated bits will be filled with sign bits or 0 bits
- `~`: unary one's complement; `~x` flips each `1` into a `0` and vice versa

### Aside: Binary Representation of Signed Quantities

- there are several ways to represent signed integers in binary:
  - **sign-magnitude**: set most significant bit of `x` to `0` if it's positive, `1` if not
    - issues: this produces multiple representations of 0, arithmetic operations and comparisons are tricky
  - **one's complement**: represent `-x` with the bitwise complement, `~x`
    - issues: this still produces multiple representations of 0, addition requires a wrap-around carry operation to work
  - **two's complement**: represent `-x` via the following procedure:
    - take the bitwise complement of `x`: `~x`
    - add 1 to `~x`, ignoring any overflow: `(~x) + 1`

- two's complement representation solves the problems of sign-magnitude and one's complement; there's only one representation of zero, and addition doesn't require wrap-around carry

- assuming that integers have `N` bits of storage, the two's complement representation maps the positive integers `0, ... 2^(N - 1) - 1` to the range `000...0, ..., 01111...1`, and the negative integers `-2^(N - 1), -2(N - 1) + 1, ... , -2, -1` to the range `100...0, ... , 111...1`. In other words, the positive integers are mapped to the first half of the range of possible bit representations, and the negative integers are mapped to the second half.

### Ternary Expressions

- `cond ? n_1 : n_2` evaluates to `n_1` if `cond` is true, otherwise `n_2`
- if `n_1` and `n_2` are different types, then type conversion occurs with the normal rules

### Order of Operations

- except for `&&`, `||`, `?:` or `,`, C doesn't specify the order in which operands are evaluated
  - some implications of this: expressions involving the return values of functions like `a = f() + g()` can produce different results depending on the order in which the function calls are evaluated (for instance, if the call to `f` alters a value that the call to `g` is dependent on)
  - the order in which function arguments are evaluated is also implementation-dependent: a function call like `f(n++, n)` can invoke `f` with different values depending on the implementation
- as in other languages the moral here is to not rely on operator precedence and use parentheses