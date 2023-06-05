#include<bits/stdc++.h>
using namespace std;

const int MAX = 5;
int mp[MAX][MAX], visited[MAX][MAX];
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };
int n, m, k, ret, cnt;
char temp;

void go(int y, int x, int idx) {

	//목적지 도착 못하고 거리 충족
	if (idx == k && y == 0 && x == m - 1) {
		cnt++;
		return;
	}
	//목적지 도착 하고 거리충족
	else if (idx == k) return;
	
	for (int d = 0; d < 4; d++) {
		int ny = my[d] + y;
		int nx = mx[d] + x;
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || mp[ny][nx]) continue;
		visited[ny][nx] = 1;
		go(ny, nx, idx + 1);
		visited[ny][nx] = 0;
	}

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == '.') mp[i][j] = 0;
			else mp[i][j] = 1;
		}
	}

	//백트래킹 하며 cnt ++;

	visited[n - 1][0] = 1;
    go(n - 1, 0, 1);


	//출력
	cout << cnt;


	return 0;
}