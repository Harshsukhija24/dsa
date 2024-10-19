#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getLength(ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // Get the lengths of both linked lists
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Align the starting points of both lists
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    // Traverse both lists in sync to find the intersection point
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA; // Intersection point found
        }
        headA = headA->next;
        headB = headB->next;
    }

    return NULL; // No intersection point
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating first linked list
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    headA->next->next->next = new ListNode(2);
    headA->next->next->next->next = new ListNode(4);

    // Creating second linked list
    ListNode* headB = new ListNode(3);
    headB->next = new ListNode(2);

    // Creating intersection
    headB->next->next = headA->next->next->next; // Both lists now intersect at node with value 2

    // Printing both lists
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    // Finding intersection point
    ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection != NULL) {
        cout << "The intersection point value is: " << intersection->val << endl;
    } else {
        cout << "No intersection point found." << endl;
    }

    return 0;
}
