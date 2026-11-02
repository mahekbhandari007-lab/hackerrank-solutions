// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/divide-and-conquer-sort-a-linked-list/problem?isFullScreen=true
// Problem     Divide and Conquer - Sort a Linked List
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-11-02, 12:02 p.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Definition for singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to split the linked list into two halves using slow and fast pointers
void splitList(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    // Advance 'fast' two nodes, and 'slow' one node
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is before the midpoint in the list, split it in two at this point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* a, Node* b) {
    Node* result = nullptr;

    // Base cases
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    // Pick either a or b, and recur
    if (a->data <= b->data) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }
    return result;
}

// Main Merge Sort function for Linked List
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* a;
    Node* b;

    // Base case -- length 0 or 1
    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }

    // Split head into 'a' and 'b' sublists
    splitList(head, &a, &b);

    // Recursively sort the sublists
    mergeSort(&a);
    mergeSort(&b);

    // answer = merge the two sorted lists together
    *headRef = mergeSortedLists(a, b);
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n == 0) {
        cout << "Empty\n";
        return 0;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    // Build the linked list from standard input
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Sort the linked list
    mergeSort(&head);

    // Print the sorted elements
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << (current->next != nullptr ? " " : "");
        Node* temp = current;
        current = current->next;
        delete temp; // Clean up memory to avoid leaks
    }
    cout << "\n";

    return 0;
}
