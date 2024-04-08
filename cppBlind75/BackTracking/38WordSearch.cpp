#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int height = board.size();
        int width = board[0].size();

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, 0, i, j, height, width))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int index, int i, int j, int height, int width)
    {
        if (i < 0 || i >= height || j < 0 || j >= width || board[i][j] != word[index])
            return false;

        if (index == word.size() - 1)
            return true;
        board[i][j] = '#';
        if (
            dfs(board, word, index + 1, i + 1, j, height, width) 
            || dfs(board, word, index + 1, i - 1, j, height, width) 
            || dfs(board, word, index + 1, i, j + 1, height, width) 
            || dfs(board, word, index + 1, i, j - 1, height, width))
            return true;

        board[i][j] = word[index];
        return false;
    }
};