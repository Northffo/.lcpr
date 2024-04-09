// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=30121
 *
 * [713] 乘积小于 K 的子数组
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        
        int cnt = 0;
        int len = nums.size();
        int sum = 1;
        int l = 0, r = 0;

        for(r = 0; r < len; r++) {
            sum *= nums[r];;

            while(sum >= k) {
                sum /= nums[l++];
            }

            cnt += r - l + 1;
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */

