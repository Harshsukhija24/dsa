#include <bits/stdc++.h>
using namespace std;

string Largestoddnumber(string num) {
    int idx = num.size() - 1;
    
    while (idx >= 0) {
        if ((num[idx] - '0') % 2 != 0) 
            break;
        idx--;
    }
    
    if (idx < 0)
        return ""; 
    return num.substr(0, idx + 1); 

int main() {
    int n;
    cin >> n; // Input the length of the string (though not necessary for logic)
    string s;
    cin >> s; // Input the string of digits

    string result = Largestoddnumber(s); // Store result as a string
    if(result == "")
        cout << "No odd number found" << endl; // Handle case with no odd numbers
    else
        cout << result << endl; // Print the largest odd number found

    return 0;
}
