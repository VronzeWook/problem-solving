#include<bits/stdc++.h>
using namespace std;

const int MAX = 101;
const int DIR = 4;
int my[DIR] = { 1, 0, -1, 0 };
int mx[DIR] = { 0, 1, 0, -1 };
int mp[MAX][MAX];
bool visited[MAX][MAX];
int n, m, k, a_cnt, cnt;
int kyx[4];
vector<int> area;

bool DFS(int y, int x) {
	if (visited[y][x] == 1 || mp[y][x] != 0) return 0;
	visited[y][x] = 1;
	cnt++;
	for (int i = 0; i < DIR; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] == 0 && mp[ny][nx] == 0) {
			DFS(ny, nx);
		}
	}
	return 1;
}

void squre(int y1, int x1, int y2, int x2) {
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) mp[i][j] ++;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >>  m >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> kyx[0] >> kyx[1] >> kyx[2] >> kyx[3];
		squre(kyx[0], kyx[1], kyx[2], kyx[3]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt = 0;
			if (DFS(i, j)) {				
				a_cnt++;
				area.push_back(cnt);
			}
		}
	}

	sort(area.begin(), area.end());

	cout << a_cnt << '\n';
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}

	return 0;
}