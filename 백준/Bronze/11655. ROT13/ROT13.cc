#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i])) {
			if(isupper(s[i]))(s[i] - 'A' + 13) >= 26 ? s[i] -= 13 : s[i] += 13;
			else (s[i] - 'a' + 13) >= 26 ? s[i] -= 13 : s[i] += 13;
		}
	}
	cout << s;
	return 0;
}