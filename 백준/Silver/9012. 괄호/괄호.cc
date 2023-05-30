#include<bits/stdc++.h>
using namespace std;

int ps_cnt, T, f;
string s;
int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		ps_cnt = 0, f = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') ps_cnt++;
			else ps_cnt--;

			if (ps_cnt < 0) {
				cout << "NO\n";
				f = 1;
				break;
			}
		}
		if (f != 1) {
			if (ps_cnt == 0) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}