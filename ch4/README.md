## Chapter 4 Notes

---

- the return values of functions are converted into the return type specified by the function definition, if necessary
- **compiling multiple files**: if compiling multiple files with a command like

```
cc file1.c file2.c ... filen.c
```

Then the object files `file1.o`, `file2.o`, ... `filen.o` are produced, and loaded into an executable `a.out`. If there is a compilation error in `file1.c`, then fixing the error and running the command

```
cc file1.c file2.o ... filen.o
```

recompiles `file1.c` by itself, producing the object file `file1.o`.

### Functions Returning non-`int` Values

For functions returning a non-`int` type value, such as a `double`, the function must declare the type of value it returns:

```
double func(int n) {
  /* ... */
}
```

In addition, any calling functions must know that `func` returns a non-`int` value, which can be done by explicitly declaring `func` in the calling routine:

```
// ...

void main() {
  double func(int);

  // ...

  func(1);
}
```

Incnsistencies between the return type in the definition and the return type given in the calling function will cause a compilation error if they are in the same source file. **But if they are compiled separately, inconsistencies will not be detected at compile time, resulting in errors at runtime**.

**Why this happens**: if there is no function prototype, a function is implicitly declared by its first appearance in an expression. If the name of a function first appears in a calling routine by being called by the routine, say

```
void main() {
  // ... no declaration of func

  func(1);
}
```

Then `func` is assumed to return an `int`, and nothing is assumed about its arguments.

Similarly, if a function declaration doesn't include arguments, then nothing is assumed about its arguments.

The lesson here is to **be explicit with function definitions and declarations - declare types of arguments and return values when necessary**.