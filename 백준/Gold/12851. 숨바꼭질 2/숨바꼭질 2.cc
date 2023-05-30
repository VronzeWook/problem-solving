#include<bits/stdc++.h>
using namespace std;

const int MX = 100000;
int n, m, visited[MX + 4], cnt[2 * MX + 4];


int oper(int a, int idx) {
	if (idx == 0) return a + 1;
	if (idx == 1) return a - 1;
	else return a * 2;
}

int bfs(int start, int target) {
	if (start == target) {
		cnt[target] = 1;
		return 0;
	}
	queue<int> q;
	cnt[start] = 1;
	visited[start] = 1;
	q.push(start);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = oper(x, i);
			if (nx < 0 || nx > MX) continue;
			if (!visited[nx]) {
				q.push(nx);
				visited[nx] = visited[x] + 1;
				cnt[nx] = cnt[x];
			}
			else if (visited[nx] && visited[nx] == visited[x] + 1) {
				cnt[nx] += cnt[x];
			}
		}
	}

	return visited[target] - 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	cout << bfs(n, m) << "\n" << cnt[m];

	return 0;
}