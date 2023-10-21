//C/C++ 
#include <bits/stdc++.h> 

int main() 
{ 
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 != 0) count1++;
        else count2++;
    }
    std::cout << count1 << " " << count2 << std::endl;
    
    delete[] arr;
    return 0;
}
