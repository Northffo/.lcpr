// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=575 lang=cpp
 * @lcpr version=30203
 *
 * [575] 分糖果
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
    int distributeCandies(vector<int>& candyType) {
        int len = candyType.size();

        bool st[1000100] = {0};


        int cnt = 0; 
        for(int candy : candyType) {
            if(!st[candy]) {
                st[candy] = 1;
                cnt++;
            }
        }

        return len / 2 <= cnt ? len / 2 : cnt;

        // unordered_map<int, int> mp;
        // int cnt = 0;
        // for(int candy : candyType) {
        //     if(mp.size() > len / 2) break;
        //     else if(!mp.contains(candy) && cnt < len / 2) {
        //         mp[candy]++;
        //         cnt++;
        //     }
        // }
        
        // return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6,6]\n
// @lcpr case=end

 */

