#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TrieNode{
	bool isEnd;
	vector<TrieNode*> child{vector<TrieNode*>(26, NULL)};
};



void insert(TrieNode* root, string s){
	auto *temp = root;
	for(int i=0;i<s.length();i++){
		int index = s[i]-'a';
		if(temp->child[index]){
			temp = temp->child[index];
		}
		else{
			temp->child[index] = new TrieNode();
			temp = temp->child[index];
		}
	}
	temp->isEnd = true;

}


bool search(TrieNode* root, string s){
	auto *temp = root;
	for(int i=0;i<s.length();i++){
		int index = s[i]-'a';
		if(temp->child[index] == NULL){
			return false;
		}
		else{
			temp = temp->child[index];
		}
	}
	return (temp->isEnd == true)?true:false;
}

void printTrie(TrieNode* temp, string s, int level){
	if(temp == NULL){
		return;
	}
	if(temp->isEnd){
		for(int i=0;i<level;i++)
			cout<<s[i];
		cout<<endl;
	}
	for(int i=0;i<26;i++){
		if(temp->child[i]){
			s[level] = (char)('a' + i);
			// cout<<"In MIDDLE::"<<s<<endl;
			printTrie(temp->child[i], s, level+1);

		}
	}
}


int main(){
	TrieNode* root = new TrieNode();
	// insert(root, "aaj");
	insert(root, "raj");
	insert(root, "aditya");
	insert(root, "adi");
	// cout<<search(root, "rahu")<<endl;
	string s(20,'x');
	printTrie(root, s, 0);
}






