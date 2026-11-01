#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node (int val): data(val), next(nullptr){}
};

Node* build(int n){
    if(n<=0) return nullptr;
    int val;
    cout<<"Enter "<<n<<" elments: ";
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
    for(Node* p = head; p != nullptr; p=p->next) count++;
    return count;
}

Node* InFro(Node* head, int x){
    Node* n = new Node(x);
    n->next=head;
    return n;
}

Node* InEnd(Node* head, int y){
    Node* n = new Node(y);
    if(head==nullptr) return n;
    Node* p = head; 
    while (p->next!=nullptr) p=p->next;
    p->next = n;
    return head;
}

Node* delval(Node* head, int x){
    if(head==nullptr) return nullptr;
    if(head->data==x){
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    Node* p = head;
    while (p->next!=nullptr && p->next->data!=x) p=p->next;
    if (p->next!=nullptr)
    {
        Node* temp = p->next;
        p->next = p->next->next;
        delete temp;
    }
    return head;
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr!=nullptr){
        Node* newnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = newnode;
    }
    return prev;
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    Node* head = build(n);
    display(head);

    cout<<"Length of Linked List is: "<<length(head)<<endl;

    // int x;
    // cout<<"Enter value at front: ";
    // cin>>x;
    // head = InFro(head, x);
    // cout<<"After entering at front: ";
    // display(head);

    // int y;
    // cout<<"Enter value at end: ";
    // cin>>y;
    // head = InEnd(head, y);
    // cout<<"After entering at end: ";
    // display(head);

    // int z;
    // cout<<"Enter value at for deleting: ";
    // cin>>z;
    // head = delval(head, z);
    // cout<<"After Deleting the value: ";
    // display(head);

    // head = reverse(head);
    // cout<<"After Reversing the list: ";
    // display(head);

    cout<<"Mid elemnt of the list is: "<<findMid(head)->data<<endl;

    return 0;
    
}