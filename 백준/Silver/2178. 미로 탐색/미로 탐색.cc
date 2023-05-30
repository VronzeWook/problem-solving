#include<bits/stdc++.h>
using namespace std;

int n, m;
char mp[101][101];
int visited[101][101];
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };


void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;

	while (q.size()) {
		for (int i = 0; i < 4; i++) {
			int ny = q.front().first + my[i];
			int nx = q.front().second + mx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || mp[ny][nx] == '0') continue;
			q.push({ ny, nx });
			visited[ny][nx] = visited[q.front().first][q.front().second] + 1;
		}
		if(!q.empty()) q.pop();
	}

	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
		}
	}

	bfs(0, 0);

	cout << visited[n - 1][m - 1];


	return 0;
}