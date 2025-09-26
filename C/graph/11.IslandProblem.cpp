#include <vector>
#include <queue>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;



int r;
int c;
int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}
int numIslands(vector<vector<char>> &grid)
{
    r = grid.size();
    c = grid[0].size();

    queue<pair<int, int>> q;
    int count = 0;

    // check the char 1 in our grid
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                // Make all 1 convert to zero
                q.push(make_pair(i, j));
                grid[i][j] = '0';

                while (!q.empty())
                {
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();

                    // 8 direction mein check kar skta hu
                    for (int k = 0; k < 8; k++)
                    {
                        if (valid(new_i + row[k], new_j + col[k]) &&
                            grid[new_i + row[k]][new_j + col[k]] == '1')
                        {

                            q.push(make_pair(new_i + row[k], new_j + col[k]));
                            grid[new_i + row[k]][new_j + col[k]] = '0';
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << numIslands(grid) << endl;
    return 0;
}
