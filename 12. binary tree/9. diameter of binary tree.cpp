// binary tree
// 9. diameter of a binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int, int> helper(TreeNode* root){
        pair<int, int> p;
        if(root == NULL){
            p.first = p.second = 0;
            return p;
        }
        
        pair<int, int> leftAns = helper(root -> left);
        pair<int, int> rightAns = helper(root -> right);
        
        int lh = leftAns.first;
        int ld = leftAns.second;
        int rh = rightAns.first;
        int rd = rightAns.second;
        
        int height = 1 + max(lh, rh);
        int diameter = max(lh + rh, max(ld, rd));
        
        p.first = height;
        p.second = diameter;
        return p;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> p = helper(root);
        return p.second;
    }
};

// time complexity is O(n)