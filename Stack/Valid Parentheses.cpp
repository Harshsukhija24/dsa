#include <bits/stdc++.h>
using namespace std;

bool valid(string x) {
    stack<char> stk; 
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '{' || x[i] == '[' || x[i] == '(') {
            stk.push(x[i]);
        } else {
            if (stk.empty()) {
                return false;
            }
            if (x[i] == ')' && stk.top() == '(') {
                stk.pop();
            } else if (x[i] == '}' && stk.top() == '{') {
                stk.pop();
            } else if (x[i] == ']' && stk.top() == '[') {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    string s;
    cin >> s;

    if (valid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }

    return 0;
}


