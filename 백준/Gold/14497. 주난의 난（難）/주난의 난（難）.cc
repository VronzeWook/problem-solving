#include<bits/stdc++.h>
using namespace std;

const int MX = 300, DIR = 4;
int n, m, cnt = 1, visited[MX][MX];
int my[4] = {1, 0, -1, 0}, mx[4] = {0, 1, 0, -1};
pair<int, int> ju, cho;
char mp[MX][MX];
bool ans;

bool dfs(int y, int x) {
	if (mp[y][x] == '#') return ans = 1;
	//if (mp[y][x] == '1') return ans;
	visited[y][x] = 1;

	for (int i = 0; i < DIR; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
		if (mp[ny][nx] == '1') {
			visited[ny][nx] = 1;
			mp[ny][nx] = 0;
		}
		else {
			dfs(ny, nx);
		}
	}

	return ans;
}




void input() {
	cin >> n >> m;
	cin >> ju.first >> ju.second; 
	cin >> cho.first >> cho.second;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j ++) {
			cin >> mp[i][j];
		}
	}
	ju.second -= 1; ju.first -= 1;
	cho.second -= 1; cho.first -= 1;
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();


	while (!dfs(ju.first, ju.second)) {
		cnt++;
		fill(&visited[0][0], &visited[0][0] + MX * MX, 0);
	}

	cout << cnt;

	return 0;
}