// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.


class Solution {
public:

        void inorder(TreeNode *root,vector<int> &v)
    {
        if(!root)
            return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        vector<int> r;
        inorder(root,r);
        for(int i=1;i<r.size();i++){
            if(r[i-1]>=r[i]){
                ans=false;
            }
        }
        return ans;
    }
};