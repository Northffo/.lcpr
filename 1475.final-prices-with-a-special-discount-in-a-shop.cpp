// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 * @lcpr version=30202
 *
 * [1475] 商品折扣后的最终价格
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
    vector<int> finalPrices(vector<int>& prices) {
        int len = prices.size();
        vector<int> discount(len, 0);
        vector<int> ans(len);
        stack<int> st;

        for(int i = 0; i < len; i++) {
            int x = prices[i];

            if(st.empty()) st.push(i);
            else {
                while(st.size() && x <= prices[st.top()]) {
                    discount[st.top()] = x;
                    st.pop();
                }
                st.push(i);
            }
        }

        for(int i = 0; i < len; i++) {
            ans[i] = prices[i] - discount[i];
        }

        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=finalPrices
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [8,4,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [10,1,1,6]\n
// @lcpr case=end

 */

