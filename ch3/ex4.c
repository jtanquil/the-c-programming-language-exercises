/* Exercise 3-4. In a two's complement number representation, our version of 
itoa does not handle the largest negative number, that is, the value of n equal 
to -(2^(wordsize - 1)). Explain why not. Modify it to print that value 
correctly, regardless on the machine on which it runs. */

/*
In a two's complement number representation, it is possible to represent
-(2^(wordsize - 1)) as an integer but not its negative, 2^(wordize - 1), so 
in the itoa function, flipping the sign of n won't work if n is 
-(2^(wordsize - 1)).
*/

 

