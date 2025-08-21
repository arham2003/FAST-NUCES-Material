#include <iostream>

// Define the size of the maze
#define N 4

using namespace std;

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the given cell is valid or not
bool isValid(int maze[N][N], int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] != 0 && sol[x][y] == 0);
}


bool solveRatMaze(int maze[N][N], int x, int y, int destX, int destY, int sol[N][N]) {
    // If the rat has reached the destination
    if (x == destX && y == destY) {
        sol[x][y] = 1;
        return true;
    }

    // Check if the current cell is valid
    if (isValid(maze, x, y, sol)) {
        // Mark the current cell as part of the solution
        sol[x][y] = 1;

        // Try moving forward
        for (int i = 1; i <= maze[x][y]; i++) {
            if (solveRatMaze(maze, x + i, y, destX, destY, sol)) {
                return true;
            }
        }

        // If moving forward doesn't lead to a solution, try moving downward
        for (int i = 1; i <= maze[x][y]; i++) {
            if (solveRatMaze(maze, x, y + i, destX, destY, sol)) {
                return true;
            }
        }

        // If no valid move is found, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}


void solveMaze(int maze[N][N]) {
    int sol[N][N] = {0}; // Initializing the solution matrix

    if (solveRatMaze(maze, 0, 0, N - 1, N - 1, sol)) {
        cout << "Solution matrix:" << endl;
        printSolution(sol);
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {

    int maze[N][N] = {
        {2, 1, 0, 0},
        {3, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 0, 1}
    };

    solveMaze(maze);

    return 0;
}

