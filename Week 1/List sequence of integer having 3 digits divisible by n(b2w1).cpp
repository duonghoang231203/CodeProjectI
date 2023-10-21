//CPP 
#include <bits/stdc++.h> 

int main() 
{ 
    int n;
    std::cin >> n;

    for (int i = 100; i <= 999; i++) {
        if(i % n == 0) std::cout << i << std::endl;
    }

    

    return 0;
}

