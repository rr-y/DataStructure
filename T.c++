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

void recIn(TreeNode* root){
    map<TreeNode*, bool> m;
    m[root] = true;
    stack<TreeNode* > st;
    st.push(root);
    while(!st.empty()){
        if(st.top()->left != NULL and m.count(st.top()->left) == 0){
            st.push(st.top()->left);
            m[st.top()] = true;
        }
        else{
            auto top = st.top();
            cout<<st.top()->val<<endl;
            st.pop();
            if(top->right != NULL and m.count(top->right) == 0){
                st.push(top->right);
                m[st.top()] = true;
            }
        }
            
    }
}

void recPre(TreeNode* root){
    stack<TreeNode* > st;
    st.push(root);

    while(!st.empty()){
        auto top = st.top();
        cout<<top->val<<" ";
        st.pop();
        if(top->right)
            st.push(top->right);
        if(top->left)
            st.push(top->left);
    } 
}

int main(){
    auto root = buildTree();
    preorder(root);
    cout<<endl;
    recPre(root);
    return 0;
}