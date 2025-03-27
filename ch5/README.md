## Chapter 5 Notes

---

### Pointer Syntax

- `p = &c` assigns the address of `c` to the variable `p`; `p` **points to `c`**
- the `&` operator can only apply to objects in memory: variables and array elements
  - it can't be applied to expressions, constants, or `register` variables
- the unary `*` operator accesses the object that the pointer points to:

```
int x = 1, y = 2;
int *ip;          /* this is how to declare a pointer to an int named ip */

ip = &x;          /* now ip points to x */
*ip = 2;          /* assigns 2 to x (what ip is pointing to) */
ip = &y;          /* ip points to y now */
```

### Pointers and Function Arguments

C is pass by value, so there is no direct way for a called function to alter a variable in the caller, **but** the caller can pass pointers to the calling function which can give the function access to objects that then change:

```
/* swap will take two pointers to integers, a and b */
void swap(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;  
  *b = temp;
}

void main() {
  int a = 1;
  int b = 2;

  swap(&a, &b);

  printf("%d %d\n", a, b); /* 2 1 */
}
```

### Pointers and Arrays

- in general, any operation involving array subscripting can be done with pointers; the pointer version will generally be faster but might be harder to understand
- **idea**: the name of an array is a synonym for the location of the initial element; when declaring an array, say `int a[10]`, the variable `a` is a point to the element `a[0]`
- so code like this makes sense:

```
int a[10];
int *pa;

pa = a; // equivalent to pa = &a[0]
int x = *pa; // equivalent to int x = a[0];

/* equivalence of pointer + offset and array indexing operations */
int y = *(pa + 1); // valid ptr arithmetic: equivalent to int y = a[1];
int z = *(a + 2);  // a points to a[0] so this is also valid ptr arithmetic
```

- **one caveat**: a pointer `pa` is a variable, so statements like `pa = a` and `pa++` are legal (see pointer arithmetic for more), but array names are not variables, so `a = pa` and `a++` are not legal

### Pointer Arithmetic

Valid pointer arithmetic operations:

- **pointer comparison**: if `p` and `q` are pointers to elements of the same array, then `p < q` if `p` points to an earlier element than `q`
  - any pointer can be compared to `0` (this is never a valid memory address in C)
  - comparisons can only be made if `p` and `q` are pointers to the same array, with the exception of if one of them points to the first element past the end of the array
- **addition with an integer**: `p + n` means the address of the nth object beyond the one that `p` points to; `n` is scaled according to the size of the objects `p` points to, determined by the declaration of `p`
- **pointer subtraction**: if `p` and `q` point to elements of the same array, and `p < q`, then `p - q` returns the number of elements from `p` to `q`, not including `q`; operations like this can be used to make computations about lengths and offsets of arrays:

```
int maxsize;
int arr[maxsize];

/* check if moving to index i to i + j would be out of bounds */
int i, j;

if ((arr + maxsize) - (arr + i) < j) { /* it's out of bounds */ }
```

### Character Pointers vs Array Assignments

```
// two different ways of defining a character array with a string constant
char a[] = "hi";
char *b = "hi";  
```

- the difference between these two definitions is that the array that `a` points to just big enough to hold the sequence of characters and the `\0`: `{"h", "i", "\0"}`. Individual characters in the array can be changed by `a` will always point to the same storage in memory
- `b` is a pointer that points to the string constant `hi`; `b` can be reassigned to point somewhere else, but the contents of the string that it's pointing to can't be changed

### Pointer Arrays/Pointers to Pointers

`char *s[]` initializes an array of pointers to `char`s; in other words, the elements `s[i]` point to `char` objects and `*s[i]` will retrieve whatever `char` `s[i]` is pointing to

### 2D Arrays

`char s[row][col]` initializes `row` arrays of `char`s of length `col`. 

- equivalently, `s` is a one-dimensional array whose elements point to arrays of size `col` whose elements are `char`s. 
- when passing a multidimensional array as an argument to a function, the first dimension/subscript (in the above case, `row`) doesn't need to be specified **since `s` is a pointer to an array of columns (or more generally, an array whose elements are arrays of a fixed size, with one fewer dimension):**

```
/* all valid ways to pass s into f */
f(char s[row][col]);
f(char s[][col]);
f(char (*s)[y]); /* parentheses here because brackets have higher precedence */
```

### Pointers vs Multidimensional Arrays

The initialization `char *name[10]` allocates 10 pointers and doesn't initialize them; initialization must be done explicitly; but the "rows" of `name` can be of different sizes.

```
char *name[] = {'illegal month', 'jan', 'feb', 'mar'};
```

The initialization `char namearr[row][col]` sets aside space for `row` `char`s each with length `col`:

```
char namearr[][15] = {'illegal month', 'jan', 'feb', 'mar'}
```

This sets aside a fixed-size location in memory for `namearr[0]`, `namearr[1]` etc (in this case, the size of each is `15`).

### Command Line Arguments

Pass command line arguments by changing the signature of `main` to take arguments `int argc` and `char *argv`/`char[] argv`. `argc` is the length of `argv` and `argv` contains the command line arguments (`argv[0]` is set to the function name, so the arguments will be in `argv[1]`, ... , `argv[argc - 1]`)

### Pointers to Functions

It is possible to create pointers to functions, which allows them to be passed into other functions as arguments.

```
void fn1 (int *a) {
  // ...
}

// pass a pointer to fn1 into fn2
fn2((*fn1)(void *));
```

In the signature of `fn1` in the call to `fn2`, the argument to `fn1`, a pointer to an `int`, is cast as a generic **void pointer**, a pointer that can hold an address of any type and can be cast into any type. Any pointer can be cast as a void pointer and back without any loss of information.

Passing function pointers as arguments can be useful in cases where the caller needs to invoke a different function based on the other arguments passed to it (for instance, passing different comparison functions into a sort function depending on the types of values being sorted), and casting pointers as `void` pointers is also useful in these cases where it is not known ahead of time the signature of the particular function whose pointer is being passed.

- since `*` has lower precedence than `()`, parentheses are needed to indicate a pointer to a function:

```
void *f();    // function returning a void pointer
void (*f)();  // pointer to a function returning void
```

### Reading Complicated Declarations

```
// idea: go inside out
char (*(*x())[])();

// x is a function returning a pointer to an array[] of pointers to functions returning char

// x()
// x is a function...

// (*x())[]
// ...returning a pointer to an array[]...

// (*(*x())[])
// ...of pointers...

// (*(*x())[])()
// ...to functions...

// char (*(*x())[])()
// ...returning char

char (*(*x[3])())[5]

// x is an array[3] of pointers to functions returning a pointer to an array[5] of char

// x[3]
// x is an array[3]...

// *x[3]
// ...of pointers...

// (*x[3])()
// ...to functions...

// (*(*x[3])())[5]
// ...returning a pointer to an array[5]...

// char (*(*x[3])())[5]
// ...of char
```