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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int maxi = 0;
        findMax(root,maxi);
        return maxi;
    }
    int findMax(TreeNode* node,int & maxi){
        if(node==0)return 0;
        int lh = findMax(node->left,maxi);
        int rh = findMax(node->right,maxi);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
};