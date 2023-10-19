#include <iostream>
#include <iomanip>
using namespace std;

int giadienhientai(int i){
    if(i <= 50) return i * 1728;
    else if(i <= 100) return 50 * 1728 + (i - 50) * 1786;
    else if(i <= 200) return 50 * 1728 + 50 * 1786 + (i - 100) * 2074;
    else if(i <= 300) return 50 * 1728 + 50 * 1786 + 100 * 2074 + (i - 200) * 2612;
    else if(i <= 400) return 50 * 1728 + 50 * 1786 + 100 * 2074 + 100 * 2612 + (i - 300) * 2919;
    else return 50 * 1728 + 50 * 1786 + 100 * 2074 + 100 * 2612 + 100 * 2919 + (i - 400) * 3015;
}

int giadiendexuat(int i){
    if(i <= 100) return i * 1728;
    else if(i <= 200) return 100 * 1728 + (i - 100) * 2074;
    else if(i <= 400) return 100 * 1728 + 100 * 2074 + (i - 200) * 2612;
    else if(i <= 700) return 100 * 1728 + 100 * 2074 + 200 * 2612 + (i - 400) * 3111;
    else return 100 * 1728 + 100 * 2074 + 200 * 2612 + 300 * 3111 + (i - 700) * 3457;
}

int main() 
{ 
    int i;
    cin >> i;
    cout << fixed << setprecision(2) << (giadiendexuat(i) - giadienhientai(i))*1.1 << endl;
    return 0;
}

