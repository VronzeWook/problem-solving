#include<bits/stdc++.h>
using namespace std;

const int MAX = 53;
int visited[MAX][MAX], mp[MAX][MAX];
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };
int n, m, ret;
char temp;

void BFS(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });
	while (q.size()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		for (int i = 0; i < 4; i++) {
			int ny = now_y + my[i];
			int nx = now_x + mx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !mp[ny][nx])continue;
			visited[ny][nx] = visited[now_y][now_x] + 1;
			ret = max(ret, visited[ny][nx] - 1);
			q.push({ ny, nx });
		}
		q.pop();
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == 'W') mp[i][j] = 0;
			else mp[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!mp[i][j]) continue;
			fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
			BFS(i, j);
		}
	}
	
	cout << ret;

	return 0;
}