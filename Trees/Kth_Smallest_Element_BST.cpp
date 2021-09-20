
// Given the root of a binary search tree, and an integer k,
//  return the kth (1-indexed) smallest element in the tree.






class Solution {
public:
    void inorder(int &c,int &ans,TreeNode* root,int k){
        
        if(root && ans==-1){

            inorder(c,ans,root->left,k);
            c++;
            if(c==k){
                ans=root->val;
                return;
            }
            
            inorder(c,ans,root->right,k);
         
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int c=0;
        inorder(c,ans,root,k);
        return ans;
    }
};