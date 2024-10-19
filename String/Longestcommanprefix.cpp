#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if (n == 0)
        return "";

    string ans = "";
    sort(strs.begin(), strs.end());

    string a = strs[0];      
    string b = strs[n - 1];  

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            ans += a[i];
        } else {
            break;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);  

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);

    cout << result << endl;

    return 0;
}
