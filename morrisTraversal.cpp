class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        if(!root) return inorder;
        
        TreeNode* cur=root;
        while(cur){
            if(cur->left==NULL){
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode *l=cur->left;
                while(l->right && l->right!=cur){
                    l=l->right;
                }
                if(l->right==NULL){
                    l->right=cur;
                    cur=cur->left;
                }
                else if(l->right==cur){
                    inorder.push_back(cur->val);
                    l->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
};
