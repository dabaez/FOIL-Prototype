# invint

Naive implementation


naive reads and prints through console

naivetxt reads from input.txt and prints in output.txt


-Write integer perceptron size n

-Write n real numbers representing the perceptron vector w

-Write the real number b representing the bias of the perceptron

-Write queries finished with /


Queries:

Variables x can be any string as long as they aren't "[" , "(" , "P(" , "~", "Exists" or "ForAll" and DON'T CONTAIN ANY SPACES

Constants have to start with "[" and then have n numbers "0", "1" or "?" and end with a "]" everything separated with spaces

The operation <= has to be between two variables/constants and has to have a <= in the middle, the three have to be separated by spaces (don't put a space between <=)

The operation P( x ) or P( c ) needs to have "P(" together (with no spaces) but separated with spaces from the variable/constant and the ")"

The ~ A has to be separated from A with a space

The operations ( A ) v ( B ) and ( A ) ^ ( B ) need to have everything separated with a space, also it has to be a lowercase v

Exists x. A and ForAll x. A has to be written exactly as stated and need to have spaces as exemplified

Example:

4

2 4 5 -13

-1

Exists x. P( x ) /

Exists x. ( [ ? ? ? 1 ] <= x ) ^ ( P( x ) ) /

/



Returns:

True

False
