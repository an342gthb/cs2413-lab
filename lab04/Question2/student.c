#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool mirror(struct TreeNode *left2, struct TreeNode* right2){
    if(left2 == NULL && right2 == NULL)
      return true;
    if(left2 == NULL || right2 == NULL)
      return false;
    return (left2->val == right2->val) && mirror(left2->left, right2->right) && mirror(left2->right, right2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
      return true;
    return mirror(root->left, root->right);
}