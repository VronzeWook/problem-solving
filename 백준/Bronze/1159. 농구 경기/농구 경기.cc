#include<bits/stdc++.h>
using namespace std;
string temp;
int cnt[26];
int flag = 0, N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		cnt[temp[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 4) {
			char ch = i + 'a';
			cout << ch;
			flag = 1;
		}
	}
	if (flag == 0) cout << "PREDAJA";
	return 0;
}