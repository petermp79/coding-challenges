/*
    LEETCODE# 200

    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
    return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
    You may assume all four edges of the grid are all surrounded by water.

    Example 1:

    Input: grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]
    Output: 1

    Example 2:

    Input: grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
    ]
    Output: 3
 

    Constraints:

        m == grid.length
        n == grid[i].length
        1 <= m, n <= 300
        grid[i][j] is '0' or '1'.

*/


#include <iostream>
#include <vector>

using namespace std;


void dfs(vector<vector<char>> &grid, int i, int j, int r, int c) {
    
    // Skip out of bound and visited location
    if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != '1') {
        return; // skip
    }
    
    grid[i][j] = '2';   // visited
    
    // Traverse adjacent lands ('1'), if any, and mark them as visited to avoid
    // recounted as separate islands
    //
    dfs(grid, i+1, j, r, c);   // down
    dfs(grid, i-1, j, r, c);   // up
    dfs(grid, i, j+1, r, c);   // right
    dfs(grid, i, j-1, r, c);   // left
    
    return;
}

int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    
    if (row == 0) { // row = 0?
        return 0;
    }
    
    int islands = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '1') {
                // Visit all adjacent lands and mark them all 
                // as a single piece of land, count as 1
                //
                dfs(grid, i, j, row, col);
                islands++;
            }
        }
    }
    return islands;
}

// Print a matrix
//
void printMatrix(string heading, vector<vector<char>> grid) {

    string startspaces(heading.length()+4, ' ');
    string endspaces(heading.length(), ' ');


    cout << heading << "[" << endl;
    for (auto row : grid) {
        cout << startspaces << "[";
        for (auto x : row) {
            cout << x << ",";
        }
        cout << "]," << endl;
    }
    cout << endspaces << "]" << endl;
}


int main() {

    vector<vector<char>> grid1 {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    printMatrix("Matrix# 1: ", grid1);
    cout << "Number of Islands: " << numIslands(grid1) << endl;

    vector<vector<char>> grid2 {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << endl;
    printMatrix("Matrix# 2: ", grid2);
    cout << "Number of Islands: " << numIslands(grid2) << endl;

    return 0;
}


