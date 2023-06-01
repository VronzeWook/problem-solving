#include<bits/stdc++.h>
using namespace std;

const int MAX = 50;
int n, m, cnt, ret, min_dis = 2098765432;
int mp[MAX][MAX], visited[MAX][MAX], dis[MAX][MAX];
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> chicken, home, com;

//BFS로 탐색하며 visited에 거리 저장
void BFS(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });
	while (q.size()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = my[d] + nowy;
			int nx = mx[d] + nowx;
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
			visited[ny][nx] = visited[nowy][nowx] + 1;
			q.push({ ny, nx });
		}
	}
	return;
}

//경우의 수를 구하고, 해당 경우에서 최소 치킨 거리를 갱신
void combi(int idx) {
	if (com.size() == m) {
		/*
		cout << "            combi        \n";

		for (int i = 0; i < com.size(); i++)
		{
			cout << "(" << com[i].first << ", " << com[i].second << ")        ";
		}

		cout << "\n";
		*/
		//경우의 수 생성, com의 치킨집 좌표 마다 BFS 실행
		int sum = 0;
		fill(&dis[0][0], &dis[0][0] + MAX * MAX, 2098765432);
		for (int i = 0; i < com.size(); i++) {
			fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
			BFS(com[i].first, com[i].second);
			//visited 와 dis min()을 통해 갱신
			for (int j = 0; j < home.size(); j++) {
				int hy = home[j].first;
				int hx = home[j].second;
				dis[hy][hx] = min(dis[hy][hx], visited[hy][hx] - 1);
			}
		}

		//치킨 거리 합 구하고 최소값 갱신
		for (int i = 0; i < home.size(); i ++) {
			sum += dis[home[i].first][home[i].second];
		}
		min_dis = min(min_dis, sum);

		return;
	}

	for (int i = idx + 1; i < chicken.size(); i++) {
		com.push_back(chicken[i]);
		combi(i);
		com.pop_back();
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			cin >> mp[i][j];
			if (mp[i][j] == 2) chicken.push_back({ i, j });
			if (mp[i][j] == 1) home.push_back({i, j});
		}
	}

	combi(-1);

	//vector chicken으로 경우의 수만큼 반복

	//초기화

	//치킨집에서 BFS를 수행하며 집마다 최소거리 갱신

	//치킨 거리 합

	//최소값 갱신

	//출력

	cout << min_dis;

	return 0;
}