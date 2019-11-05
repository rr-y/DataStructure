#include<iostream>
#include<cstdlib>
using namespace std;

class node
{
    public:
        int val;
        node* next = NULL;
};

class linkedList
{
    private:
        node * head;
    public:

        linkedList()
        {
            node *head = NULL;
        }
        void addNodeHead(int val)
        {
            node* newNode = new node();
            newNode->val = val;
            if (this->head == NULL)
            {
                this->head = newNode;
            }
            else
            {
                newNode->next = this->head;
                this->head = newNode;
            }
            
        }

        void addNodeBack(int val)
        {
            node* newNode = new node();
            newNode->val = val;
            if (this->head == NULL)
            {
                this->head = newNode;
            }
            else
            {
                node* temp = this->head;

                while(temp->next)
                    temp = temp->next;
                
                temp->next = newNode;
            }
            
        }

        void printList()
        {
            if(this->head)
            {
                node* temp = this->head;

                while(temp)
                {
                    cout<<temp->val<<" ";
                    temp = temp->next;
                }
                cout<<endl;
            }
            else
            {
                cout<<"List is empty"<<endl;
            }
            
        }

        int searchList(int val)
        {

            if(this->head)
            {
                node* temp = this->head;
                while(temp)
                {
                    if(temp->val == val)
                    {
                        cout<<"Present in the List"<<endl;
                        return 1;
                    }
                    temp = temp->next;
                }
            }
            else
            {
                cout<<"List is empty"<<endl;
            }
            return 0;
        }

        void delNode(int val)
        {
            node* first = this->head;
            node *second;
            if (this->searchList(val))
            {
                if(first->val == val)
                {
                    delete (first);
                    this->head->next = NULL;
                }
                node *second = first->next;
                while(second)
                {
                    if(second->val == val)
                    {
                        first->next = second->next;
                        delete(second);
                        break;
                    }
                    first = second;
                    second = second->next;
                }
                
            }
        }  

};

int main()
{ 
    linkedList* ll = new linkedList();
    for(int i=1;i<=20;i++)
    {
        ll->addNodeHead(i);
    }
    ll->printList();
    ll->addNodeBack(0);
    ll->printList();
    ll->delNode(11);
    ll->printList();
}