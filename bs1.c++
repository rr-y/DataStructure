
#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>& A, int st, int ed, int val){
    int ans = -1;
    while(st < ed){
        int mid = st + (ed-st)/2;
        cout<<st<<" "<<ed<<endl;
        if(A[mid] == val){
            ans = mid;
            break;
        }
        else if(A[mid] > val){
            ed = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    return ans;
}


int bs_lower(vector<int> &A, int st, int ed, int val){

    int ans = -1;
    while(st <= ed){
        int mid = st + (ed-st)/2;
        
        // condition
        if(A[mid] > val){
            ed = mid-1;
        }
        else if(A[mid] == val){
            ans = mid;
            ed = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    return ans;
}

int bs_upper(vector<int>& A, int st, int ed, int val){
    int ans = -1;
    while(st <= ed){
        int mid = st + (ed-st)/2;
        cout<<st<<" "<<ed<<endl;
        // condition
        if(A[mid] > val){
            ed = mid-1;
        }
        else if(A[mid] == val){
            ans = mid;
            st = mid+1;
        }
        else{
            st = mid+1;
        }
    }
    return ans;
}

int findRot(vector<int>& A, int st, int ed){
    int ans = 0;
    while(st <= ed){
        int mid = st + (ed-st)/2;
        if( (mid-1) >= 0 and A[mid] < A[mid-1]){
            return mid;
        }
        else if(A[mid] > A[A.size()-1]){
            st = mid+1;
        }
        else{
            ed = mid-1;
        }

    }
    return ans;
}


int upper_bound(vector<int>& A, int st, int ed, int val){
    while(st <= ed){
        int mid = st + (ed-st)/2;
        if(A[mid] == val)
            return mid;
        else if(A[mid] > val)
            ed = mid-1;
        else
            st = mid+1;
    }
    return ed;
}



int main(){
    vector<int> A = {6,8,4};
    // cout<<bs(A, 0, A.size(), 1)<<endl;
    // cout<<bs_lower(A, 0, A.size()-1, 2)<<endl;
    // cout<<upper_bound(A, 0, A.size()-1, 7)<<endl;
    cout<<findRot(A, 0, A.size()-1)<<endl;
    return 0;

}