// #include<iostream>
// using namespace std;

// class stack{
//     private:
//         int *arr;
//         int top;
//         int capasity;
//     public:
//         stack(int size){
//             capasity = size;
//             arr = new int [capasity];
//             top = -1;
//         }
//         ~stack(){delete[] arr;}
//         bool isEmpty(){return top==-1;}
//         bool isFull(){return top==capasity-1;}
//         int size(){return top + 1;}

//         void push(int x){
//             if(isFull()){
//                 cout<<"Stack is Overflow \n";
//                 return;
//             }
//             arr[++top] = x;
//         }
//         void pop(){
//             if(isEmpty()){
//                 cout<<"Stack is underflow \n";
//                 return;
//             }
//             top--;
//         }
//         int peak(){
//             if(isEmpty()){
//                 cout<<"Stack is Empty \n";
//                 return -1;
//             }
//             return arr[top];
//         }
//         void display(){
//             for (int i = top; i >= 0; i--)
//                 cout<<arr[i]<<" ";
//             cout<<endl;
//         }
// };

// int main() {
    
//     stack s1(5);
//     s1.push(10);
//     s1.push(20);
//     s1.push(30);
//     s1.push(40);
//     s1.display();

//     cout <<"Top: "<<s1.peak()<<endl;
//     cout<<"Size: "<<s1.size()<<endl;

//     s1.pop();
//     s1.display();
//     cout<<"Size: "<<s1.size()<<endl;


//     return 0;
    
// }

#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> temp) {
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "\n";
}

int main() {
    
    stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    printStack(s1);
    
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    return 0;

}