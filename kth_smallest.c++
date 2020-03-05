#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    int countLeft;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), countLeft(0), left(NULL), right(NULL) {};
};

TreeNode* buildTree(TreeNode *root, int val){
    if(root == NULL){
        auto *p = new TreeNode(val);
        return p;
    }

    if(val < root->val){
        root->countLeft++;
        root->left = buildTree(root->left, val);
        
    }
    
    if(val >= root->val)
        root->right = buildTree(root->right, val);
    
    return root;
}


int findkthsmall(TreeNode* root, int k){
    if(root->countLeft == k-1){
        return root->val;
    }

    if(root->countLeft < k-1){
        return findkthsmall(root->right, k-root->countLeft-1);
    }
    else{
        return findkthsmall(root->left, k);
    }
}

int main(){
    vector<int> A{1,3,7,3,4,5,8,9};
    TreeNode* root = NULL;
    for(int i=0;i<A.size();i++){
        root = buildTree(root, A[i]);
    }
    cout<<findkthsmall(root, 2)<<endl;
    return 0;
}


