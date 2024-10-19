#include <bits/stdc++.h>
using namespace std;

void generatesub(string s, string current, int index, vector<string> &result) {
    if (index == s.length()) {
        result.push_back(current); 
        return;
    }

    generatesub(s, current, index + 1, result);

    generatesub(s, current + s[index], index + 1, result);
}

vector<string> allsubsequence(string s) {
    vector<string> result;
    generatesub(s, "", 0, result);
    return result;
}

int main() {
    int n;
    cout << "Enter the length of the string: ";
    cin >> n;

    string str;
    cout << "Enter the string: ";
    cin >> str;

    vector<string> subsequences = allsubsequence(str);

    cout << "All subsequences of the string are:\n";
    for (const string &subseq : subsequences) {
        cout << "\"" << subseq << "\"\n";
    }

    return 0;
}
