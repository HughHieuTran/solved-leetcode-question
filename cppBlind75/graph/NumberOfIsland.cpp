#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int width = grid[0].size();
        int height = grid.size();
        int result = 0;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, height, width);
                    result++;
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>> &grid, int i, int j, int height, int width)
    {
        if (i < 0 || i >= height || j < 0 || j >= width || grid[i][j] == '0')
            return;
        grid[i][j] = '0';

        dfs(grid, i + 1, j, height, width);
        dfs(grid, i - 1, j, height, width);
        dfs(grid, i, j + 1, height, width);
        dfs(grid, i, j - 1, height, width);
    }
};
