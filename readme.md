# invint

Naive implementation


naive reads and prints through console

naivetxt reads from input.txt and prints in output.txt

Compiled through C++14


-Write integer perceptron size n

-Write n real numbers representing the perceptron vector w

-Write the real number b representing the bias of the perceptron

-Write queries finished with /


Queries:

Variables x can be any string as long as they aren't "[" , "(" , "P(" , "~", "Exists" or "ForAll"




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
