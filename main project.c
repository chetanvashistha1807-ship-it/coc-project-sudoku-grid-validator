#include <stdio.h>

/* 
   Function Prototypes 
   -------------------
   Declared here so the compiler knows about them before main().
*/
int check_rows(int grid[9][9]);
int check_columns(int grid[9][9]);
int check_subgrids(int grid[9][9]);

/* 
   Function: check_rows
   --------------------
   Verifies that each of the 9 rows contains the numbers 1–9 exactly once.
   Uses a simple frequency tracking array 'seen' to detect duplicates.
*/
int check_rows(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        int seen[10] = {0}; // Index 1–9 represent numbers in Sudoku
        for (int j = 0; j < 9; j++) {
            int num = grid[i][j];
            // Check if number is out of range or repeated
            if (num < 1 || num > 9 || seen[num])
                return 0; // Invalid row
            seen[num] = 1;
        }
    }
    return 1; // All rows valid
}

/* 
   Function: check_columns
   -----------------------
   Checks that each of the 9 columns contains the numbers 1–9 exactly once.
   Mirrors the logic used for rows but loops by column first.
*/
int check_columns(int grid[9][9]) {
    for (int j = 0; j < 9; j++) {
        int seen[10] = {0};
        for (int i = 0; i < 9; i++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num])
                return 0; // Invalid column
            seen[num] = 1;
        }
    }
    return 1; // All columns valid
}

/* 
   Function: check_subgrids
   ------------------------
   Checks all nine 3×3 subgrids (or "boxes") in the Sudoku grid.
   This requires four nested loops:
     - Outer two loops move to each 3×3 box start position.
     - Inner two loops scan the 3×3 cells inside that box.
*/
int check_subgrids(int grid[9][9]) {
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            int seen[10] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = grid[row + i][col + j];
                    if (num < 1 || num > 9 || seen[num])
                        return 0; // Invalid subgrid
                    seen[num] = 1;
                }
            }
        }
    }
    return 1; // All subgrids valid
}

/* 
   Function: main
   --------------
   Stores a Sudoku solution in a 9×9 2D array,
   calls the three validation functions,
   and prints the final verdict.
*/
int main() {
    // Example Sudoku grid (valid completed puzzle)
    int grid[9][9] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };

    // Validate Sudoku solution
    if (check_rows(grid) && check_columns(grid) && check_subgrids(grid))
        printf("VALID SOLUTION\n");
    else
        printf("INVALID SOLUTION\n");

    return 0;
}
