#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
int val;
ListNode* next;
ListNode (int x):val(x) ,next(NULL){}
};





ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
 
 ListNode* dummy=new ListNode(0);
 ListNode* current=dummy;

 while(l1!=NULL && l2!=NULL){
       if(l1->val<l2->val){
        current->next=l1;
        l1=l1->next;
       }
       else{
         current->next=l2;
         l2=l2->next;
       }
       current=current->next;
 }
  if(l1!=NULL){
   current->next=l1;
  }else if(l2!=NULL){
   current->next=l2;
  }

ListNode* Merge=dummy->next;
delete dummy;
return Merge;

}

void printList(ListNode* head){
    ListNode* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"";
        temp=temp->next;
    }
}



ListNode* createList(const vector<int>& arr){
    if(arr.empty()) return NULL;
    ListNode* head=new ListNode(arr[0]);
    ListNode* current=head;
    for(int i=1; i< arr.size();i++){
        current->next=new ListNode(arr[i]);
        current=current->next;
    }
    return head;
}




int main() {
    // Input for the first sorted linked list
    int n1;
    cout << "Enter the number of elements for the first list: ";
    cin >> n1;
    vector<int> values1(n1);
    cout << "Enter the elements for the first list: ";
    for (int i = 0; i < n1; ++i) {
        cin >> values1[i];
    }
    ListNode* l1 = createList(values1);

    // Input for the second sorted linked list
    int n2;
    cout << "Enter the number of elements for the second list: ";
    cin >> n2;
    vector<int> values2(n2);
    cout << "Enter the elements for the second list: ";
    for (int i = 0; i < n2; ++i) {
        cin >> values2[i];
    }
    ListNode* l2 = createList(values2);

    // Merge the two sorted lists
    ListNode* mergedList = mergeTwoLists(l1, l2);

    // Print the merged list
    cout << "Merged list: ";
    printList(mergedList);

    // Cleanup the linked list memory
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
