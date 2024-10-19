#include <bits/stdc++.h>
using namespace std;

// Definition of the ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect if there is a cycle in the linked list
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move slow pointer by one
        fast = fast->next->next;   // Move fast pointer by two
        if (slow == fast) {        // Cycle detected
            return true;
        }
    }
    return false;  // No cycle found
}

// Function to print the linked list
void Print(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to create a linked list from a vector of integers
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

    vector<int> value(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    // Create the linked list
    ListNode* head = createList(value);

    // Print the linked list
    cout << "Linked List: ";
    Print(head);

    // Check for cycle
    if (hasCycle(head)) {
        cout << "Yes, the linked list has a cycle." << endl;
    } else {
        cout << "No, the linked list does not have a cycle." << endl;
    }

    // Clean up memory for the linked list
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
