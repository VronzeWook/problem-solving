#include<bits/stdc++.h>
using namespace std;

const int MAX = 54;
int visited[MAX][MAX], mp[MAX][MAX];
int n, bot, top, sum, cnt, day;
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> union_list;
bool changed_flag = true;

void fill_avg(int fill) {
	for (int i = 0; i < union_list.size(); i++) {
		int y = union_list[i].first;
		int x = union_list[i].second;
		if(mp[y][x] != fill) changed_flag = true;
		mp[y][x] = fill;
	}
	return;
}

void DFS(int y, int x) {
	union_list.push_back({ y, x });
	sum += mp[y][x];
	visited[y][x] = 1;
	for (int d = 0; d < 4; d++) {
		int ny = my[d] + y;
		int nx = mx[d] + x;
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
		//인구 차이 조건
		int gab = abs(mp[y][x] - mp[ny][nx]);
		if (gab < bot || gab > top) continue;
		DFS(ny, nx);
	}
	cnt++;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> bot >> top;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

	//멈출 때 까지 반복
	do {
		changed_flag = false; day++;
		fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				sum = 0; cnt = 0; union_list.clear();
				DFS(i, j);
				fill_avg(sum / cnt);
			}
		}
		/*
		cout << "인구 이동 후 \n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mp[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
	} while (changed_flag);

	cout << day - 1;

	return 0;
}