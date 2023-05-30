#include<bits/stdc++.h>
using namespace std;

int n;
char mp[65][65];

void qt(int y, int x, int nn) {
	int flag = false, _prev = mp[y][x];
	for (int i = y; i < y + nn; i++) {
		for (int j = x; j < x + nn; j++) {
			if (mp[i][j] != _prev) flag = true;
		}
	}

	if (flag) {
		cout << "(";
		qt(y, x, nn / 2);
		qt(y, x + nn / 2, nn / 2);
		qt(y + nn / 2, x, nn / 2);
		qt(y + (nn / 2), x + (nn / 2), nn / 2);
		cout << ")";
	}
	else cout << mp[y][x];
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

	qt(0, 0, n);

	return 0;
}