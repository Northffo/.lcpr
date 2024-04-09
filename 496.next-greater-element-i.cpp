// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=30121
 *
 * [496] 下一个更大元素 I
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;          // 单调递增栈
        int len = nums2.size();     // nums2的长度
        // vector<int> mp(len, -1);    // 初始化为-1的哈希表
        unordered_map<int, int> mp;
        int nl[len];

        for(int num : nums2) {
            while(!st.empty() && num > st.top()) {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            if(mp.find(nums1[i]) == mp.end()) res[i] = -1;
            else res[i] = mp[nums1[i]];

        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */

