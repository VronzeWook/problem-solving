#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

unordered_map<string, string> mp1, mp2;
int n, m;
string temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> temp;
		string it = to_string(i);
		mp1.insert({ it, temp});
		mp2.insert({ temp, it });
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (!isalpha(temp[0])) cout << mp1[temp] << "\n";
		else cout << mp2[temp] << "\n";
	}

	return 0;
}