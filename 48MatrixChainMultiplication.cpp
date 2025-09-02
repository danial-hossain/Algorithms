#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int P[] = {5, 4, 6, 2, 7};   // dimensions array
    int m[5][5] = {0};           // cost table
    int s[5][5] = {0};           // split table

    int i, j, k, d, q, min;

    for (d = 1; d < n - 1; d++) {
        for (i = 1; i < n - d; i++) {
            j = i + d;
            min = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
                if (q < min) {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;

    return 0;
}
