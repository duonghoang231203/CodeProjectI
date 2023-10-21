#include <iostream>
#include <string>

void generateBinarySequences(int n, std::string prefix = "") {
    if (n == 0) {
        std::cout << prefix << std::endl;
    } else {
        generateBinarySequences(n - 1, prefix + "0");
        generateBinarySequences(n - 1, prefix + "1");
    }
}

int main() {
    int n;
    std::cin >> n;

    generateBinarySequences(n);

    return 0;
}

