#include <iostream>
#include <vector>
using namespace std;

void reverseastring(vector<string>& str) {
    int start = 0;
    int end = str.size() - 1;
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> str(n); // Using vector for dynamic sizing
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    reverseastring(str);
    
  for(int i =0;i<n;i++){
    cout<<str[i];
  }
    
    return 0;
}
