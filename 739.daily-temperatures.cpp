/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30121
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ans(len, 0);
        vector<int> st;

        for(int i = 0; i < len; i++) {
            int temp = temperatures[i];
            if(st.empty()) st.push_back(i);
            else {
                while(st.size() && temp > temperatures[st.back()]) {
                    ans[st.back()] = i - st.back();
                    st.pop_back();
                }
                st.push_back(i);
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

