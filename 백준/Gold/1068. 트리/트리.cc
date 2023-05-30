#include<bits/stdc++.h>
using namespace std;

const int MAX = 54;
int n, root_idx, cut, cnt;
vector<int> adj[MAX];
int tree[MAX], temp[MAX];

void DFS(int a) {
	if (adj[a].empty()) {
		cnt++;
		return;
	}
	for (int i = 0; i < adj[a].size(); i++) {
		DFS(adj[a][i]);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> temp[i];
	cin >> cut;

	for (int i = 0; i < n; i++) {
		if (temp[i] == -1) root_idx = i;
		else if (i == cut) continue;
		else {
			adj[temp[i]].push_back(i);
		}
	}

	DFS(root_idx);

	if (root_idx == cut) cnt = 0;
	cout << cnt;

	return 0;
}