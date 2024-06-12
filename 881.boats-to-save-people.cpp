/*
 * @lc app=leetcode.cn id=881 lang=cpp
 * @lcpr version=30203
 *
 * [881] 救生艇
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
    int numRescueBoats(vector<int>& people, int limit) {
        int len = people.size();
        sort(people.begin(), people.end());

        int cnt = 0;

        int l = limit;

        int i = 0, j = len - 1;

        while(i < j) {
            int tmp = people[i] + people[j];

            if(tmp > limit) {
                cnt++;
                j--;
            }
            else if(tmp <= limit) {
                cnt++;
                i ++;
                j --;
            }
        }

        if(i == j) cnt++;

        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,5,3,4]\n5\n
// @lcpr case=end

 */

