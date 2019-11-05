#include<iostream>
#define MAX 5
using namespace std;

class circularQueue
{
    private:
        int queue[MAX];
        int front = -1;
        int rear = -1;
    
    public:
        void enqueue(int val)
        {
            int index;
            index = (this->rear+1)%MAX;
            if(front != index)
            {
                if (this->front == -1)
                    this->front = 0;
                this->queue[index] = val;
                this->rear = index;
            }
            else
            {
                cout<<"Queue is Full"<<endl;
            }
             
        }

        int dequeue()
        {
            int index, val;
            index = this->front;
            if(index == this->rear)
            {
                this->front = -1;
                this->rear = -1;
                val = this->queue[index];
            }
            else
            {
                val = this->queue[index];
                this->front = (this->front+1)%MAX;
            }
            return val;   
        }

        int top()
        {
            if(this->rear != -1)
            {
                return this->queue[this->front];
            }
            else
            {
                cout<<"Empty Queue";
            }

            return -1;
        }

        int size()
        {
            if(rear >= front)
            {
                return rear-front;
            }
            else
            {
                return MAX-front+rear;
            }
            
        }

        void printQueue()
        {
            int i = front;
            while(i != rear) 
            {
                cout<<queue[i]<<" ";
                i = (i+1)%MAX;
            } 
            cout<<queue[i]<<" ";
            cout<<endl;
        }

};

int main()
{
    circularQueue* q = new circularQueue();
    q->enqueue(10);
    q->enqueue(10);
    q->enqueue(10);
    q->enqueue(10);
    q->enqueue(10);
    q->dequeue();
    q->enqueue(20);
    q->printQueue();
    q->enqueue(20);

    return 0;
}