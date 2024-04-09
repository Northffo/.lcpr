// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2009 lang=cpp
 * @lcpr version=30121
 *
 * [2009] 使数组连续的最少操作数
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
    int minOperations(vector<int>& nums) {
        int len = nums.size();
        int res = len;

        unordered_set<int> rmv(nums.begin(), nums.end());
        vector<int> sortedNums(rmv.begin(), rmv.end());
        sort(sortedNums.begin(), sortedNums.end());

        int j = 0;
        for(int i = 0; i < sortedNums.size(); i++) {
            int l = sortedNums[i];
            int r = l + len - 1;

            while(j < sortedNums.size() && sortedNums[j] <= r) {
                res = min(res, len - (j - i + 1));
                j ++;
            }
        }
            

        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minOperations
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [4,2,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,100,1000]\n
// @lcpr case=end

 */

