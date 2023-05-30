#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin >> s;
	int j = s.size() - 1;
	for (int i = 0; i < j; i++, j--) {
		if (s[i] != s[j]) {
			cout << "0";
			return 0;
		}
	}
	cout << "1";
	return 0;
}