# Greedy with new grammar

The project is built with cmake using c++14

To build the project create a folder build in this directory and in it run the following commands

$ cmake ../

$ make

This should leave the final program called just main



When running main, there's two command line arguments:

--model is a necessary argument, right now the only option is perceptron

--file can be any file to read the model from, if not specified, the model will be read from the console

The perceptron file has to be in the following format:

-First, an integer n representing the size of the perceptron

-Next, the n doubles representing the weights

-Finally, a value b representing the bias



Format details:

-Variables need to be all latin lowercase, it can have numbers as long as they're not the first character

-Constants have to start with a "[" and then values "0", "1" or "?" separated by commas and finished with a "]"

-The operation <= has to be between two variables/constants with the symbol in the middle

-The operation P( x ) must use the uppercase "P" 

-The operaton ~( A )

-The operation ( A ) V ( B ) must use an uppercase "V"

-The operation ( A ) ^ ( B )

-The operations "EXISTS x ," and "FORALL x ," must use uppercase as seen


Example:

With the perceptron.txt file being:

"4

2 4 5 -13

-1"

The queries could be as follows:

$ EXISTS x, P(x)

$ YES

$ EXISTS x, ( [ ?,?,?,1] <= x) ^ ( P(x) )

$ NO