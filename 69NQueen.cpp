#include <bits/stdc++.h>
using namespace std;

void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board,
          vector<bool> &column, vector<bool> &LeftDig, vector<bool> &RightDig) 
{
    // Base condition: if all queens placed
    if (row == n) {// guti bosate bosate last row te->push to the ans to 2d string
        ans.push_back(Board);
        return;
    }

    // Try placing queen in each column
    for (int j = 0; j < n; j++) {
        if (column[j] == 0 && LeftDig[n - 1 + row - j] == 0 && RightDig[row + j] == 0) {
            column[j] = 1;
            Board[row][j] = 'Q';
            LeftDig[n - 1 + row - j] = 1;
            RightDig[row + j] = 1;

            find(row + 1, n, ans, Board, column, LeftDig, RightDig);

            // Backtrack
            column[j] = 0;
            Board[row][j] = '.';
            LeftDig[n - 1 + row - j] = 0;
            RightDig[row + j] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> Board(n, string(n, '.'));

    vector<bool> LeftDig(2 * n - 1, 0);
    vector<bool> RightDig(2 * n - 1, 0);
    vector<bool> column(n, 0);

    find(0, n, ans, Board, column, LeftDig, RightDig);
    return ans;
}

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
