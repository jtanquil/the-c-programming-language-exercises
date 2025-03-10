## Chapter 1 Notes

---

### Arithmetic Operator Type Casting:
- if both operands are `int`, then the value of the arithmetic expression is an `int`; in particular, the value of integer division is the floor of the floating point result
- if one of the operands is a `float`, then the other operand is cast into a `float`

```
printf("%d", 5 / 9); // 0
printf("%3.2f", 5.0 / 9.0); // 0.56
```

### Formatting For Floats in `printf`:
- `%m.nf` will format the corresponding `float` as a number with at most `m` total digits, with `n` digits to the right of the decimal point.

```
printf("%4.2f", 20.123); // 20.12
```

### Reading Input Characters:
- `EOF` is an integer defined in `stdio.h` used to signal the end of file input. It is not equal to the value of any character, so any variable that is used to store input characters must be able to store the value of `EOF` in addition to the value of any character.
- the possible values of `char` are a subset of the possible values of `int` so an `int` variable can be used to store input characters.

### Character Constants:
- a character surrounded by single quotes like `'A'` represents the numerical ASCII value corresponding to that character.

```
printf("%d", 'A' == 65); // 1
```

### Call by Value:
- C is call by value; parameters store copies of the values passed into the function as arguments via the function call. If a function is passed values stored in an exterior variable, then it cannot alter the value stored in that variable because it was passed a copy of that value through the parameter:

```
void func(int b) {
  b = b + 1;
}

/* ... */

int a = 0;

func(a); // this function can change the value of the parameter that stores the value of a

printf("%d", a); // 0; the a on line 1 was unchanged by calling func
```

- **BUT**...if a function is passed a pointer to a variable, then the function can access that variable in memory and change the value stored at its memory address.
- also, when arrays are passed into functions as arguments, the function is passed a pointer to the beginning of the memory allocated to that array, so it is possible for the function to mutate the array.

### Strings as Character Arrays in C:
- strings are arrays of characters whose last character is `\0` (so the string representation of `"abc"` is an array whose elements are `'a'`, `'b'`, `'c'` and `'\0'`); when `printf` is passed a string (`%s`) it expects a string with that format.

### Global Variables and `extern`:
- global or external variables are defined once at the top level scope, and then declared with the `extern` keyword within each function in which that variable is accessed:

```
int a;

/* ... */

void func() {
  extern a;

  a = 1; // assigns the global variable a above to the value 1
}
```

- if the function body is placed before the definition of the global variable in the source file, then the `extern` keyword is required:

```
void func() {
  extern a; // refers to the a defined below

  a = 1;
}

int a;
```

- otherwise, `extern` is optional and accessing global/external variables from within a function is done implicitly; global variable definitions are typically placed at the top of a source file for this reason

```
int a;

/* ... */

void func() {
  a = 1; // assigns the global variable a to the value 1
}
```

- variable **definition** vs **declaration**: when variables are defined, then this refers to when variables are created or storage is assigned to them. When variables are declared, then this refers to when the usage of a variable is stated **but storage is not allocated to the variable**. The `extern` statements above are variable declarations but **not** definitions.