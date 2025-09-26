#include <vector>
#include <queue>
using namespace std;
#include <bits/stdc++.h>
using namespace std;


int r, c;
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    r = n;
    c = m;

    queue<pair<int, int>> q;

    // Apply BFS operation from border, where O is present
    // Replace O with T

    // First row
    for (int j = 0; j < c; j++) {
        if (mat[0][j] == 'O') {
            q.push(make_pair(0, j));
            mat[0][j] = 'T';
        }
    }

    // Last row
    for (int j = 0; j < c; j++) {
        if (mat[r - 1][j] == 'O') {
            q.push(make_pair(r - 1, j));
            mat[r - 1][j] = 'T';
        }
    }

    // First column
    for (int i = 0; i < r; i++) {
        if (mat[i][0] == 'O') {
            q.push(make_pair(i, 0));
            mat[i][0] = 'T';
        }
    }

    // Last column
    for (int i = 0; i < r; i++) {
        if (mat[i][c - 1] == 'O') {
            q.push(make_pair(i, c - 1));
            mat[i][c - 1] = 'T';
        }
    }

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            if (valid(i + row[k], j + col[k]) && mat[i + row[k]][j + col[k]] == 'O') {
                mat[i + row[k]][j + col[k]] = 'T';
                q.push(make_pair(i + row[k], j + col[k]));
            }
        }
    }

    // Replace all O with X
    // Replace all T with O
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 'O')
                mat[i][j] = 'X';
            else if (mat[i][j] == 'T')
                mat[i][j] = 'O';
        }
    }

    return mat;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> mat(R, vector<char>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<char>> result = fill(R, C, mat);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
