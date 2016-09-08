/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    } else if (p == NULL || q == NULL) {
        return false;
    } else if (p->val != q->val) {
        return false;
    } else if ( (p->left || q->left) && (p->right || q->right) ) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else if (p->left || q->left) {
        return isSameTree(p->left, q->left);
    } else if (p->right || q->right) {
        return isSameTree(p->right, q->right);
    } else {
        return true;
    }
}