#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    int countRight;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), countRight(0), left(NULL), right(NULL) {};
};

TreeNode* buildTree(TreeNode *root, int val){
    if(root == NULL){
        auto *p = new TreeNode(val);
        return p;
    }

    if(val < root->val){
        root->left = buildTree(root->left, val);
        
    }
    
    if(val >= root->val){
        root->countRight++;
        root->right = buildTree(root->right, val);
    }
    
    return root;
}


int findkthsmall(TreeNode* root, int k){
    if(root->countRight == k-1){
        return root->val;
    }

    if(root->countRight < k-1){
        return findkthsmall(root->left, k-root->countRight-1);
    }
    else{
        return findkthsmall(root->right, k);
    }
}

int main(){
    vector<int> A{5,4,2,11,1,8,3,7};
    TreeNode* root = NULL;
    for(int i=0;i<A.size();i++){
        root = buildTree(root, A[i]);
    }
    cout<<findkthsmall(root, 6)<<endl;
    return 0;
}


