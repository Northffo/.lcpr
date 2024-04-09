// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30121
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;

        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int len = s.size();

        for(char ch : s) mp[ch] = 0;

        int maxn = 1;

        while(r < len) {
            mp[s[r]] ++;

            if(mp[s[r]] > 1) {
                maxn = max(maxn, r - l);

                for(int i = l; i < r; i++) mp[s[i]] = 0;
                l ++;
                mp[s[l]] = 1;
                r = l;
            }

            if(r == len - 1 && mp[s[r]] == 1) maxn = max(maxn, r - l + 1);
            r ++;
 
        }


        return maxn;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

