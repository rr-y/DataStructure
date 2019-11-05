#include<iostream>
using namespace std;

class node
{
    public:
        int val;
        node* next;
};

class cirLinkedList
{
    private:
        node *head;
    
    public:
        cirLinkedList()
        {
            this->head = NULL;
        }

        void addNode(int val)
        {
            node* newNode = new node();
            newNode->val = val;
            newNode->next = NULL;
            node *p;
            if(this->head)
            {
                p = this->head;
                while(p->next != this->head)
                {
                    p = p->next;
                }
                p->next = newNode;
                newNode->next = this->head;
            }
            else
            {
                this->head = newNode;
                newNode->next = this->head;
            }
            
        }

        void printList()
        {
            node*p;
            if(this->head)
            {
                p = this->head;
                cout<<p->val<<" ";
                p = p->next;
                while(p != this->head)
                {
                    cout<<p->val<<" ";
                    p = p->next;
                }
                cout<<endl;
            }
            else
            {
                cout<<"List is Empty"<<endl;
            }
        }

        void delFirst()
        {
            node* p,q;
            if(this->head)
            {
                if(this->head->next == this->head)
                {
                    this->head = NULL;
                }
                else
                {
                    p = this->head;
                    while(p->next != this->head)
                        p = p->next;
                    p->next = this->head->next;
                    this->head = this->head->next;
                }
                
            }
            else
            {
                cout<<"Empty list"<<endl;
            }
            
        }

        void delLast()
        {
            node* p;
            if(this->head)
            {
                if(this->head->next == this->head)
                {
                    this->head = NULL;
                }
                else
                {
                    p = this->head;
                    while(p->next->next != this->head)
                        p = p->next;
                    p->next = this->head;
                }
                
            }
            else
            {
                cout<<"Empty list"<<endl;
            }
            
        }
};

int main()
{
    cirLinkedList* cll = new cirLinkedList();
    cll->addNode(1);
    cll->addNode(2);
    cll->printList();
    return 0;
}