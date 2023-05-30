#include<bits/stdc++.h>
using namespace std;

const int NMX = 51;
int visited[NMX][NMX], mp[NMX][NMX];
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };
int n, bot, top, cnt, sum, day_cnt;
vector<pair<int, int>> adj[NMX][NMX];
// 연결 컴포넌트 개수, 합 연산
bool dfs(int y, int x) {
	if (visited[y][x]) return false; //방문하지 않은 그래프만 방문
	visited[y][x] = 1; // 첫 방문 처리
	sum += mp[y][x]; //연결 컴포넌트 요소 합 구하기
	for (int i = 0; i < adj[y][x].size(); i++) {
		dfs(adj[y][x][i].first, adj[y][x][i].second); //연결되 그래프로 들어감
	}
	cnt++; //연결된 그래프 개수를 위한 cnt
	return true;
}
//연결 컴포넌트를 floor(합/개수) 으로 채움
void fill_dfs(int y, int x, int sm) {
	if (visited[y][x] != 1) return; // visited == 1인 곳만 처리
	visited[y][x] += 1; //재방문 처리
	mp[y][x] = sm; //값 대입
	for (int i = 0; i < adj[y][x].size(); i++) {
		fill_dfs(adj[y][x][i].first, adj[y][x][i].second, sm); //연결된 그래프로 들어감
	}
	return;
}
//visited와 그래프 연결 리스트 초기화
void reset() {
	fill(&visited[0][0], &visited[0][0] + NMX * NMX, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adj[i][j].clear();
		}
	}
	return;
}
//top, bot 값을 기준으로 그래프 연결 리스트 작성
bool link_map() {
	int flag = false;
	for (int i = 0; i < n; i++) { //모든 노드를 방문하며
		for (int j = 0; j < n; j ++) {
			for (int k = 0; k < 4; k++) { //노드 4방향 탐색
				int ny = my[k] + i;
				int nx = mx[k] + j;
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue; //조건에 만족해야 실행
				int gap = abs(mp[i][j] - mp[ny][nx]); 
				if (gap <= top && gap >= bot) { //두 노드가 조건에 만족하면 서로 연결
					adj[i][j].push_back({ ny, nx });
					adj[ny][nx].push_back({ i, j });
					flag = true; //연결된 그래프가 남아 있음을 알림
				}
			}
		}
	}
	return flag;
}
//입력
void input() {
	cin >> n >> bot >> top;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}
	return;
}
//출력
void output() {
	cout << day_cnt;
	return;
}
//실행
void run() {
	while (link_map()) { // 새롭게 연결된 그래프가 있다면 실행
		for (int i = 0; i < n; i++) {//모든 그래프 방문
			for (int j = 0; j < n; j++) {
				cnt = 0; sum = 0; //그래프 개수와 그래프 요소 합 초기화
				if (dfs(i, j)) fill_dfs(i, j, sum / cnt); //dfs()에서 방문 실행되었을때, 요소들을 새롭게 채움
			}
		}
		day_cnt++; //실행된 날짜를 카운트
		reset(); //visited와 연결 리스트를 초기화
	};
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//입력
	input();
	//실행
	run();
	//출력
	output();
	return 0;
}