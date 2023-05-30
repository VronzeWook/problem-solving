#include<bits/stdc++.h>
using namespace std;

const int MX = 500000;
int n, m, visited[2][MX + 4];
bool ret = false;
//계층에 맞는 비교값 배열


int oper(int a, int idx) {
	if (idx == 0) return a + 1;
	if (idx == 1) return a - 1;
	else return a * 2;
}

int bfs(int start, int target) {
	if (start == target) {
		ret = true;
		return 0;
	}
	int  turn = 1;
	queue<int> q; //현 위치, 해당 계층에서 비교되야할 위치
	visited[0][start] = 1;
	q.push(start);
	while (q.size()) {
		target += turn;
		if (target > MX) break;
		if (visited[turn % 2][target]) {
			ret = true;
			break;
		}

		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front();
			q.pop();
			for (int j = 0; j < 3; j++) {
				int nx = oper(x, j);
				if (nx < 0 || nx > MX || visited[turn % 2][nx]) continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				if (nx == target) {
					ret = true; break;
				}
				q.push(nx);
			}
			if (ret) break;
		}
		if (ret) break;
		turn++;
	}
	
	return turn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int temp = bfs(n, m);
	if (ret) cout << temp << "\n";
	else cout << -1 << "\n";
	return 0;
}