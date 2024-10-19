#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect a cycle in the linked list
ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Move slow pointer by one and fast pointer by two
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        // Cycle detected
        if (slow == fast) {
            ListNode* start = head; // Reset start pointer
            // Find the entry point of the cycle
            while (slow != start) {
                slow = slow->next;
                start = start->next;
            }
            return start; // Start of the cycle
        }
    }
    return nullptr; // No cycle found
}

// Function to print the linked list
void PrintNode(ListNode* head) {
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

    vector<int> values(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Create the linked list
    ListNode* head = createList(values);

    // Print the linked list
    cout << "Linked List: ";
    PrintNode(head);

    // Detect cycle (For demonstration, no cycle is created in this code)
    ListNode* cycleNode = detectCycle(head);
    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Clean up memory for the linked list
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
