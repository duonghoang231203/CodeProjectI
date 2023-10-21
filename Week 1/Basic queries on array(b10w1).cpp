//C/C++ 
#include <bits/stdc++.h> 
#include <iomanip>

using namespace std;
 
int main()
{
 
    float a, b, c, delta, x1, x2;
    cin >> a >> b >> c;
    if(a == 0) {
        if(b == 0) {
            cout << "NO SOLUTION" << endl;
        } else {
            cout << "Phuong trinh co nghiem duy nhat: " << -c/b << endl;
        }
    } else {
        delta = b*b - 4*a*c;
        if(delta > 0) {
            x1 = (-b-sqrt(delta))/(2*a);
            x2 = (-b+sqrt(delta))/(2*a);
            cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
        } else if ( delta == 0) {
            cout << fixed << setprecision(2) << -b/2*a << endl;
        } else {
            cout << "NO SOLUTION" << endl;
        }
    }
    return 0;
}
