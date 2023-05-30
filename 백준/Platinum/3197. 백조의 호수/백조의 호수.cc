#include<bits/stdc++.h>
using namespace std;

const int MX = 1500, DIR = 4;
int n, m, cnt, water_visited[MX][MX], swan_visited[MX][MX];
int my[DIR] = { 1, 0, -1, 0 }, mx[DIR] = { 0, 1, 0, -1 };
int mp[MX][MX];
bool ans;
queue<pair<int, int>> qWater, qSwan, qNextSwan;
vector<pair<int, int>> swan;

void input() {
	char temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == 'X') mp[i][j] = 1;
			else {
				mp[i][j] = 0;
				qWater.push({ i, j });
			}
			if (temp == 'L') {
				swan.push_back({ i, j });
			}
		}
	}
	qSwan.push({ swan[0].first, swan[0].second });
	swan_visited[swan[0].first][swan[0].second] = 1;
	return;
}

//qWater에서 검사필요
bool moveSwan() {
	while(qSwan.size()) {
		int y = qSwan.front().first;
		int x = qSwan.front().second;
		qSwan.pop();
		for (int d = 0; d < DIR; d++) {
			int ny = y + my[d];
			int nx = x + mx[d];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || swan_visited[ny][nx]) continue;
			swan_visited[ny][nx] = 1;
			if (ny == swan[1].first && nx == swan[1].second) {ans = true;	break;}
			else if (mp[ny][nx] == 1) qNextSwan.push({ ny, nx });
			else qSwan.push({ ny, nx });
		}
		if (ans) break;
	}
	return ans;
}


//물에 닿은 얼음을 큐에 넣고, 물들을 방문 표시
void melting_Water() {
	int qsize = qWater.size();
	for (int i = 0; i < qsize; i++) {
		int y = qWater.front().first;
		int x = qWater.front().second;
		qWater.pop();
		for (int d = 0; d < DIR; d++) {
			int ny = y + my[d];
			int nx = x + mx[d];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || water_visited[ny][nx]) continue;
			if (mp[ny][nx]) {
				mp[ny][nx] = 0;
				qWater.push({ ny, nx });
			}
			water_visited[ny][nx] = 1;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();

	while (!ans) {
		moveSwan();

		if (ans) break;
		
		while (!qNextSwan.empty()) {
			qSwan.push({ qNextSwan.front().first, qNextSwan.front().second });
			qNextSwan.pop();
		}

		melting_Water();
		cnt++;
	}

	cout << cnt;

	return 0;
}