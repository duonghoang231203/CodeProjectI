#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int> seen;//su dung de kiem tra su trung lap trong mang
    for (int i = 0; i < n; i++) {
        if (seen.count(a[i]) > 0) {//neu count > 0 thi in ra 1
            cout << "1" << endl;
        } else {
            seen.insert(a[i]);//neu a[i] chua ton tai trong seen, ta them no vao 'seen' su dung .insert(a[i]) in ra 0 de chi ra rang gtri nay chua tung xuat hien
            cout << "0" << endl;
        }
    }

    return 0;
}

