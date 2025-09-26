#include <bits/stdc++.h>
using namespace std;

int row[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
int col[] = {0, 0, -1, 1}; 
int r, c;

bool valid(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

int helpaterp(vector<vector<int>> hospital) {
    r = hospital.size();
    c = hospital[0].size();
    
    queue<pair<int, int>> q;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (hospital[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    int timer = 0;
    
    while (!q.empty()) {
        timer++;
        int curr_patient = q.size();
        
        while (curr_patient--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Up
            if (i - 1 >= 0 && hospital[i - 1][j] == 1) {
                hospital[i - 1][j] = 2;
                q.push(make_pair(i - 1, j));
            }

            // Down
            if (i + 1 < r && hospital[i + 1][j] == 1) {
                hospital[i + 1][j] = 2;
                q.push(make_pair(i + 1, j));
            }

            // Left
            if (j - 1 >= 0 && hospital[i][j - 1] == 1) {
                hospital[i][j - 1] = 2;
                q.push(make_pair(i, j - 1));
            }

            // Right
            if (j + 1 < c && hospital[i][j + 1] == 1) {
                hospital[i][j + 1] = 2;
                q.push(make_pair(i, j + 1));
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (hospital[i][j] == 1) {
                return -1;
            }
        }
    }

    return timer - 1;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> hospital(R, vector<int>(C));
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> hospital[i][j];
        }
    }
    
    cout << helpaterp(hospital) << endl;
    return 0;
}
