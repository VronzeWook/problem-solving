#include<bits/stdc++.h>
using namespace std;

int atk[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

struct scvs {
	int a, b, c;
};

int visited[64][64][64];

int n, cnt, scv[3];
queue<scvs> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> scv[i];
	}

	//BFS
	q.push({ scv[0], scv[1], scv[2] });
	visited[scv[0]][scv[1]][scv[2]] = 1;
	while (q.size()){
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
	
		for (int i = 0; i < 6; i++) {
			int na = a - atk[i][0];
			int nb = b - atk[i][1];
			int nc = c - atk[i][2];
			if (na < 0) na = 0;
			if (nb < 0) nb = 0;
			if (nc < 0) nc = 0;
			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb, nc });
		}
		if (visited[0][0][0]) break;
	}

	//출력
	cout << visited[0][0][0] - 1;


	return 0;
}