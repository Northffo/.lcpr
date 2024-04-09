/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30121
 *
 * [35] 搜索插入位置
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
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();

        int l = 0, r = len - 1;

        while(l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        
        // if(nums[l] == target) return l;
        // if(nums[l] < target) return l + 1;
        // if(nums[l] > target) return l;

        return nums[l] >= target ? l : l + 1;

        // return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */

