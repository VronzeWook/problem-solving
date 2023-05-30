#include<bits/stdc++.h>
using namespace std;

const int MX = 100004;
int n, m, visited[MX * 2 + 4];
vector<int> adj[MX * 2 + 4];

int oper(int a, int idx) {
	if (idx == 0) return a + 1;
	if (idx == 1) return a - 1;
	else return a * 2;
}

int bfs(int start, int target) {
	if (start == target) {
		return 0;
	}
	
	queue<int> q;
	visited[start] = 1;
	q.push(start);
	while (q.size()) {
		int now = q.front();
		q.pop();
		if (visited[target]) break;
		for (int i = 0; i < 3; i++) {
			int next = oper(now, i);
			if (next < 0 || next > MX * 2 || visited[next]) continue;
			adj[next].push_back(now);
			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
	return visited[target] - 1;
}

void find_ans(int cur) { //tartget to start
	if (cur == n) {
		cout << cur << " ";
		return;
	}

	find_ans(adj[cur][0]);
	cout << cur << " ";

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	cout << bfs(n, m) << "\n";
	find_ans(m);

	return 0;
}