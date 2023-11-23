# Basic Statistics Calculator

## Overview
This program, `basicstats`, computes basic statistical measures for a given dataset. It reads data from a file and calculates the mean, median, and standard deviation of the numbers.

## Features
- Dynamic memory allocation for dataset storage.
- Computation of mean, median, and standard deviation without using any external math libraries.
- Ability to process datasets of any size without re-compilation.

## Prerequisites
Make sure you have a C compiler installed on your system (e.g., GCC, Clang).

## Compilation
Navigate to the project directory and run the following command to compile the program:


## Input File Format
The input file should contain floating-point numbers with one number per line. For example:
	
	123.45
	567.90
	-345.17


Replace `<input_file>` with the path to a text file containing your dataset. The file should have one number per line. The sample test file is under cmake-build-debug.


## Output
The program will output the number of values processed, the mean, median, standard deviation, and the unused array capacity.

Example:

(base) sues-MacBook-Air:cmake-build-debug oubyou$ ./basicstats small.txt
Results:
--------
Num values: 12
mean: 85.776176
median: 67.469803
stddev: 90.382568
Unused array capacity: 8
(base) sues-MacBook-Air:cmake-build-debug oubyou$ ./basicstats large.txt
Results:
--------
Num values: 30
mean: 2035.599976
median: 1956.000000
stddev: 1496.152832
Unused array capacity: 10
(base) sues-MacBook-Air:cmake-build-debug oubyou$ 



## Author
- Xiaosu Zhou

## Acknowledgments
This project was created for the CS402 course at IIT.

