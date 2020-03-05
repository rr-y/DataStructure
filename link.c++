//seperate out even and odd nodes in LL

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};


ListNode* buildList(){
    ListNode *head;
    head = NULL;
    srand(12);
    for(int i=0;i<20;i++){
        auto newNode = new ListNode(rand()%100);
        if(head){
            newNode->next = head;
            head = newNode;
        }
        else{
            head = newNode;
        }
    }
    return head;
}

void printList(ListNode* head){
    auto p = head;
    while(p){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

void eoSep(ListNode* head){
    ListNode *evenHead = NULL, *oddHead = NULL;
    auto p = head;

    while(p){
        auto q = p->next;
        if(p->val%2 == 0){
           
            if(evenHead){
                p->next = evenHead;
                evenHead = p;
            }
            else{
                evenHead = p;
                p->next= NULL;
            }
        }
        else{
            if(oddHead){
                p->next= oddHead;
                oddHead = p;
            }
            else{
                oddHead = p;
                p->next= NULL;
            }
        }
        p = q;
    }
    printList(evenHead);
    printList(oddHead);

}

int main(){
    ListNode* head = buildList();
    printList(head);
    eoSep(head);
    return 0;
}