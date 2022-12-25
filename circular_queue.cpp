#include<bits/stdc++.h>
using namespace std;


class MyCircularQueue
{
       int *arr;
       int front;
       int rear;
       int size;

public:
       MyCircularQueue(int k)
       {
              arr = new int[k];
              front = -1;
              rear = -1;
              size = k;
       }

       bool enQueue(int value)
       {
              if (isFull())
              {
                     return false;
              }
              else if (isEmpty())
              {
                     front = 0;
              }

              rear = (rear + 1) % size;
              arr[rear] = value;

              return true;
       }

       bool deQueue()
       {
              if (isEmpty())
              {
                     return false;
              }

              // Circular Queue will be empty after this deletion.
              if (front == rear)
              {
                     front = -1;
                     rear = -1;
              }
              else
              {
                     front = (front + 1) % size;
              }

              return true;
       }

       int Front()
       {
              if (isEmpty())
              {
                     return -1;
              }

              return arr[front];
       }

       int Rear()
       {
              if (isEmpty())
              {
                     return -1;
              }

              return arr[rear];
       }

       bool isEmpty()
       {
              return (front == -1 && rear == -1);
       }

       bool isFull()
       {
              return (((rear + 1) % size) == front);
       }
};

int main(){
       MyCircularQueue q(4);
       q.enQueue(5);
       q.enQueue(10);
       cout<<q.Front()<<endl;;
       q.deQueue();
       cout<<q.Front()<<endl;
       return 0;
}