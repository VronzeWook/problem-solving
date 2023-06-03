#include<bits/stdc++.h>
using namespace std;

int arr[104], n, k, ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k; 

	for (int i = 0; i < n; i++) {
		if (arr[i] == k) ret++;
	}

	cout << ret;

	return 0;
}