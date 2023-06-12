#include<bits/stdc++.h>
using namespace std;

int n, x, arr[10004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < x) cout << arr[i] << " ";
	}


	return 0;
}