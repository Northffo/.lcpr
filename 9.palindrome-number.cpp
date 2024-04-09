/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=30121
 *
 * [9] 回文数
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
    bool isPalindrome(int x) {

        // Solution 1
        // long long reverseNum = 0;
        // if(x < 0) return false;

        // long long tmp = x;
        // while(tmp) {
        //     reverseNum = reverseNum * 10  + tmp % 10;
        //     tmp /= 10;
        // }

        // return reverseNum == x;

        string s1 = to_string(x);
        string s2 = to_string(x);
        reverse(s1.begin(), s1.end());

        return s1 == s2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

