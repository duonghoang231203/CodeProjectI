#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> seen;//noi luu tru cac gia tri da xem xet
    int count = 0;
    for (int i = 0; i < n; i++) {
        int complement = M - a[i];
        if (seen.find(complement) != seen.end()) {//kiem tra complement co ton tai trong seen ko, neu co thi gia tri se khac seen.end() va count++
            count++;
        }
        seen[a[i]] = i;//luu tru chi muc cua so a[i] trong seen, de co the tim thay no trong lan kiem tra khac
    }

    cout << count << endl;

    return 0;
}

