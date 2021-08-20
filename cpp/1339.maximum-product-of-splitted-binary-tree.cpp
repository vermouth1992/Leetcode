/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 *
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 *
 * algorithms
 * Medium (38.64%)
 * Total Accepted:    44.8K
 * Total Submissions: 106.2K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a binary tree, split the binary tree into two subtrees by
 * removing one edge such that the product of the sums of the subtrees is
 * maximized.
 * 
 * Return the maximum product of the sums of the two subtrees. Since the answer
 * may be too large, return it modulo 10^9 + 7.
 * 
 * Note that you need to maximize the answer before taking the mod and not
 * after taking it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 110
 * Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
 * Their product is 110 (11*10)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2,3,4,null,null,5,6]
 * Output: 90
 * Explanation: Remove the red edge and get 2 binary trees with sum 15 and
 * 6.Their product is 90 (15*6)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [2,3,9,10,7,8,6,5,4,11,1]
 * Output: 1025
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 5 * 10^4].
 * 1 <= Node.val <= 10^4
 * 
 * 
 */
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

#include "common.hpp"

class Solution {
public:
    int maxProduct(TreeNode* root) {
        // compute the sum of each subtree and store in an array
        std::vector<long long> subtree_sum;
        long long total = this->compute_sum_subtree(root, subtree_sum);
        long long max_product = -1;
        for (auto& num : subtree_sum) {
            long long prod = (total - num) * num;
            if (prod > max_product) max_product = prod;
        }
        return max_product % (int) (1e9 + 7);
    }

private:
    long long compute_sum_subtree(TreeNode* root, std::vector<long long> &subtree_sum) {
        if (root == nullptr) return 0;
        long long left_sum = this->compute_sum_subtree(root->left, subtree_sum);
        long long right_sum = this->compute_sum_subtree(root->right, subtree_sum);
        long long sum = left_sum + right_sum + root->val;
        subtree_sum.push_back(sum);
        return sum;
    }
};
