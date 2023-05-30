#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000004;
int n, temp;
pair<int, int> num[MAX];
stack<pair<int, int>> stk;
int onum[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		num[i] = { i, temp };
	}

	for (int i = 0; i < n; i++) {
		while (!stk.empty() && num[i].second > stk.top().second) {
			onum[stk.top().first] = num[i].second;
			stk.pop();
		}
		stk.push(num[i]);
	}
	
	while (!stk.empty()) {
		onum[stk.top().first] = -1;
		stk.pop(); 
	}
	
	for (int i = 0; i < n; i++) {
		cout << onum[i] << " ";
	}

	return 0;
}