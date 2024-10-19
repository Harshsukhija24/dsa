#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect and remove the loop in the linked list
ListNode* detectAndRemoveLoop(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected
            break;
        }
    }

    // If no loop is found, return the head as it is
    if (slow != fast) return head;

    // Step 2: Find the starting point of the loop
    slow = head;
    if (slow != fast) {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    } else {
        // If the loop starts at the head
        while (fast->next != slow) {
            fast = fast->next;
        }
    }

    // Step 3: Remove the loop by setting the next of the last node to NULL
    fast->next = NULL;

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example linked list with a loop
    vector<int> values = {1, 2, 3, 4, 5};

    // Creating the linked list
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    ListNode* loopNode = nullptr;

    for (int i = 1; i < values.size(); ++i) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
        if (i == 2) {  // Let's assume the loop starts at the node with value 3
            loopNode = temp;
        }
    }

    // Creating a loop in the list
    temp->next = loopNode;

    // Detect and remove the loop
    head = detectAndRemoveLoop(head);

    // Print the list after removing the loop
    cout << "Modified list: ";
    printList(head);

    return 0;
}
