#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middle(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;  // Corrected: Added missing semicolon and newline for better output formatting
}

// Function to create a linked list from a vector
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); i++) {  // Corrected: Loop starting from 1 to avoid duplicate first element
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    ListNode* head = createList(values);

    cout << "Linked List: ";
    printList(head);

    ListNode* findmiddle = middle(head);
    cout << "Middle Element: " << findmiddle->val << endl;

    return 0;
}
