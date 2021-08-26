





// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.












class Solution {
public:
    void traverse(TreeNode* root){
        if(root){
           
            TreeNode* l=root->left;
            TreeNode* r=root->right;
            root->left=NULL;
            root->right=l;
            traverse(l);
            traverse(r);
            TreeNode * p=root;
            while(p->right){
                p=p->right;
            }
            p->right=r;
        }
    }
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
       
        cout<<"Debug 1"<<endl;
        traverse(root);
        cout<<"Debug 2"<<endl;
    
    
    }
};