// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=LCR 129 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 129] 字母迷宫
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool st[10][10];
    bool wordPuzzle(vector<vector<char>>& grid, string target) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                string s;
                dfs(grid, i, j, s, target.size());
                if(s == target) return true;
            }
        }


        return false;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, string& s, int len) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || st[i][j]) return;

        s.push_back(grid[i][j]);
        st[i][j] = 1;

        if(s.size() == len) return;
        dfs(grid, i - 1, j, s, len);
        if(s.size() == len) return;
        dfs(grid, i + 1, j, s, len);
        if(s.size() == len) return;
        dfs(grid, i, j - 1, s, len);
        if(s.size() == len) return;
        dfs(grid, i, j + 1, s, len);
        if(s.size() == len) return;
        st[i][j] = 0;

    }

   
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=wordPuzzle
// paramTypes= ["string[][]","string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */

