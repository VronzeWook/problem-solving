#include<bits/stdc++.h>
using namespace std;

const int DIR = 4;
const int NMAX = 9;
const int MAX = NMAX * NMAX;
vector<pair<int, int>> wcoordi;
int mp[NMAX][NMAX], visited[NMAX][NMAX];
int n, m, vcnt, af_vcnt, scnt,vmin = -1, ret;
int my[DIR] = { 1, 0, -1, 0 };
int mx[DIR] = { 0, 1, 0, -1 };

void virus_DFS(int y, int x) {
	if (visited[y][x] || mp[y][x] == 1) return;
	visited[y][x] =1;
	for (int i = 0; i < DIR; i++) {
		int ny = y + my[i];
		int nx = x + mx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || mp[ny][nx] == 1) continue;
		virus_DFS(ny, nx);
	}
	if (mp[y][x] == 0) af_vcnt++;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 0) {
				wcoordi.push_back({ i, j }); //벽 생성가능 공간
				scnt++; //여백 크기
			}
			else if (mp[i][j] == 2) vcnt++;
		}
	}
	//벽이 세워질 수 있는 경우 완전 탐색
	for (int i = 0; i< wcoordi.size() - 2; i++) {
		mp[wcoordi[i].first][wcoordi[i].second] = 1;
		for (int j = i + 1; j < wcoordi.size() - 1; j++) {
			mp[wcoordi[j].first][wcoordi[j].second] = 1;
			for (int k = j + 1; k < wcoordi.size(); k++) {
				mp[wcoordi[k].first][wcoordi[k].second] = 1;

				fill(&visited[0][0], &visited[n][m] + 1, 0);
				af_vcnt = 0;

				for (int dj = 0; dj < n; dj++) {
					for (int dk = 0; dk < m; dk++) {
						if (mp[dj][dk] == 2) {
							virus_DFS(dj, dk);
							//cout << "Dfs 완 \n";
						}
					}
				}
				if (vmin == -1) vmin = af_vcnt;
				else vmin = min(vmin, af_vcnt);

				mp[wcoordi[k].first][wcoordi[k].second] = 0;
			}
			mp[wcoordi[j].first][wcoordi[j].second] = 0;
		}
		mp[wcoordi[i].first][wcoordi[i].second] = 0;
	}
	ret = scnt - vmin - 3 ;
	cout << ret << "\n";

	return 0;
}