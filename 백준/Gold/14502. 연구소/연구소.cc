#include<bits/stdc++.h>
using namespace std;

const int MAX = 8;
int n, m, cnt, ret;
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };
int mp[MAX][MAX], visited[MAX][MAX], mp_temp[MAX][MAX];
vector<pair<int, int>> space;

void DFS(int y, int x) {
	if (visited[y][x] || mp[y][x] == 1) return;
	visited[y][x] = 1;
	mp_temp[y][x] = 2;
	for (int d = 0; d < 4; d++) {
		int ny = my[d] + y;
		int nx = mx[d] + x;
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		DFS(ny, nx);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (!mp[i][j]) space.push_back({ i, j });
		}
	}

	for (int i = 0; i < space.size() - 2; i++) {
		for (int j = i + 1; j < space.size() - 1; j++) {
			for (int k = j + 1; k < space.size(); k++) {\
				//벽 세우기
				mp[space[i].first][space[i].second] = 1;
				mp[space[j].first][space[j].second] = 1;
				mp[space[k].first][space[k].second] = 1;
				//바이러스 전이 전 상태 불러오기 및 visited 초기화
				copy(&mp[0][0], &mp[0][0] + MAX * MAX, &mp_temp[0][0]);
				fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);

				//바이러스 뿌리기
				for (int vi = 0; vi < n; vi++) {
					for (int vj = 0; vj < m; vj++) {
						if(mp_temp[vi][vj] == 2) DFS(vi, vj);
					}
				}
		

				//안전 영역 카운트
				cnt = 0;
				for (int si = 0; si < n; si++) {
					for (int sj = 0; sj < m; sj++) {
						if (mp_temp[si][sj] == 0) cnt++;
					}
				}

				//최댓값 갱신
				ret = max(cnt, ret);

				//벽 철거
				mp[space[i].first][space[i].second] = 0;
				mp[space[j].first][space[j].second] = 0;
				mp[space[k].first][space[k].second] = 0;
			}
		}
	}

	cout << ret;

	return 0;
}