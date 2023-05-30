#include<bits/stdc++.h>
using namespace std;

int n, cnt; 
stack<char> stk;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (!stk.empty() && stk.top() == s[j]) stk.pop();
			else stk.push(s[j]);
		}
		if (stk.empty()) cnt++;
		
		while (!stk.empty()) stk.pop();
	}
	cout << cnt << "\n";
	return 0;
}