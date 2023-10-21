#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int countWords(string text) {
    stringstream ss(text);
    string word;
    int wordCount = 0;
    
    while (ss >> word) {
        wordCount++;
    }
    
    return wordCount;
}

int main() {
    string text;
    string line;
    int emptyLineCount = 0;

    while (getline(cin, line)) {
        if (line.empty()) {
            emptyLineCount++;
            if (emptyLineCount > 7) {
                break;
            }
        } else {
            text += line + ' ';
        }
    }

    int wordCount = countWords(text);

    cout << wordCount << endl;

    return 0;
}

