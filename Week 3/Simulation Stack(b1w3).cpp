#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
	string s;
	stack<int> st;
	while(true){
		cin >> s;
		if (s == "#") break;
		else if (s == "PUSH"){
			int n;
			cin >> n;
			st.push(n);
		}
		else if (s == "POP"){
			if (!st.empty()){
				cout << st.top() << endl;
				st.pop();
			}
			else {
				cout << "NULL" << endl;
			}
		}
	}

	return 0;
}
