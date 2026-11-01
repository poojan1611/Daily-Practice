#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Function to build linked list
Node* buildLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }

    int value;
    cout << "Enter " << n << " elements: ";

    cin >> value;

    Node* head = new Node(value);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> value;

        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

// Function to display linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Main function
int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = buildLinkedList(n);

    cout << "Linked List: ";
    display(head);

    return 0;
}