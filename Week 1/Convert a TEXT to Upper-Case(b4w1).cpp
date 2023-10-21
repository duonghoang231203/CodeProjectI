#include <iostream>
#include <string>

int main() {
    std::string inputText, uppercaseText;
    
    int emptyLineCount = 0; // Keep track of consecutive empty lines

    while (true) {
        std::getline(std::cin, inputText);

        if (inputText.empty()) {
            emptyLineCount++;
        } else {
            emptyLineCount = 0; // Reset the count if a non-empty line is encountered
        }

        if (emptyLineCount >= 3) {
            break; // Exit the loop when two consecutive empty lines are encountered
        }

        for (int i = 0; i < inputText.length(); i++) {
            uppercaseText += std::toupper(inputText[i]);
        }

        uppercaseText += '\n';
    }

    std::cout << uppercaseText;

    return 0;
}

