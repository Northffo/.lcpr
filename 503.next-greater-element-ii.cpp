/*
 * @lc app=leetcode.cn id=503 lang=cpp
 * @lcpr version=30121
 *
 * [503] 下一个更大元素 II
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        vector<int> nums2(2 * len - 1); 
        for(int i = 0; i < len; i++) nums2[i] = nums[i];
        for(int i = len; i < 2 * len - 1; i++) nums2[i] = nums[i - len];
        
        // unordered_map<int, int> mp;
        stack<int> st;

        for(int i = 0; i < 2 * len - 1; i++) {
            while(!st.empty() && nums2[i % len] > nums2[st.top()]) {
                res[st.top()] = nums2[i % len];
                st.pop();
            }

            st.push(i % len);
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,3]\n
// @lcpr case=end

 */

