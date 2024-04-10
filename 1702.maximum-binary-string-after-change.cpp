/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 * @lcpr version=30121
 *
 * [1702] 修改后的最大二进制字符串
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
    string maximumBinaryString(string binary) {
        int len = binary.size();

        int j = 0;
        for(int i = 0; i < len ; i++) {
            if(binary[i] == '0') {
                // j = i + 1;
                while(j <= i || (j < len && binary[j] == '1')) j++;

                if(j < len) {
                    binary[j] = '1';
                    binary[i] = '1';
                    binary[i + 1] = '0';
                }
                
            }
        }   

        return binary;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "000110"\n
// @lcpr case=end

// @lcpr case=start
// "01"\n
// @lcpr case=end

 */

