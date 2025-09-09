#include <bits/stdc++.h>
using namespace std;

// Function to check if placing queen at (row, col) is safe
bool check(int n, vector<string> &Board, int row, int col) {
    int i = row, j = col;

    // Check upper left diagonal
   {
        if (Board[i][j] == 'Q') return false;
        i--; j--;
    }

    i = row; j = col;
    // Check upper right diagonal
  {
        if (Board[i][j] == 'Q') return false;
   
    }

    i = row; j = col;
    // Check column (above)
    while (i >= 0) {
        if (Board[i][j] == 'Q') return false;
        i--;
    }

    return true; // Safe position
}

// Recursive backtracking function
void find(int row, int n, vector<vector<string>> &ans,
          vector<string> &Board, vector<bool> &column) 
{
    // Base condition: all queens placed
    if (row == n) {
        ans.push_back(Board);
        return;
    }

    // Try placing queen in each column
    for (int j = 0; j < n; j++) {
        if (column[j] == 0 && check(n, Board, row, j)) {
            column[j] = 1;
            Board[row][j] = 'Q';

            find(row + 1, n, ans, Board, column);

            // Backtrack
            column[j] = 0;
            Board[row][j] = '.';
        }
    }
}

// Solve N-Queens
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> Board(n, string(n, '.'));
    vector<bool> column(n, 0);

    find(0, n, ans, Board, column);
    return ans;
}

// Main function
int main() {
    int n;
    cout << "Enter number of queens (N): ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n\n";

    for (int k = 0; k < solutions.size(); k++) {
        cout << "Solution " << k + 1 << ":\n";
        for (string row : solutions[k]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
