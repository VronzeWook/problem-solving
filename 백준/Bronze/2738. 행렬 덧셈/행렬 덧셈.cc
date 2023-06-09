#include<bits/stdc++.h>
using namespace std;

const int MAX = 104;
int arr[MAX][MAX];
int n, m, temp;;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> temp;
				arr[i][j] += temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}