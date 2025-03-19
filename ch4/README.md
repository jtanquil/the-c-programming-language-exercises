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

#### Scope

- for automatic (local) variables, their scope is within the function in which the name is declared
- for external variables, it is from declaration to the end of the file being compiled
  - if an external variable is referred to before it is defined, or if it's defined in a different source file from the reference, an `extern` declaration is mandatory

**Recall**: external variable *declarations* announce the properties (mainly the type) of the variable, whereas *definitions* do this and causes storage to be set aside.

```
// assume this is outside of any function
int a; // this is a definition, so the type of a is stated and memory is set aside for it

// ...

extern int b; // this is a declaration, so the type of b is stated but no memory is allocated
```

- there must only be one definition for each external variable amongst the files that make up the source program; other files may contain `extern` declarations to access them

#### Header Files

The task of splitting up large programs into several source files is expedited through **header files**, with a `.h` extension. The idea is to place the definitions and declarations shared amongst the source files in a single header file which is included in the source files that require those external declarations via the `#include` keyword.

- this means that instead of putting external declarations in each source file that needs them, those source files can just `#include` the relevant header(s)
- the use of header file(s) (there can be more, for larger programs) is a tradeoff; centralizing information means it is easier to prevent source files from having access to more external members than they need but the code becomes harder to maintain because dependencies are obscured

#### Static Variables

- the `static` keyword can be used in a declaration of an external variable to restrict access to that variable/function to within the source file being compiled.
- when `static` is used on an internal variable, they still remain local to the function in which they are defined but unlike other automatic variables, they remain in existence after the function call ends
  - internal `static` variables are a way to persist information within a single function beyond a single function call

```
// external; a can't be accessed from outside this file
static int a;

void func() {
  // internal; b will persist after the call to func ends
  static int b;
}
```

#### Register Variables

- the `register` keyword can be used in a variable declaration to signal to the compiler that the variable will be heavily used; the compiler may then place the variable in machine registers, which may result in better performance
- limitations: `register` can only be applied to automatic variables and parameters, only a few variables in each function can be kept in register, only certain types are allowed, and compilers may choose not to add `register` variables to machine registers anyway

#### Block Scope

- it exists for variables
- `static` block variables are initialized only the first time the block is entered

#### Initialization

Some notes about initialization for external and automatic variables:

| **External/`static`** | **Automatic/`register`**
| --- | --- |
| without explicit initialization, these are set to `0` | without explicit initialization, these are set to garbage values |
| the initializer must be a constant expression; initiailization occurs once, conceptually before the program begins execution  | the initializer can be any expression involving any previously defined values, including function calls...initializations are effectively shorthand for assignments |

#### Array Initialization

- arrays can be initialized following declaration with a comma-separated list of initializers enclosed in braces: `int a[] = {1, 2, 3};`
- if the size of the array is omitted, the compiler will compute the length by counting the initializers (3 in this case)
- if there are fewer initializers than the specified array size, then the missing elements will be set to `0` for external, automatic, and `static` variables
- too many initializers is an error
- character arrays can be initialized with string notation:

```
char str[] = "hello";

// is the same as 

char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};

// note that strings end with the terminating '\0' character so the length of str is 6
```

#### `#include`

- used as `#include <filename>` or `#include "filename"`; the former for accessing libraries like `stdio.h` and the latter for accessing other files comprising the source program
- `#include "filename"` will begin searching for the file typically where the source program was found; if it's not there, or if the include command is of the form `#include <filename>` then some other implementation-specific method is used to find the file
- `#include` lines are used to tie together declarations for a large program, guaranteeing that source files will have access to the same definitions and variable declarations
- when an included file is changed, all its dependent files will need to be recompiled

#### Macro Substitution with `#define`

- defintions have the form `#define name replacement`, where instances of the token `name` are replaced by `replacement`
- the scope of a `name` is from its point of defintion to the end of the source file
- definitions can use previous definitions
- substitutions are only made with tokens (no partial matching), and do not take place within quoted strings: `#define hell replacement` will replace `hell` with `replacement` but not the `hell` in `hello`, or `printf("hell");`
- names can be defined with any replacement text:

```
#define hi printf("hi"); // replaces the token hi with the statement printf("hi");
#define max(A, B) ((A) > (B) ? (A) : (B)) // a name/replacement that take arguments
```

**Some caveats about macro substitution**

- macros can take the form of a function call but the parameters do not act as such; what happens when using a macro with parameters is not passing arguments into parameters **but direct text substitution**, resulting in counterintuitive behavior:

```
#define square(x) x * x

...

int z = 5;

printf("%d\n", square(z + 1)); // prints 11
```

- this example prints `11` instead of the expected `36` because the expression `square(z + 1)` performs a direct text substitution, plugging in the literal text `z + 1` into the expression `x * x`: then the expression is `z + 1 * z + 1` (note the lack of parentheses), which evaluates to `11`

- functions can be, and are commonly implemented as macros; names can be undefined with `#undef` to ensure that a name will refer to a function and not a macro:

```
#undef func

void func() { ... }
```

- using `#param` in the replacement text, where `param` is a parameter that appears in `name`, will expand `#param` into a quoted string with the parameter replaced by the actual argument:

```
#define printd(exp) printf(#exp " = %g\n", expr)

// ...

printd(x/y)

/*
  this expands into:
  printf("x/y" " = %g\n", x/y)
/*
```

- `##` operator can concatenate arguments during macro expansion:

```
#define paste(front, back) front ## back

...

paste(x, y) // creates the token xy
```

- conditional constructs are available via preprocessor commands:

```
// only include the contents of name if it hasn't already been included
#if !defined(name)
#define name

/* contents of name here /*

#endif
```

- the normal conditional constructs are defined: `#elif condition`, `else`
- `#ifndef name` and `#ifdef name` are specialized conditional tests that execute their commands whether or not `name` is defined