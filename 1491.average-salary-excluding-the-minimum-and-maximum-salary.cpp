/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 * @lcpr version=30122
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
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
    double average(vector<int>& salary) {
        int len = salary.size();
        sort(salary.begin(), salary.end());

        double sum = reduce(salary.begin() + 1, salary.end() - 1);
        // sum -= (salary[0] + salary[len - 1]);

        return sum / (len - 2);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4000,3000,1000,2000]\n
// @lcpr case=end

// @lcpr case=start
// [1000,2000,3000]\n
// @lcpr case=end

// @lcpr case=start
// [6000,5000,4000,3000,2000,1000]\n
// @lcpr case=end

// @lcpr case=start
// [8000,9000,2000,3000,6000,1000]\n
// @lcpr case=end

 */

