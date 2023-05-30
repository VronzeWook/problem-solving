#include<bits/stdc++.h>
using namespace std;

string s;
stack<char> stk;
const string cmp = "()[]";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, s);
	while (s.size() != 1 && s[0] != '.') {
		for (int i = 0; i < s.size(); i++) {
			//스택이 비어있고 괄호일 경우
			if (stk.empty() && cmp.find(s[i]) != string::npos) stk.push(s[i]);
			//이외 괄호일 경우
			else if(cmp.find(s[i]) != string::npos) {
				//스택 top과 괄호가 매치하면 pop()
				if (stk.top() == '(' && s[i] == ')') stk.pop();
				else if (stk.top() == '[' && s[i] == ']') stk.pop();
				//이외 스택 push
				else stk.push(s[i]);
			}
		}

		if (stk.empty()) cout << "yes\n";
		else cout << "no\n";

		while (!stk.empty()) stk.pop();

		getline(cin, s);
	}

	return 0;
}