/*
 * @lc app=leetcode.cn id=217 lang=cpp
 * @lcpr version=30121
 *
 * [217] 存在重复元素
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
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < len ; i++) {
            mp[nums[i]] ++;
            if(mp[nums[i]] > 1) return true;
        }

        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,3,3,4,3,2,4,2]\n
// @lcpr case=end

 */

