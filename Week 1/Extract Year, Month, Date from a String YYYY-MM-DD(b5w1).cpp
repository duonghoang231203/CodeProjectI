#include<iostream>
#include<string>
using namespace std;
int main() 
{ 
    string a;
	int count = 0;
	getline(cin, a);
	for (int i = 0 ; i < 4; i++){
		if (a[i] > '9' || a[i] < '0') {
			count ++;		
			}
	}
	if (a[4] != '-'){
		count ++;
	}
	else a[4] = ' ';
	if (a[5] == '0'){
		if (a[6] > '9' || a[6] < '1'){
			count ++;
		}
	}
	else if (a[5] == '1'){
		if (a[6] < '0'|| a[6] > '2'){
			count ++;
		}
	}
	else {
		count ++;
	}
	if (a[7] != '-'){
		count ++;
	}
	else a[7] = ' ';
	if (a[8] == '0'){
		if (a[9] > '9' || a[9] < '1'){
			count ++;
		}
		else a.erase(a.begin()+8);
	}
	else if (a[8] == '1' || a[8] == '2'){
		if (a[9] > '9' || a[9] < '0'){
			count ++;
		}
	}
	else if (a[8] == '3'){
		if (a[9] != '0' && a[9] != '1'){
			count ++;
		}
	}
	else {
		count ++;
	}
	if (count == 0){
		if (a[5] == '0'){
			a.erase(a.begin()+5);
		}
			for(int i = 0; i < a.length(); i++){
				cout << a[i];
			}
	}
	else cout << "INCORRECT";
}

