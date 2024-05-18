/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 * @lcpr version=30122
 *
 * [1553] 吃掉 N 个橘子的最少天数
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
// @lc code=start = 0;
class Solution {
    unordered_map<int, int> memo;
public:
    int minDays(int n) {
        if(n <= 1) return n;

        if(memo.contains(n)) return memo[n];

        memo[n] = min(minDays(n / 2) + n % 2, minDays(n / 3) + n % 3) + 1;

        return memo[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 6\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 56\n
// @lcpr case=end

 */

