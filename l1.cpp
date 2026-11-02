#include<iostream>
using namespace std;

struct Node{
    Node* next;
    int data;
    Node (int val): data(val), next(nullptr){}
};

Node* build(int n){
    if(n<=0) return nullptr;
    int val;
    cout<<"Enter "<<n<<" elements: ";
    cin>>val;
    Node* head = new Node(val);
    Node* tail = head;
    for (int i = 1; i < n; i++)
    {
        cin>>val;
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
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
    int count  = 0;
    for(Node* p = head; p != nullptr; p = p->next) count++;
    return count;
}

Node* InFront(Node* head, int x){
    Node* n  = new Node(x);
    n->next = head;
    return n;
}

Node* InEnd(Node* head, int x){
    Node* n = new Node(x);
    if(head == nullptr) return n;
    Node* p = head;
    while(p->next != nullptr) p = p->next;
    p->next = n;
    return head;
}

Node* delval(Node* head, int x){
    if(head == nullptr) return nullptr;
    if(head->data == x){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    } 
    Node* p = head;
    while(p->next != nullptr && p->next->data != x) p = p->next;
    if(p->next != nullptr){
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
        prev= curr;
        curr = newnode;
    }
    return prev;
}

Node* mergeTwo(Node* a, Node* b) {
    Node dummy(0);
    Node* t = &dummy;
    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            t->next = a;
            a = a->next;
        } else {
            t->next = b;
            b = b->next;
        }
        t = t->next;
    }
    if (a != nullptr) t->next = a;
    else t->next = b;
    return dummy.next;
}

int main() {
    
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    Node* head = build(n);
    display(head);

    cout<<"length of linked list is: "<<length(head)<<endl;

    // cout<<"Enter value to insert in front: ";
    // int x;
    // cin>>x;
    // head = InFront(head,x);
    // cout<<"After inserting "<< x <<" in front: ";
    // display(head);

    // cout<<"Enter value to insert in end: ";
    // int y;
    // cin>>y;
    // head = InEnd(head, y);
    // cout<<"After inserting "<< y <<" in end: ";
    // display(head);

    // cout<<"Enter value to delete: ";
    // int z;
    // cin>>z;
    // head = delval(head, z);
    // cout<<"After deleting "<< z <<" from linked list: ";
    // display(head);

    head = reverse(head);
    cout<<"After reversing linked list: ";
    display(head);

    // Merge two sorted linked lists
    Node* list1 = build(3);
    Node* list2 = build(3);
    cout<<"First list: ";
    display(list1);
    cout<<"Second list: ";
    display(list2);
    Node* merged = mergeTwo(list1, list2);
    cout<<"Merged list: ";
    display(merged);

    return 0;
}