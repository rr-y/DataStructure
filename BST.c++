#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* getNode(int val){
	auto *node = new TreeNode();
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

TreeNode* insert(TreeNode* root, int val){
	if(root==NULL){
		return getNode(val);
	}

	if(val < root->val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);

	return root;
}

void inorder(TreeNode* root){
	if(root){
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}


TreeNode* inorderSucc(TreeNode* root){
	TreeNode* temp = root;
	while(temp and temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

TreeNode* deleteNode(TreeNode* root, int val){
	if(root == NULL)
		return root;

	if(val < root->val)
		root->left = deleteNode(root->left, val);

	else if(val > root->val)
		root->right = deleteNode(root->right, val);
	
	else{
		if(root->left == NULL){
			TreeNode* temp = root->right;
			delete(root);
			return temp;
		}
		else if(root->right == NULL){
			TreeNode* temp = root->left;
			delete(root);
			return temp;
		}
		else{
			TreeNode* inSucc  = inorderSucc(root->right);
			root->val = inSucc->val;
			root->right = deleteNode(root->right, inSucc->val);
		}
	}
	return root;
}




int main(){
	srand(1);
	TreeNode* root = NULL;
	for(int i=0;i<20;i++){
		// cout<<rand()%100<<endl;
		root = insert(root, rand()%100);
	}
	inorder(root);
	cout<<endl;
	root = deleteNode(root, 72);
	inorder(root);
}







