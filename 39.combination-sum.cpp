/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30122
 *
 * [39] 组合总和
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
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        dfs(candidates, target, 0, 0, v);
        
        // set<set<int>> tmp;

        // for(auto e : res) {
        //     set<int> stmp(v.begin(), v.end());
            
        // }


        return res;
    }

    void dfs(vector<int> candidates, int target, int cnt, int start, vector<int> v) {
        if(cnt > target) return;

        if(cnt == target) {
            res.push_back(v);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            v.push_back(candidates[i]);
            dfs(candidates, target, cnt + candidates[i], i, v);
            v.pop_back();
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

