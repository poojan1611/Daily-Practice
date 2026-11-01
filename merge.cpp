#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* mergeTwo(Node* a, Node* b) {
    Node dummy(0);
    Node* t = &dummy;
    while (a != nullptr && b != nullptr) {
        if (a->val <= b->val) {
            t->next = a;
            a = a->next;
        }
        else {
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

    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insertEnd(list1, 1);
    insertEnd(list1, 3);
    insertEnd(list1, 5);
    insertEnd(list1, 7);

    insertEnd(list2, 2);
    insertEnd(list2, 4);
    insertEnd(list2, 6);
    insertEnd(list2, 8);

    cout << "List 1: ";
    display(list1);

    cout << "List 2: ";
    display(list2);

    Node* merged = mergeTwo(list1, list2);

    cout << "Merged List: ";
    display(merged);

    return 0;
}