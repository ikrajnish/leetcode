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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
    int maxPathDown(TreeNode* node,int & maxi){
        if(node == NULL) return 0;
        int left = max(maxPathDown(node->left,maxi),0);
        int right = max(maxPathDown(node->right,maxi),0);

        maxi = max(maxi,left + right + node->val);
        return max(left,right) + node->val;
    }
};