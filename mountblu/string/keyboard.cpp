#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string convertToKeypadSequence(const string& sentence) {
    // Create a mapping of characters to their corresponding keypad digits
    unordered_map<char, string> keypadMapping = {
        {'A', "2"}, {'B', "22"}, {'C', "2"},
        {'D', "3"}, {'E', "3"}, {'F', "3"},
        {'G', "4"}, {'H', "4"}, {'I', "4"},
        {'J', "5"}, {'K', "5"}, {'L', "5"},
        {'M', "6"}, {'N', "6"}, {'O', "6"},
        {'P', "7"}, {'Q', "7"}, {'R', "7"}, {'S', "7"},
        {'T', "8"}, {'U', "8"}, {'V', "8"},
        {'W', "9"}, {'X', "9"}, {'Y', "9"}, {'Z', "9"}
    };

    string keypadSequence = "";

    for (char ch : sentence) {
        if (isalpha(ch)) {  // Check if the character is an alphabet
            ch = toupper(ch);  // Convert to uppercase to standardize mapping
            keypadSequence += keypadMapping[ch];  // Append corresponding digit
        } else if (ch == ' ') {
            keypadSequence += " ";  // Keep spaces in the output
        }
    }

    return keypadSequence;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string result = convertToKeypadSequence(sentence);
    cout << "Keypad sequence: " << result << endl;

    return 0;
}
