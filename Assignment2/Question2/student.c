/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



int heightHelper(struct TreeNode* root, long min, long max){
    if(root==NULL)
        return 0;

    if(root->val < min || root->val > max)
        return -1;

    if((root->val == min && root->val!=-2147483648)|| root->val == max && root->val!=2147483648){
        return -1;
    }

    int leftHeight = heightHelper(root->left, min, root->val);
    if(leftHeight==-1)
        return -1;
    int rightHeight = heightHelper(root->right, root->val, max);
    if(rightHeight==-1)
        return -1;

    if(leftHeight-rightHeight>1 ||leftHeight-rightHeight<-1)
        return -1;

    if(rightHeight>leftHeight)
        return rightHeight +1;
    else
        return leftHeight+1;
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    if(root==NULL)
        return -1;

    return heightHelper(root, -2147483648, 2147483648)!=-1;

    (void)root;
    return false;
}
