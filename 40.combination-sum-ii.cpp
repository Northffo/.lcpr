/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30122
 *
 * [40] 组合总和 II
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
    vector<vector<int>> res;
    bool st[110];
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0, 0, v);

        return res;
    }   

    void dfs(const vector<int>& candidates, int target, int cnt, int start, vector<int>& v) {
        if(cnt > target) return;

        if(cnt == target) {
            res.push_back(v);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) return;
            v.push_back(candidates[i]);
            dfs(candidates, target, cnt + candidates[i], i + 1, v);
            v.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */

