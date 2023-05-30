#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
int arr[15004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (m > 200000) cout << 0 << '\n';
	else {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] + arr[j] == m) cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}