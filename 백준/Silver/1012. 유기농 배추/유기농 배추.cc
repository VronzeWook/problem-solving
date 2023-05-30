#include<bits/stdc++.h>
using namespace std;

const int MAX = 51;
const int DIR = 4;
int t, n, m, k, tx, ty;
int visited[MAX][MAX];
int mp[MAX][MAX];
int my[DIR] = { -1, 0, 1, 0 };
int mx[DIR] = { 0, 1, 0, -1 };

bool DFS(int y, int x) {
	if (visited[y][x] || mp[y][x] == 0) return 0;
	visited[y][x] = 1;
	for (int i = 0; i < DIR; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] != 0) continue;
		if (mp[ny][nx] == 1) {
			DFS(ny, nx);
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int test = 0; test < t; test++) {
		fill(&visited[0][0], &visited[MAX-1][MAX-1], 0);
		fill(&mp[0][0], &mp[MAX-1][MAX-1], 0);
		int cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> tx >> ty;
			mp[ty][tx] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (DFS(i, j)) cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}