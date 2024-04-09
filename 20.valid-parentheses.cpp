// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30121
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        int len = s.size();
        if(len % 2 == 1) return false;
        stack<char> st;

        for(int i = 0; i < len; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else if(s[i] == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else return 0;
            }
            else if(s[i] == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else return 0;
            }
            else if(s[i] == '}') {
                if(!st.empty() && st.top() == '{') st.pop();
                else return 0;
            }
            
        }

        return st.empty();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */

