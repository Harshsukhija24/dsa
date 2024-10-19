#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to delete a node in the linked list.
void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        // Cannot delete a NULL node or the tail node
        return;
    }
    node->val = node->next->val; 
    node->next = node->next->next;
}

// Function to print the linked list.
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to create a linked list from a vector of integers.
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create linked list
    ListNode* head = createList(arr);

    // Print original list
    cout << "Original List: ";
    printList(head);

    // Ask user for the index of the node to delete
    int index;
    cout << "Enter the index of the node to delete (0-based index): ";
    cin >> index;

    // Check if the index is valid
    if (index < 0 || index >= n) {
        cout << "Invalid index. Cannot delete the node." << endl;
    } else {
        // Special case for deleting the head node
        if (index == 0) {
            ListNode* temp = head;
            head = head->next; // Update head to the next node
            delete temp; // Free the memory for the deleted node
        } else {
            // Traverse to the node before the one to delete
            ListNode* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next; // Move to the node before the one to delete
            }
            // Use the deleteNode function to delete the specified node
            ListNode* nodeToDelete = current->next;
            deleteNode(nodeToDelete); // Call the deleteNode function
        }

        cout << "List after deletion: ";
        printList(head);
    }

   

    return 0;
}
