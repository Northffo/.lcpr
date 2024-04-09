/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30121
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> res;

        // postorder(root, res);

        // return res;

        
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        TreeNode* prev;       

        while(root || st.size()) {
            while(root) {
                st.push(root);
                root = root->left;
            }

            TreeNode* node = st.top();
            st.pop();

            if(!node->right || prev == node->right) {
                res.push_back(node->val);
                prev = node;
                root = nullptr;
            }
            else {
                st.push(node);
                root = node->right;
            }
        }
        return res;
    }

    void postorder(TreeNode* root, vector<int>& res) {
        if(!root) return ;
        
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

