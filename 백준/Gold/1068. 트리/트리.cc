#include<bits/stdc++.h>
using namespace std;

const int MAX = 50;
int n, del_num, temp, cnt, root;
vector<int> adj[MAX];

void dfs(int r) {
	if (adj[r].empty()) {
		cnt++;
		return;
	}
	for (int i = 0; i < adj[r].size(); i++) {
		dfs(adj[r][i]);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) {
			root = i;
			continue;
		}
		adj[temp].push_back(i);
	}
	
	cin >> del_num;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (adj[i][j] == del_num) adj[i].erase(adj[i].begin() + j);
		}
	}
	
	dfs(root);

	if (del_num == root) cout << 0;
	else cout << cnt;

	return 0;
}