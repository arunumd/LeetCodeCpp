#include <iostream>
#include <vector>

/*
 * QUESTION : (https://leetcode.com/problems/unique-paths/)
 * A robot is located at the top-left corner of a m x n grid (marked 'S' in the diagram below).
 * ---------------------------------
 * | S |  |  |  |  |  |  |  |  |   |
 * ---------------------------------
 * |   |  |  |  |  |  |  |  |  |   |
 * ---------------------------------
 * |   |  |  |  |  |  |  |  |  | F |
 * ---------------------------------
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'F' in the diagram below).
 * How many possible unique paths are there?
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> table(m, std::vector<int>(n, 0));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                int prev_l, prev_t;
                i == 0 ? prev_l = 0 : prev_l = table[i - 1][j];
                j == 0 ? prev_t = 0 : prev_t = table[i][j - 1];
                table[i][j] = prev_l + prev_t;
                if (i == 0 && j == 0) table[0][0] = 1;
            }
        }
        return table[m - 1][n - 1];
    }
};

int main() {
    Solution solver;
    std::cout << solver.uniquePaths(20, 20) << std::endl;
    return 0;
}
