#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long evenCount = 0, oddCount = 0;
    long long result = 0;
    
    for (int i = 0; i < k; i++) {
        if (a[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    
    if (evenCount % 2 == 0) {
        result++;
    }
    
    for (int i = k; i < n; i++) {
        if (a[i - k] % 2 == 0) {
            evenCount--;
        } else {
            oddCount--;
        }
        
        if (a[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
        
        if (evenCount % 2 == 0) {
            result++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}

