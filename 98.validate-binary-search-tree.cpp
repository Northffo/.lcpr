/*
 * [98] 验证二叉搜索树
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30121
 *
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // return helper(root, LONG_MIN, LONG_MAX);

        stack<TreeNode*> st;
        vector<int> arr;

        TreeNode* node;
        while(root || st.size()) {
            while(root) {
                st.push(root);
                root = root->left;
            }

            node = st.top();
            if(arr.size() && node->val <= arr.back()) return false;
            arr.push_back(node->val);
            st.pop();
            root = node->right;
        }

        return true;
    }   

    bool helper(TreeNode* root, long long lower, long long upper) {
        if(!root) return true;
        
        if(root->val <= lower || root->val >= upper) return false;

        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

