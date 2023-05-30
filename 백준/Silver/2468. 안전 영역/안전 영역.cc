#include<bits/stdc++.h>
using namespace std;

const int MAX = 101;
const int DIR = 4;

int mp[MAX][MAX];
bool visited[MAX][MAX];
int my[DIR] = { 1, 0, -1, 0 };
int mx[DIR] = { 0, 1, 0, -1 };
int n, max_h, cnt, max_cnt;

bool DFS(int y, int x, int h) {
	if (visited[y][x] != 0 || mp[y][x] <= h) return 0;
	visited[y][x] = 1;
	for (int i = 0; i < DIR; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] == 0 && mp[ny][nx] > h) {
			DFS(ny, nx, h);
		}
	}
	return 1;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] > max_h) max_h = mp[i][j];
		}
	}
	max_cnt = 0;

	for (int i = 0; i <= max_h; i++) {			
		cnt = 0;
		fill(&visited[0][0], &visited[MAX-1][MAX-1], 0);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (DFS(j, k, i)) cnt++;
			}
		}
		if (cnt > max_cnt) max_cnt = cnt;
		}
	cout << max_cnt << "\n";

	return 0;
}