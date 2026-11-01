#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr){}
};

Node* build(int n){
    if(n<=0) return nullptr;
    int val;
    cout<<"Enter "<<n<<" values: ";
    cin>>val;
    Node* head = new Node(val);
    Node* tail = head;
    for (int i = 1; i < n; i++)
    {
        cin>>val;
        Node* newnode = new Node(val);
        tail->next = newnode;
        tail = newnode;
    }
    return head;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}

int length(Node* head){
    int count = 0;
    for (Node* i = head; i != nullptr; i=i->next) count++;
    return count;
}

int main() {
    
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    Node* head = build(n);
    display(head);
    cout<<"The Length of Linked List: "<<length(head)<<endl;;
    
    return 0;
    
}