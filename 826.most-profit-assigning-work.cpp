// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=826 lang=cpp
 * @lcpr version=30202
 *
 * [826] 安排工作以达到最大收益
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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // 要求在为每个工人找到一个在工作能力范围内报酬最多的工作
        // 寻找一个在不超过difficulty[i]下报酬最多的工作
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        for(int i = 0; i < n; i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        ranges::sort(jobs);
        ranges::sort(worker);

        int cnt = 0, j = 0;
        int maxprof = 0;
        for(int w : worker) {
            while(j < n && jobs[j].first <= w) {
                maxprof = max(maxprof, jobs[j++].second);
            }
            cnt += maxprof;
        }

        return cnt;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [85,47,57]\n[24,66,99]\n[40,25,25]\n
// @lcpr case=end

 */

