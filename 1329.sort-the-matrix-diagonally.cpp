/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30122
 *
 * [1329] 将矩阵按对角线排序
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dg(2 * m + 2 * n);

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++) {
                dg[i - j + n].push_back(mat[i][j]);
            }
        }

        for(auto& d : dg) {
            sort(d.rbegin(), d.rend());
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mat[i][j] = dg[i - j + n].back();
                dg[i - j + n].pop_back();
            }
        }
        
        return mat;
    }
};



// class Solution {
// public:
//     vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
//         vector<int> dg;
//         int m = mat.size();
//         int n = mat[0].size();

//         for(int i = 0; i < n; i++) {
//             int col = i;
//             int row = 0;
//             dg.clear();
//             while(row < m && col < n) {
//                 dg.push_back(mat[row][col]);
//                 row++;
//                 col++;
//             }
//             sort(dg.begin(), dg.end());
//             col = i;
//             row = 0;
//             int idx = 0;
//             while(row < m && col < n) {
//                 mat[row][col] = dg[idx];
//                 row++;
//                 col++;
//                 idx++;
//             }
//         }

//         for(int i = 1; i < m; i++) {
//             int row = i;
//             int col = 0;
//             dg.clear();
//             while(row < m && col < n) {
//                 dg.push_back(mat[row][col]);
//                 row++;
//                 col++;
//             }
//             sort(dg.begin(), dg.end());
//             row = i;
//             col = 0;
//             int idx = 0;
//             while(row < m && col < n) {
//                 mat[row][col] = dg[idx];
//                 row++;
//                 col++;
//                 idx++;
//             }
//         }

//         return mat;
//     }
// };
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

