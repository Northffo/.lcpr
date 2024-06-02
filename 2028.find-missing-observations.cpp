// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 * @lcpr version=30202
 *
 * [2028] 找出缺失的观测数据
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <ranges>
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
#include <<numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int all = mean * (n + m);
        int cnt = std::reduce(rolls.begin(), rolls.end(), 0);
        int last = all - cnt;
        
        vector<int> ans;

        if(n * 6 < last || n > last) return ans;
        
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < 7; j++) {
                tmp += j;
                if(n - 1 - i <= last - tmp && last - tmp <= (n - 1 - i) * 6) {
                    ans.push_back(j);
                    break;
                } else tmp -= j;
            }
        }

        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=missingRolls
// paramTypes= ["number[]","number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [3,2,4,3]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,5,6]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n3\n1\n
// @lcpr case=end

 */

