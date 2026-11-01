#include <iostream>
using namespace std;

// ============================================================
// 1. THE NODE: one box = a value + an arrow to the next box
// ============================================================
struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

// ============================================================
// 2. BASICS: build, print, length, insert, delete
// ============================================================

// Build a linked list from an array. Returns the head (first box).
Node* build(int a[], int n) {
    Node dummy(0);              // temporary box in front, makes life easy
    Node* tail = &dummy;
    for (int i = 0; i < n; i++) {
        tail->next = new Node(a[i]);   // create new box, attach at the end
        tail = tail->next;             // move tail to the new box
    }
    return dummy.next;                 // real head is after the dummy
}

// Print the list like: 1 -> 2 -> 3 -> NULL
void print(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        cout << p->val << " -> ";
        p = p->next;                   // walk forward
    }
    cout << "NULL\n";
}

// Count the nodes
int length(Node* head) {
    int n = 0;
    for (Node* p = head; p != nullptr; p = p->next) n++;
    return n;
}

// Insert at the front. Returns the new head.
Node* insertFront(Node* head, int x) {
    Node* n = new Node(x);
    n->next = head;
    return n;
}

// Insert at the end. Returns the head.
Node* insertEnd(Node* head, int x) {
    Node* n = new Node(x);
    if (head == nullptr) return n;
    Node* p = head;
    while (p->next != nullptr) p = p->next;
    p->next = n;
    return head;
}

// Delete the first node having value x. Returns the head.
Node* deleteVal(Node* head, int x) {
    Node dummy(0);
    dummy.next = head;
    Node* prev = &dummy;
    while (prev->next != nullptr) {
        if (prev->next->val == x) {
            prev->next = prev->next->next;   // skip over that node
            break;
        }
        prev = prev->next;
    }
    return dummy.next;
}

// ============================================================
// 3. REVERSE (the most important function)
// ============================================================
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nxt = curr->next;   // 1. save next
        curr->next = prev;        // 2. flip arrow backwards
        prev = curr;              // 3. move prev forward
        curr = nxt;               // 4. move curr forward
    }
    return prev;                  // prev is the new head
}

// ============================================================
// 4. MIDDLE NODE (slow and fast pointers)
// ============================================================
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// ============================================================
// 5. REVERSE-BASED QUESTIONS
// ============================================================

// 5a. Palindrome check: reverse second half, compare, then restore.
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;
    Node* mid = findMiddle(head);
    Node* second = reverse(mid);      // reversed second half
    Node* p1 = head;
    Node* p2 = second;
    bool ok = true;
    while (p2 != nullptr) {
        if (p1->val != p2->val) {
            ok = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    reverse(second);                  // put the list back as it was
    return ok;
}

// 5b. Reverse nodes from position m to n (1-indexed).
Node* reverseBetween(Node* head, int m, int n) {
    if (head == nullptr || m == n) return head;
    Node dummy(0);
    dummy.next = head;
    Node* pre = &dummy;
    for (int i = 1; i < m; i++) pre = pre->next;   // node just before position m
    Node* curr = pre->next;                        // first node of the segment
    for (int i = 0; i < n - m; i++) {
        Node* t = curr->next;          // node to move to the front of the segment
        curr->next = t->next;
        t->next = pre->next;
        pre->next = t;
    }
    return dummy.next;
}

// 5c. Reverse in groups of k. Leftover (< k nodes) stays as it is.
Node* reverseKGroup(Node* head, int k) {
    Node* node = head;
    for (int i = 0; i < k; i++) {          // check that k nodes exist
        if (node == nullptr) return head;
        node = node->next;
    }
    Node* prev = nullptr;
    Node* curr = head;
    for (int i = 0; i < k; i++) {          // reverse exactly k nodes
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head->next = reverseKGroup(curr, k);   // old head is now the tail of this group
    return prev;                           // prev is the new head of this group
}

// 5d. Swap nodes in pairs (this is just k = 2)
Node* swapPairs(Node* head) {
    return reverseKGroup(head, 2);
}

// 5e. Reorder list: 1,2,3,4,5 -> 1,5,2,4,3
void reorderList(Node* head) {
    if (head == nullptr || head->next == nullptr) return;
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = reverse(slow->next);   // reverse the second half
    slow->next = nullptr;                 // cut the list into two
    Node* first = head;
    while (second != nullptr) {           // weave them together
        Node* t1 = first->next;
        Node* t2 = second->next;
        first->next = second;
        second->next = t1;
        first = t1;
        second = t2;
    }
}

// 5f. Add 1 to a number stored as a list: 9->9->9 becomes 1->0->0->0
Node* addOne(Node* head) {
    if (head == nullptr) return new Node(1);
    head = reverse(head);                 // now the last digit is first
    Node* p = head;
    Node* last = nullptr;
    int carry = 1;
    while (p != nullptr && carry != 0) {
        int s = p->val + carry;
        p->val = s % 10;
        carry = s / 10;
        last = p;
        p = p->next;
    }
    if (carry != 0) last->next = new Node(carry);   // extra digit at the front
    return reverse(head);                 // reverse back
}

// 5g. Rotate right by k places: 1,2,3,4,5 with k=2 -> 4,5,1,2,3
Node* rotateRight(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) return head;
    int n = 1;
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        n++;
    }
    k = k % n;
    if (k == 0) return head;
    tail->next = head;                    // make it a circle
    Node* newTail = head;
    for (int i = 0; i < n - k - 1; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;              // break the circle
    return newHead;
}

// 5h. Merge two SORTED lists
Node* mergeTwo(Node* a, Node* b) {
    Node dummy(0);
    Node* t = &dummy;
    while (a != nullptr && b != nullptr) {
        if (a->val <= b->val) {
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

// ============================================================
// MAIN: shows how to create and use everything
// ============================================================
int main() {
    // ---- How to make a linked list: put values in an array, call build ----
    int a[] = {1, 2, 3, 4, 5};
    Node* head = build(a, 5);              // 5 = number of elements

    cout << "Original list      : ";
    print(head);
    cout << "Length             : " << length(head) << "\n\n";

    // ---- Insert and delete ----
    head = insertFront(head, 0);
    cout << "After insertFront 0: ";
    print(head);
    head = insertEnd(head, 6);
    cout << "After insertEnd 6  : ";
    print(head);
    head = deleteVal(head, 3);
    cout << "After deleteVal 3  : ";
    print(head);
    cout << "\n";

    // ---- Reverse ----
    int b[] = {1, 2, 3, 4, 5};
    Node* h = build(b, 5);
    h = reverse(h);
    cout << "Reversed           : ";
    print(h);

    // ---- Middle ----
    h = build(b, 5);
    cout << "Middle value       : " << findMiddle(h)->val << "\n";

    // ---- Palindrome ----
    int p1[] = {1, 2, 3, 2, 1};
    int p2[] = {1, 2, 3, 4, 5};
    cout << "1 2 3 2 1 palindrome? " << (isPalindrome(build(p1, 5)) ? "yes" : "no") << "\n";
    cout << "1 2 3 4 5 palindrome? " << (isPalindrome(build(p2, 5)) ? "yes" : "no") << "\n\n";

    // ---- Reverse between positions 2 and 4 ----
    h = build(b, 5);
    h = reverseBetween(h, 2, 4);
    cout << "Reverse between 2,4: ";
    print(h);

    // ---- Reverse in groups of k ----
    int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
    h = build(c, 8);
    h = reverseKGroup(h, 3);
    cout << "K-group (k=3)      : ";
    print(h);

    // ---- Swap pairs ----
    h = build(b, 5);
    h = swapPairs(h);
    cout << "Swap pairs         : ";
    print(h);

    // ---- Reorder list ----
    h = build(b, 5);
    reorderList(h);                        // head does not change, so no assignment
    cout << "Reorder list       : ";
    print(h);

    // ---- Add one ----
    int d[] = {9, 9, 9};
    h = build(d, 3);
    h = addOne(h);
    cout << "999 + 1            : ";
    print(h);

    // ---- Rotate right by 2 ----
    h = build(b, 5);
    h = rotateRight(h, 2);
    cout << "Rotate right by 2  : ";
    print(h);

    // ---- Merge two sorted lists ----
    int e1[] = {1, 3, 5};
    int e2[] = {2, 4, 6};
    h = mergeTwo(build(e1, 3), build(e2, 3));
    cout << "Merge sorted lists : ";
    print(h);

    return 0;
}

/*
 ------------------------------------------------------------
 IF THE EXAM GIVES INPUT FROM THE KEYBOARD, use this main:

 int main() {
     int n;
     cin >> n;                 // first number: how many nodes
     int a[100];               // use a size from the problem limits
     for (int i = 0; i < n; i++) cin >> a[i];

     Node* head = build(a, n);
     head = reverse(head);     // call the function the question asks for
     print(head);
     return 0;
 }

 Sample input:   5
                 1 2 3 4 5
 Sample output:  5 -> 4 -> 3 -> 2 -> 1 -> NULL
 ------------------------------------------------------------
*/