#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};


TreeNode* buildTree(){
    int val;
    cin>>val;
    if(val == -1)
        return NULL;
    auto root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(TreeNode* root){
    if(root == NULL)
        return;

    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}


int dmeter(TreeNode* root, int* maxD){
    if(root == NULL)
        return 0;
    int b = dmeter(root->right, maxD);
    int a = dmeter(root->left, maxD);
    
    // cases
    *maxD = max(*maxD, a+b+1);
    return max(a,b)+1;
}




int main(){
    auto root = buildTree();
    preorder(root);
    cout<<endl;
    int maxval = 0;
    dmeter(root, &maxval);
    cout<<maxval<<endl;
    return 0;
}