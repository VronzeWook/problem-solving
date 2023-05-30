#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n) {
		int a = 0;
		int cnt = 0;
		do {
			a = (a * 10) + 1;
			a %= n;
			cnt++;
		} while (a != 0);
		cout << cnt << '\n';
	}
	return 0;
}