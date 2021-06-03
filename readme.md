# Foundations of Symbolic Languages for Model Interpretability

## To replicate the experiments over Decision Trees

The file `experiments.sh` is there in order to make the replication of the experiments over Decision Trees as easy as possible, running it with
```
$ ./experiments.sh
```
creates the folder `build/` with the built project and runs the experiments with all the trees in the Decision Trees in the folder `dtrees/`, each tree leaves a file `build/data/dim_x_nleaves_y.csv` with the details of all of the queries ran on  that tree; the file `build/queries.txt` has all of the queries that were ran, one on each line; the file `build/queries.csv` has all of the averages of each query for each tree; the file `build/experiment_data.csv` has the information used in the paper, the average and maximum over all queries for all of the trees.

## Building requirements

The main project is built with cmake using C++14, it requires ANTLR but a complete ANTLR build is given in here.

The `exp.py` has the functions used in order to run the experiments and uses numpy for the random numbers and pandas for writing the results on csv, it has been run with python 3.8.5.

The file `exp.py` runs `./main` on the shell so it doesn't work on Windows but it has been tested to work succesfully on Linux and MacOS.

## Running the code independtly

In order to build the project, the file `CMakeLists.txt` is on the root directory and can be run with cmake, we recommend creating a folder `build/` in the project and running the following commands:
```
$ cake ../
$ make
```
The folder `build/` is needed in order for `exp.py` to find everything it needs to run the experiments.

Then, in the build folder the file `main` can be run in order to run the testing of the queries. It accepts four arguemnts:

* `--model=` is used to declare the model, this is required for the algorithm to run, right now it accepts `perceptron` for perceptrons, `dt` for decision trees and `afbdd` for afbdds.
* `--file=` for giving the algorithm the file from where to read the model.
* `--one` for supressing most outputs except for the answer for the query and errors and making the algorithm close after one query.
* `--version=` is used to run different versions of the algorithm: if given 1 it will run the naive algorithm that tests all assignations for the variables in order to find an answer, if given 2 it will run the more efficient version described in the paper that only takes in querys where all of the quantifiers are only of one type, either "Exists" or "For all", and also this one isn't able to process the FULL command, if given 3 it will be the same as version 2 but this time it's able to process the FULL command if given. If this argument isn't given it will just run the naive version.

After starting the algorithm, you can run the queries just by writing them line by line. The formatting of the queries is the following:

* Variables need to be all latin lowercase, it can have numbers as long as they're not the first character
* Constants have to start with a "[" and then values "0", "1" or "?" separated by commas and finished with a "]"
* The operation <= has to be between two variables/constants with the symbol in the middle
* The operation P( x ) must use the uppercase "P" 
* The operation FULL( x ) must also be uppercase
* The operaton ~( A )
* The operation ( A ) V ( B ) must use an uppercase "V"
* The operation ( A ) ^ ( B )
* The operations "EXISTS x ," and "FORALL x ," must use uppercase as seen here and must be at the start of the query

Example:

With the perceptron.txt file being:

(First number is the size of the perceptron, second line has the weights of the perceptrons and lastly is the bias)

"4

2 4 5 -13

-1"

The queries could be as follows:

```
$./main --model=perceptron --file=perceptron.txt --v=2
File loaded from perceptron.txt
Number of features = 4
Using efficient algorithm without full
$ EXISTS x, P(x)
YES
$ EXISTS x, ( [ ?,?,?,1] <= x) ^ ( P(x) )
NO
```