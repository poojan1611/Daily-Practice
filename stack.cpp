#include<iostream>
using namespace std;

class stack{
    private:
        int *arr;
        int top;
        int capacity;
    public:
        stack(int size){
            capacity = size;
            arr = new int[capacity];
            top = -1;
        }
        ~stack(){delete[] arr;}
        bool isEmpty() {return top == -1;}
        bool isFull() { return top == capacity-1;}
        int size() { return top + 1; }

        void push(int x){
            if(isFull()){
                cout<<"Stack is Overflow \n";
                return;
            }
            arr[++top] = x;
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack is Underflow\n";
                return;
            }
            top--;
        }

        int peak(){
            if (isEmpty()){
                cout <<"Stack is Empty \n";
                return -1;
            }
            return arr[top];
        }

        void display(){
            for(int i = top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout <<endl;
        }

};


int main() {
    
    stack s(5);
    s.push(5);
    s.push(3);
    s.push(6);

    s.display();
    cout<<"Top : "<<s.peak()<<endl;

    s.pop();
    cout<<"Top after pop: "<<s.peak()<<endl;
    cout<<s.size()<<endl;

    s.display();

    return 0;
    
}