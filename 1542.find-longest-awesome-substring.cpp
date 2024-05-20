// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1542 lang=cpp
 * @lcpr version=30202
 *
 * [1542] 找出最长的超赞子字符串
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
    int longestAwesome(string s) {
        unordered_map<int, unordered_map<int, int>> mp;
        int len = s.size();
        int maxlen = 0;

        for(int i = 0; i < len; i++) {
            if(i > 0)mp[i] = mp[i - 1];
            mp[i][s[i] - '0']++;
        }

        for(int i = 0; i < len; i++) {
            int j = 0;
            while(j <= i) {
                int l = i - j + 1;
                int cnt = 0;            // memo中奇数的个数
                if(j > 0) {
                    for(int k = 0; k < 10; k++) {
                        if((mp[i][k] - mp[j - 1][k]) % 2 == 1) cnt++;
                    }
                } else {
                    for(int k = 0; k < 10; k++) {
                        if(mp[i][k] % 2 == 1) cnt++;
                    }
                }
                
                if(l % 2 == 0 && cnt == 0) {
                    maxlen = max(maxlen, l);
                    break;
                } else if(l % 2 == 1 && cnt == 1) {
                    maxlen = max(maxlen, l);
                    break;
                } 
                
                j ++;
            }
        }

        return maxlen;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=longestAwesome
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "3242415"\n
// @lcpr case=end

// @lcpr case=start
// "12345678"\n
// @lcpr case=end

// @lcpr case=start
// "213123"\n
// @lcpr case=end

// @lcpr case=start
// "00"\n
// @lcpr case=end

 */

