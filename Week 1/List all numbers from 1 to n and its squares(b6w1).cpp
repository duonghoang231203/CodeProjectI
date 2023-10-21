#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n; // ??c gi? tr? n t? ngu?i d?ng

    for (int i = 1; i <= n; i++) {
        int square = i * i; // T?nh b?nh phuong c?a s? hi?n t?i
        cout << i << " " << square << endl; // In s? v? b?nh phuong c?a n? c?ch nhau b?i m?t kho?ng tr?ng v? k?t th?c d?ng
    }

    return 0;
}

