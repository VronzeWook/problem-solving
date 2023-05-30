#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int scv[3], n, visited[64][64][64], ret;
int _a[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};

struct thr {
	int a; int b; int c;
};

int solve(int a, int b, int c) {
	queue<thr> q;
	q.push({ a, b, c });
	visited[a][b][c] = 1;
	do {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; i++) {
			int na = max(0, a - _a[i][0]);
			int nb = max(0, b - _a[i][1]);
			int nc = max(0, c - _a[i][2]);
			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb, nc });
		}
	} while (q.size());
	return visited[0][0][0] - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> scv[i];
	}
	
	cout << solve(scv[0], scv[1], scv[2]) << "\n";
	return 0;
}