/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 * @lcpr version=30202
 *
 * [1673] 找出最具竞争力的子序列
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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int len = nums.size();

        for(int i = 0; i < len; i++) {
            int num = nums[i];
            while(ans.size() && num < ans.back() && ans.size() +  len - i > k) {
                ans.pop_back();
            }

            if(ans.size() < k) ans.push_back(num);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,2,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3,3,5,4,9,6]\n4\n
// @lcpr case=end

 */

