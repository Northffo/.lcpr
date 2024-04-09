/*
 * @lc app=leetcode.cn id=2810 lang=cpp
 * @lcpr version=30121
 *
 * [2810] 故障键盘
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
    string finalString(string s) {
        string res;
        
        // solution 1
        // for(int i = 0; i < s.size(); i++) {
        //     if(s[i] == 'i') reverse(res.begin(), res.end());
        //     else {
        //         res += s[i];
        //     }
        // }

        deque<char> q;
        bool flag = true;       // 开始时字符串加在右端；

        for(char ch : s) {
            if(ch == 'i') flag = !flag;
            else {
                if(flag) q.push_back(ch);
                else q.push_front(ch);
            }
        }

        // for(int i = 0; i < s.size(); i++) {
        //     if(s[i] == 'i') flag = !flag;
        //     else {
        //         if(flag) q.push_back(s[i]);
        //         else q.push_front(s[i]);
        //     }
        // }

        
        // if(flag) {
        //     for(auto it : q) res += it;
        // } else for(auto it : q) res = it + res;
        
        if(flag) res = string(q.begin(), q.end());
        else res = string(q.rbegin(), q.rend());

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "string"\n
// @lcpr case=end

// @lcpr case=start
// "poiinter"\n
// @lcpr case=end

 */

