#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to rearrange the words based on their indices
string rearrangeWords(const string& str) {
    // Split the input string into words
    stringstream ss(str);
    int n =str.size();
    string word;
    vector<string> arrangedWords(n); // Assuming there are at most 6 words (from the given example)

    // Process each word
    while (ss >> word) {
        // Extract index from the word
        int index = 0;
        for (char c : word) {
            if (isdigit(c)) {
                index = c - '0'; // Convert char to int
                break;
            }
        }
        // Store the word in the correct position (0-based index)
        arrangedWords[index - 1] = word; // Place the word at the index-1 position
    }

    // Construct the result string
    string result;
    for (auto& w : arrangedWords) {
        // Only add non-empty words to the result
        if (!w.empty()) {
            // Remove the index from the word for the final output
            w.erase(remove_if(w.begin(), w.end(), ::isdigit), w.end());
            result += (result.empty() ? "" : " ") + w; // Add space before subsequent words
        }
    }
    
    return result;
}

int main() {
    string str;
    getline(cin,str);
    
    string result = rearrangeWords(str);
    cout << result << endl; // Output: "For the love of God"
    
    return 0;
}
