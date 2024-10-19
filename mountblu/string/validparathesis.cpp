#include <bits/stdc++.h>
using namespace std;

bool validParenthesis(string str) {
    stack<char> st;  
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
            st.push(str[i]);  
        } else {
            if (st.empty()) {
                return false;  
            }
            if (str[i] == ')' && st.top() == '(') {
                st.pop();  
            } else if (str[i] == '}' && st.top() == '{') {
                st.pop();  
            } else if (str[i] == ']' && st.top() == '[') {
                st.pop();  
            } else {
                return false;  
            }
        }
    }
    return st.empty();  
}

int main() {
    string str;
    cin >> str;  
    bool result = validParenthesis(str);
    cout << (result ? "true" : "false") << " ";
}
