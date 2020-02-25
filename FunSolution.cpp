//
// Created by Jian Wu on 24/02/2020.
//

#include "FunSolution.h"
#include <queue>

void infect(vector<vector<char>>& grid, const int& i, const int& j, int w, int h)
{
    if (i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != '1')
        return;

    grid[i][j] = '0';
    infect(grid, i+1, j, w, h);
    infect(grid, i-1, j, w, h);
    infect(grid, i, j+1, w, h);
    infect(grid, i, j-1, w, h);
}

void infect(vector<vector<int>>& grid, const int& i, const int& j, const int& w, int h, int& area)
{
    if (i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != 1)
        return;

    grid[i][j] = 0;
    area++;
    infect(grid, i+1, j, w, h, area);
    infect(grid, i-1, j, w, h, area);
    infect(grid, i, j+1, w, h, area);
    infect(grid, i, j-1, w, h, area);
}

int FunSolution::numIslands(vector<vector<char>>& grid) {
    // DFS solution
    if (grid.empty())
        return 0;

    int rows = grid.size(), cols = grid.front().size();
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1') {
                infect(grid, i, j, cols, rows);
                count++;
            }
        }
    }

    return count;
}

int FunSolution::maxAreaOfIsland(vector<vector<int> > &grid) {
    if (grid.empty()) return  0;
    int maxArea = 0;

    int rows = grid.size(), cols = grid.front().size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                int area = 0;
                infect(grid, i, j, cols, rows, area);

                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}

int FunSolution::islandPerimeter(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;

    const int rows = grid.size();
    const int cols = grid.front().size();
    int numOfStripes = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                numOfStripes += 4;
                int left = j - 1, up = i - 1;
                if (left >= 0 && grid[i][left] == 1) numOfStripes -= 2;
                if (up >= 0 && grid[up][j] == 1) numOfStripes -= 2;
            }
        }
    }

    return numOfStripes;
}