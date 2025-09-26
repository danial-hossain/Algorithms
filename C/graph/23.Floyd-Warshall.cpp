#include <bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Replace -1 with INT_MAX to represent infinity
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Replace INT_MAX back to -1 to indicate no path
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INT_MAX)
                matrix[i][j] = -1;
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 4},
        {-1, 0, 2},
        {-1, -1, 0}};

    shortest_distance(matrix);

    cout << "Shortest distance matrix:" << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            if (val == -1)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}