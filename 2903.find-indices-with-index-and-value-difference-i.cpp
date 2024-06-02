            /*
 * @lc app=leetcode.cn id=2903 lang=cpp
 * @lcpr version=30202
 *
 * [2903] 找出满足差值条件的下标 I
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
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int len = nums.size();
        int max_idx = 0, min_idx = 0;

        for(int i = indexDifference; i < len; i++) {
            int j = i - indexDifference; 
            if(nums[j] > nums[max_idx]) max_idx = j;
            else if(nums[j] < nums[min_idx]) min_idx = j;

            if(nums[max_idx] - nums[i] >= valueDifference) return {max_idx, i};
            else if(nums[i] - nums[min_idx] >= valueDifference) return {min_idx, i};
        }

        return {-1, -1};
    }   
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,4,1]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n2\n4\n
// @lcpr case=end

 */

