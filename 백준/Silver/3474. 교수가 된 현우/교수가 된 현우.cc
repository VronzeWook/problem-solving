#include<bits/stdc++.h>
using namespace std;

int n, num, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ret = 0;
		cin >> num;
		for (int j = 5; j <= num; j *= 5) {
			ret += num / j;
		}
		cout << ret << "\n";
	}
	return 0;
}