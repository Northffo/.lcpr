/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 * @lcpr version=30202
 *
 * [2644] 找出可整除性得分最大的整数
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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int max_div = divisors[0];
        int max_score = 0;
        unordered_map<int, int> mp;
        int score = 0;

        for(int div : divisors) {
            if(mp.contains(div)) continue;
            score = 0;
            for(int num : nums) {
                if(num % div == 0) {
                    score ++;
                }
            }

            mp[div] = score;
            if(score > max_score) {
                max_score = score;
                max_div = div;
            } else if(score == max_score) max_div = min(div, max_div);
        }
        
        return max_div;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,7,9,3,9]\n[5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [20,14,21,10]\n[5,7,5]\n
// @lcpr case=end

// @lcpr case=start
// [12]\n[10,16]\n
// @lcpr case=end

 */

