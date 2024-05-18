/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 * @lcpr version=30201
 *
 * [2244] 完成所有任务需要的最少轮数
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
    unordered_map<int, int> memo;
public:
    int minimumRounds(vector<int>& tasks) {
        int len = tasks.size();
        for(int i = 0; i < len; i++) {
            memo[tasks[i]]++;
        }

        int cnt = 0;
        for(int num : tasks) {
            if(memo[num] == 1) {
                return -1;
            }


            if(memo[num] >= 2) {
                if(memo[num] % 3 != 0) cnt += memo[num] / 3 + 1;
                else cnt += memo[num] / 3; 
                memo[num] = 0;
            }
        }

        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,3,2,4,4,4,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,3]\n
// @lcpr case=end

 */

