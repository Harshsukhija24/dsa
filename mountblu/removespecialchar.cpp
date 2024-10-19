#include <iostream>
#include <vector>
#include <cctype> // for std::isalnum

bool isSpecialCharacter(char c) {
    return !std::isalnum(c); // Returns true if the character is not alphanumeric
}

std::vector<char> balanceArray(const std::vector<char>& input) {
    std::vector<char> balancedArray;

    for (char c : input) {
        if (!isSpecialCharacter(c)) {
            balancedArray.push_back(c); // Add valid characters to the balanced array
        }
    }

    return balancedArray;
}

int main() {
    std::vector<char> inputArray = {'a', 'b', 'c', '!', '@', '#', '1', '2', '3', '$', '%', '^'};
    
    std::vector<char> balancedArray = balanceArray(inputArray);

    std::cout << "Balanced Array: ";
    for (char c : balancedArray) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
