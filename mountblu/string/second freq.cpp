#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void secondHighestFrequency(string s) {
    // Step 1: Count the frequency of each character
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    // Step 2: Find the highest and second highest frequency
    int highest = 0, secondHighest = 0;
    char highestChar = ' ', secondHighestChar = '\0';
    
    for (auto it : freq) {
        if (it.second > highest) {
            secondHighest = highest;            // Update second highest frequency
            secondHighestChar = highestChar;    // Update the character with second highest frequency
            highest = it.second;                // Update highest frequency
            highestChar = it.first;             // Update the character with highest frequency
        } else if (it.second > secondHighest && it.second < highest) {
            secondHighest = it.second;          // Update second highest frequency
            secondHighestChar = it.first;       // Update the character with second highest frequency
        }
    }
    
    // Step 3: Print the second highest frequency character and its count
    cout << secondHighestChar << " " << secondHighest << endl;
}

int main() {
    string s = "abccaddbbbbbbdcaasdd";
    secondHighestFrequency(s);
    
    return 0;
}
