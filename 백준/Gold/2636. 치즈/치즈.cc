#include<bits/stdc++.h>
using namespace std;

const int DIR = 4;
const int MAX = 104;
int mp[MAX][MAX];
bool visited[MAX][MAX];
int my[] = {1 , 0, -1, 0}, mx[] = {0, 1, 0, -1};
int n, m, ret, ch_cnt, ch_prev, cnt;
bool zero_f, o2;

int cheese_DFS(int y, int x) {
	if (visited[y][x] || mp[y][x]) return 0;
	visited[y][x] = 1;
	for (int i = 0; i < DIR; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || mp[ny][nx]) continue;
		cheese_DFS(ny, nx);
	}
	for (int i = 0; i < DIR; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !mp[ny][nx]) continue;
			mp[ny][nx] = 0;
			visited[ny][nx] = 1;
			ch_cnt--;
	}
	return ch_cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 1) ch_cnt++;
		}
	}
	ch_prev = ch_cnt;
	while(true) {
		fill(&visited[0][0], &visited[MAX-1][MAX-1], 0);
		cheese_DFS(0, 0);
		cnt++;
		if (!ch_cnt) break;
		ch_prev = ch_cnt;
	}
	cout << cnt << "\n";
	cout << ch_prev << "\n";

	return 0;
}