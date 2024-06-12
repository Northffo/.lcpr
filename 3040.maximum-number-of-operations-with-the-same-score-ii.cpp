/*
 * @lc app=leetcode.cn id=3040 lang=cpp
 * @lcpr version=30203
 *
 * [3040] 相同分数的最大操作数目 II
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
#include <string.h>
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
    int maxOperations(vector<int>& nums) {
        int len = nums.size();
        
        vector<vector<int>> memo(len, vector<int>(len));
        auto helper = [&](int i, int j, int target) -> int{
            for(auto& row : memo) {
                ranges::fill(row, -1);
            }

            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if(i >= j) return 0;

                int& res = memo[i][j];

                if(res != -1) return res;

                res = 0;
                if (nums[i] + nums[i + 1] == target) res = max(res, dfs(i + 2, j) + 1);
                if (nums[j - 1] + nums[j] == target) res = max(res, dfs(i, j - 2) + 1);
                if (nums[i] + nums[j] == target) res = max(res, dfs(i + 1, j - 1) + 1);
                return res;
            };

            return dfs(i, j);
        };
        
        int res1 = helper(2, len - 1, nums[0] + nums[1]);
        int res2 = helper(0, len - 3, nums[len - 1] + nums[len - 2]);
        int res3 = helper(1, len - 2, nums[0] + nums[len - 1]);

        return max({res1, res2, res3}) + 1;

    }


};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,6,1,4]\n
// @lcpr case=end

 */

