#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis, int &n, int &m)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;

        while (q.size())
        {
            int row = q.front().first, col = q.front().second;
            q.pop();

            for (int del_row = -1; del_row <= 1; ++del_row)
            {
                for (int del_col = -1; del_col <= 1; ++del_col)
                {
                    int nh_row = row + del_row, nh_col = col + del_col;
                    bool valid = false;
                    if (nh_row >= 0 && nh_row < n && nh_col >= 0 && nh_col < m)
                        valid = true; // cond for valid neighbour coordinate
                    if (valid && !vis[nh_row][nh_col] && grid[nh_row][nh_col] == '1')
                    {
                        q.push({nh_row, nh_col});
                        vis[nh_row][nh_col] = true;
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < m; ++col)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    ++cnt;
                    bfs(row, col, grid, vis, n, m);
                }
            }
        }
        return cnt;
    }
};
