/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30121
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // queue<TreeNode*> q;

        
        // vector<vector<int>> res;
        // if(!root) return res;

        // q.push(root);

        // while(q.size()) {
        //     vector<int> tmp;
        //     int len = q.size();
        //     for(int i = 0; i < len; i++) {
        //         if(q.front()->left) q.push(q.front()->left);
        //         if(q.front()->right) q.push(q.front()->right);
        //         tmp.push_back(q.front()->val);
        //         q.pop();
        //     }

        //     res.push_back(tmp);
        // }

        // return res;
        vector<vector<int>> res;
   if(!root) return res;

   queue<TreeNode*> q;
   q.push(root);
   
   while(q.size()){
      int len = q.size();        // 队列保存当前层的节点, 所以len是当前层节点的数量
      vector<int> tmp;           // 存放当前层节点的值
      for(int i = 0; i < len; i++) {      // 只处理当前层的节点
         TreeNode* node = q.front();    // 取出队头元素处理
         q.pop();                            // 删除队头元素
         tmp.push_back(node->val);           // 访问队头元素

         if(node->left) q.push(node->left);     // 如果左节点不为空, 把左节点入队
         if(node->right) q.push(node->right);
      }
      res.push_back(tmp);
   }


   return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

