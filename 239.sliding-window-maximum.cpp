/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30121
 *
 * [239] 滑动窗口最大值
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
        
        int len = nums.size();
        int l = 0, r = 0;

        for(r = 0; r < k; r++) pq.push(pair<int, int>(nums[r], r));
        res.push_back(pq.top().first);

        while(r < len) {
            pq.push(pair<int, int>(nums[r], r));
            while(r - pq.top().second >= k) {
                pq.pop();
            }

            res.push_back(pq.top().first);
            r++;
        }

        return res; 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

