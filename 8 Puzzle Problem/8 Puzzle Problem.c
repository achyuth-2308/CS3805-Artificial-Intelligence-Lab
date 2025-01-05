//This is an implementation of the 8 puzzle problem solved for AI Lab CIA 1
#include <stdio.h>

#define SIZE 3

void display(int puzzle[SIZE][SIZE]);
int isSolved(int puzzle[SIZE][SIZE]);
void moveTile(int puzzle[SIZE][SIZE], int direction, int *x, int *y);

int main() {
    int puzzle[SIZE][SIZE];
    int zeroX, zeroY, move, steps = 0;

    // Input puzzle configuration
    printf("Enter the puzzle configuration (use 0 for blank):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &puzzle[i][j]);
            if (puzzle[i][j] == 0) {
                zeroX = i; zeroY = j;  // Track the blank tile
            }
        }
    }

    // Main loop: Continue until the puzzle is solved
    while (!isSolved(puzzle)) {
        display(puzzle);
        printf("Enter move (1=Up, 2=Down, 3=Left, 4=Right): ");
        scanf("%d", &move);

        // Make the move and update blank tile position
        moveTile(puzzle, move, &zeroX, &zeroY);
        steps++;
    }

    // Puzzle solved
    display(puzzle);
    printf("Puzzle solved in %d moves!\n", steps);
    return 0;
}

// Function to display the puzzle board
void display(int puzzle[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] == 0) {
                printf("   ");
            } else {
                printf("%2d ", puzzle[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the puzzle is solved
int isSolved(int puzzle[SIZE][SIZE]) {
    int goal[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] != goal[i][j]) return 0;
        }
    }
    return 1;
}

// Function to move tiles based on user input
void moveTile(int puzzle[SIZE][SIZE], int direction, int *x, int *y) {
    int newX = *x, newY = *y;

    // Calculate new position based on direction
    if (direction == 1 && *x > 0) newX--;        // Move up
    else if (direction == 2 && *x < SIZE-1) newX++; // Move down
    else if (direction == 3 && *y > 0) newY--;    // Move left
    else if (direction == 4 && *y < SIZE-1) newY++; // Move right
    else return; // Invalid move, do nothing

    // Swap tiles
    int temp = puzzle[*x][*y];
    puzzle[*x][*y] = puzzle[newX][newY];
    puzzle[newX][newY] = temp;

    // Update blank tile position
    *x = newX;
    *y = newY;
}
