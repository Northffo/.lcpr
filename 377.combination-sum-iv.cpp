/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30122
 *
 * [377] 组合总和 Ⅳ
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
    int res;
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(1010, 0);

        dp[0] = 1;
        for(int i = 0; i <= target; i++) {
            for(int num : nums) {
                if(i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }


        return dp[target];
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */

