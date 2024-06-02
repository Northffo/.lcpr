// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2982 lang=cpp
 * @lcpr version=30202
 *
 * [2982] 找出出现至少三次的最长特殊子字符串 II
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
#include <ranges>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumLength(string s) {
        int len = s.size();

        vector<int> v[26];

        int cnt = 0;
        for(int i = 0; i < len; i++) {
            cnt ++;
            if(i + 1 == len || s[i] != s[i + 1]) {
                v[s[i] - 'a'].push_back(cnt);
                cnt = 0;
            }
        }

        int ans = 0;

        for(auto &a : v){
            if(a.empty()) continue;
            ranges::sort(a, greater());

            a.push_back(0);
            a.push_back(0);

            ans = max({ans, a[0] - 2, min(a[0] - 1, a[1]), a[2]});
        }

        return ans ? ans : -1;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumLength
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */

