#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr){}
};

class stack{
    private:
        Node* top;
        int count;
    public:
         stack(): top(nullptr), count(0) {}
         ~stack(){
            while(top) pop();
         }
         bool isEmpty(){return top == nullptr;}
         int size(){return count;}

         void push(int x){
            Node* n = new Node(x);
            n->next = top;
            top = n;
            count++;
         }

         void pop(){
            if (isEmpty()) {
                cout << "Stack Underflow\n";
                return;
            }
            Node* t = top;
            top = top->next;
            delete t;
            count--;
         }
        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return -1;
            }
            return top->data;
        }
        void display(){
            Node* temp = top;
            while (temp!=nullptr)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout <<"Null"<<endl;
        }
        void reverse(){
            stack temp;
            for(Node* cur = top;cur; cur = cur->next)
                temp.push(cur->data);
            temp.display();
        }
};



int main() {
    
    stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout<<s1.peek()<<endl;    
    cout<<s1.size()<<endl;
    s1.display();
    s1.reverse();

    s1.pop();

    cout<<s1.peek()<<endl;    
    cout<<s1.size()<<endl;
    
    s1.display();

    return 0;
    
}