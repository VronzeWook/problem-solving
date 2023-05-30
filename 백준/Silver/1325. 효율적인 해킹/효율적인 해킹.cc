#include<bits/stdc++.h>
using namespace std;

const int MAX = 10004;
vector<int> adj[MAX];
int n, m, cnt, a, b, mx;
int ret_temp[MAX], visited[MAX];

void DFS(int a) {
	if (visited[a]) return;
	visited[a] = 1;
	cnt++;
	for (int i = 0; i < adj[a].size(); i++) DFS(adj[a][i]);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[MAX], 0);
		cnt = 0;
		DFS(i);
		ret_temp[i] = cnt;
	}
	
	for (int i = 1; i <= n; i++) if (mx < ret_temp[i]) mx = ret_temp[i];
	for (int i = 1; i <= n; i++) if (ret_temp[i] == mx) cout << i << " ";

	return 0;
}