#include<bits/stdc++.h>
using namespace std;

const int MX = 1004, INF = 99999999;
int mp[MX][MX], person[MX][MX], fire[MX][MX];
int n, m, ret;
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };
pair<int, int> sp;
char temp;
queue<pair<int, int>> q;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == '#') mp[i][j] = 1;
			else if (temp == '.') mp[i][j] = 0;
			else if (temp == 'F')
			{
				fire[i][j] = 1;
				q.push({ i, j });
			}
			else if (temp == 'J') sp = {i, j};
		}
	}
	return;
}


void output() {
	if (ret == 0 ) cout << "IMPOSSIBLE\n";
	else cout << ret << "\n"; //최종 탈출을 위한 ++
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&fire[0][0], &fire[0][0] + MX * MX, INF);
	input();
	
	//불 좌표마다 BFS 실행
	while(q.size()) {
		int fy = q.front().first;
		int fx = q.front().second;
		q.pop();
		for (int v = 0; v < 4; v++) {
			int ny = my[v] + fy;
			int nx = mx[v] + fx;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || mp[ny][nx]) continue;
			if (fire[ny][nx] != INF) continue;
			fire[ny][nx] = fire[fy][fx] + 1;
			q.push({ ny, nx });
		}
	} 

	/*
	cout << "\nfire info\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << fire[i][j] << " ";
		}
		cout << "\n";
	}
	*/


	//사람 BFS 실행
	person[sp.first][sp.second] = 1;
	q.push({ sp.first, sp.second });
	while(q.size()) {
		int fy = q.front().first;
		int fx = q.front().second;
		q.pop();
		if (fy == n - 1 || fy == 0 || fx == m - 1 || fx == 0) {
			//cout << "ans fy fx : " << fy << ", " << fx << "\n";
			ret = person[fy][fx];
			break;
		}
		for (int v = 0; v < 4; v++) {
			int ny = my[v] + fy;
			int nx = mx[v] + fx;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || mp[ny][nx] || person[ny][nx]) continue;
			if (fire[ny][nx] <= person[fy][fx] + 1) continue;
			//cout << "ny , nx : " << ny << ", " << nx << "\n";
			person[ny][nx] = person[fy][fx] + 1;
			q.push({ ny, nx });
		}
	} 
	/*
	cout << "\nperson info\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << person[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	
	//결과 출력
	output();

	return 0;
}