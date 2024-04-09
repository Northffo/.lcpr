/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30121
 *
 * [347] 前 K 个高频元素
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int> , vector<pair<int, int> >, less<pair<int, int> >> pq;
        unordered_map<int, int> mp;
        int len = nums.size();
    
        // for(int i = 0; i < len; i++) {
        //     if(mp.find(nums[i]) == mp.end()) {
        //         int cnt = 0;
        //         for(int j = 0; j < len; j++) {
        //             if(nums[j] == nums[i]) cnt++;
        //         }
        //         mp[nums[i]] = cnt;
        //         pq.push(pair<int, int>(cnt, nums[i]));
        //     }
        // }

        for(int i = 0; i < len; i++) mp[nums[i]] ++;

        for(auto it : mp) pq.push(pair<int, int>(it.second, it.first));

        vector<int> res;
        while(k --) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

