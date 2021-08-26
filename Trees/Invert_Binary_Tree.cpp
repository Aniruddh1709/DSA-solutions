






// Given the root of a binary tree, invert the tree, and return its root.





class Solution {
public:
    void traversal(TreeNode* &root){
        if(root){
            swap(root->left,root->right);
            traversal(root->left);
            traversal(root->right);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
       traversal(root);

      
      
        return root;
    }
};