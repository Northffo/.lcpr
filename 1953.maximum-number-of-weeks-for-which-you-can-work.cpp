// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 * @lcpr version=30201
 *
 * [1953] 你可以工作的最大周数
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
    long long numberOfWeeks(vector<int>& milestones) {
        long long m = ranges::max(milestones);
        long long rest = reduce(milestones.begin(), milestones.end(), 0LL) - m;

        if(m <= rest + 1) {
            return m + rest;
        } else {
            return 2 * rest + 1;
        }
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=numberOfWeeks
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,1]\n
// @lcpr case=end

 */

