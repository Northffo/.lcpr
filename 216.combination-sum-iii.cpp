/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30122
 *
 * [216] 组合总和 III
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
#include <set>
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
    vector<vector<int>> res;
    bool st[10];
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;

        dfs(0, 0, k, n, 1, v);

        return res;
    }

    void dfs(int idx, int cnt, int k, int n, int start, vector<int>& v) {
        if(idx > k || (idx == n && cnt != n)) return;

        if(idx == k && cnt == n) {
            res.push_back(v);
            return;
        }

        for(int i = start; i < 10; i++) {
            if(!st[i]) {
                st[i] = 1;
                v.push_back(i);
                dfs(idx + 1, cnt + i, k, n, i, v);
                v.pop_back();
                st[i] = 0;
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

