#include<bits/stdc++.h>
using namespace std;


vector<int> prefix_f(string& s){
	vector<int> prefixArr(s.length(), 0);
	int j;
	for(int i=1;i<s.length();i++){
		j = prefixArr[i-1];
		while(j > 0 && s[i] != s[j]){
			j = prefixArr[j-1];
		}
		if(s[j] == s[i]) j++;
		prefixArr[i] = j;
	}
	return prefixArr;
}

int main(){
	string s = "aabaab";
	auto ans = prefix_f(s);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}