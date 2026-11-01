#include<iostream>
using namespace std;

class Queue{
    private:
        int* arr;
        int front, rear, capacity;
    public:
        Queue(int size){
            capacity = size;
            arr = new int [capacity];
            front = 0;
            rear = -1;
        }
        ~Queue(){delete[] arr;}

        bool isEmpty(){return front>rear;}
        bool isFull(){return rear ==capacity-1;}
        int size(){return isEmpty()?0: rear - front + 1;}

        void enqueue(int x){
            if(isFull()){
                cout<<"Queue is Overflow \n";
                return;
            }
            arr[++rear] = x;
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is underflow \n";
                return;
            }
            front++;
        }

        int peak(){
            if(isEmpty()){
                cout<<"Queue is Empty \n";
                return -1;
            }
            return arr[front];
        }

        void display(){
            if(isEmpty()){
                cout<<"Queue is Empty \n";
                return;
            }
            for (int i =  front; i <= rear; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
};

int main() {
    
    Queue q1(5);
    return 0;
    
}