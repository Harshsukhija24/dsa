#include <iostream>
#include <sstream>  // for stringstream to split the string
#include <unordered_set>  // for using a set
using namespace std;

string firstRepeatedWord(string str) {
    unordered_set<string> wordSet;  // Set to track words
    string word;
    stringstream ss(str);  // String stream to split the string into words

    // Traverse through each word in the string
    while (ss >> word) {
        // Check if the word is already in the set
        if (wordSet.find(word) != wordSet.end()) {
            return word;  // First repeated word found
        }
        // Insert the word into the set
        wordSet.insert(word);
    }

    // If no word is repeated, return an empty message
    return "No repeated word found";
}

int main() {
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);  // Read entire line as input
    
    string result = firstRepeatedWord(str);
    if(result != "No repeated word found") {
        cout << "The first repeated word is: " << result << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
