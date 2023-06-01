#include<bits/stdc++.h>
using namespace std;

const int MAX = 10004;
int n, m, temp1, temp2, cnt, mx, _prev_mx, cnt_ret[MAX];
vector<int> adj[MAX], ret;
bool visited[MAX];

//노드 완전 탐색으로 노드 개수 카운트
void dfs(int r) {
	visited[r] = 1;
	for (int i = 0; i < adj[r].size(); i++) {
		if (visited[adj[r][i]]) continue;
		dfs(adj[r][i]);
	}
	cnt++;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력 및 인접 리스트 기록
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		adj[temp2].push_back(temp1);
	}

	//모든 노드에서 탐색하며 전파가능한 최대 노드 수 갱신
	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[0] + MAX, 0);
		cnt = 0;
		dfs(i);
		mx = max(cnt, mx);
		cnt_ret[i] = cnt;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt_ret[i] == mx) ret.push_back(i);
	}
	
	sort(ret.begin(), ret.end());

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}

	return 0;
}