## Chapter 3 Notes

---

- **truthy values**: nonzero values
- **falsy values**: 0

- **statements** are expressions followed by a semicolon `;`
- **braces** collect a set of statements into a block that is considered equivalent to a single statement.

**The `,` Operator**: used in the form `expression_1, expression_2`
  - expressions are evaluated from left to right: first `expression_1`, then `expression_2`
  - the type and value of the entire expression are the type/value of the right operand, `expression_2`
  - this operator can be used to evaluate expressions that are closely related to each for, like a `for` loop iterating over two related variables:

```
char s[], t[];
int i, j;

/* ... */

/* assign i and j to 0 with a single compound expression with the comma operator */
for (i = 0, j = 0; s[i] != '\0\; i++) {
  if (s[i] = /* ... */) {
    /* do some stuff with i and j here... */
  }
}
```

**`continue`**:
  - when used in a `while` or `do` loop, execution continues to the test
  - when used in a `for` loop, execution continues to the increment expression

**`goto`**
  - `goto label` transfers execution to the statement following the label `label`
  - labels have global scope, and can be attached to any statement in the same function as the `goto`
  - don't use this