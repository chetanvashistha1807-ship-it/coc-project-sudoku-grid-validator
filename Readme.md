Sudoku Grid Validator (COC C Project)

Project Overview

This project is a Sudoku solution validator written in C.
It checks whether a completed 9×9 Sudoku grid follows the three fundamental Sudoku rules.
It’s a pure logic and data analysis problem, designed to test your ability to work with arrays, loops, and functions in a structured and modular way.


---

Problem Description

A Sudoku puzzle is considered valid only if:

1. Every row contains the digits 1 through 9 exactly once.


2. Every column contains the digits 1 through 9 exactly once.


3. Every 3×3 subgrid (box) also contains the digits 1 through 9 exactly once.



This program validates a completed Sudoku grid according to those three conditions and prints either:

VALID SOLUTION

or

INVALID SOLUTION


---

Core Concepts Demonstrated

2D Arrays: Used to represent the 9×9 Sudoku grid.

Nested Loops: Handle row, column, and subgrid traversal.

Functions: Each validation rule (rows, columns, boxes) is handled by a separate function.

If–Else Logic: Determines the final output based on validation results.

Basic Data Analysis: Implements logical tracking using a simple integer array as a frequency counter.



---

How It Works

1. The Sudoku grid is stored as a 9×9 integer array.


2. Three functions independently check:

check_rows() → Validates each row.

check_columns() → Validates each column.

check_subgrids() → Validates all 3×3 boxes.



3. Each function uses an integer array seen[10] to “track” which digits have appeared.


4. If a number repeats or is out of range (not 1–9), the function immediately flags it invalid.


5. The main() function combines all checks and prints the final verdict.




---

Code Structure

Sudoku_Validator/
│
├── sudoku_validator.c       # Main source file (this contains all functions)
├── README.md                # Project documentation
└── sample_input.txt         # (Optional) Example Sudoku grid for testing


---

Sample Output

For a valid Sudoku:

VALID SOLUTION

For an invalid Sudoku (duplicate or missing number):

INVALID SOLUTION
