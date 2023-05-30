#include<bits/stdc++.h>
using namespace std;

int ps_cnt, T, f;
string s, ps = "()[]";

bool is_vps(string a) {
	stack<char> stk;
	for (int i = 0; i < a.size(); i++) {
		if (ps.find(a[i]) != string::npos) {
			if (a[i] == '(' || a[i] == '[') stk.push(a[i]);
			else if (!stk.empty() && a[i] == ')' && stk.top() == '(') stk.pop();
			else if (!stk.empty() && a[i] == ']' && stk.top() == '[') stk.pop();
			else return false;
		}
	}
	if (stk.empty()) return true;
	else return false;
}

int main(){

	getline(cin, s);
	while (s != ".") {
		if (is_vps(s)) cout << "yes\n";
		else cout << "no\n";
		getline(cin, s);
	}

	return 0;
}