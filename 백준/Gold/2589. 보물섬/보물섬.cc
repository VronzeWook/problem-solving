#include<bits/stdc++.h>
using namespace std;

const int NMX = 51;
int n, m, ret;
int visited[NMX][NMX], my[4] = {1, 0, -1, 0}, mx[4] = {0, 1, 0, -1};
char temp;
bool mp[NMX][NMX];

int bfs(int y, int x) {
	if (!mp[y][x]) return 0;
	//cout << "in bfs\n";
	int mx_cnt = 0;
	queue < pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;

	do {
		for (int i = 0; i < 4; i++) {
			int ny = my[i] + q.front().first;
			int nx = mx[i] + q.front().second;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] != 0 || !mp[ny][nx]) continue;
			visited[ny][nx] = visited[q.front().first][q.front().second] + 1;
			mx_cnt = max(mx_cnt, visited[ny][nx]);
			//cout << "push :" << ny << "," << nx << "\n";
			q.push({ ny, nx });
		}
		//cout << "pop :" << q.front().first << "," << q.front().second << "\n";
		q.pop();
	} while (q.size());
	//cout << "\n";

	return mx_cnt;
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
			fill(&visited[0][0], &visited[0][0] + NMX * NMX, 0);
			ret = max(bfs(i, j), ret);
			//cout << "i  j : " << i << ", " << j << "\n";
		}
	}

	if (ret == 0) ret += 1;
	cout << ret - 1 << "\n";

	return 0;
}