#include<bits/stdc++.h>
using namespace std;

const int NMX = 50, MMX = 13;
int n, m, cnt, ret = NMX * NMX;
int mp[NMX][NMX], ret_mp[NMX][NMX];
int my[4] = {1, 0, -1, 0}, mx[4] = {0, 1, 0, -1};
vector<pair<int, int>> clist, hlist, cl;

//집마다 최소 거리 합
int sum_dis() {
	int sum = 0;
	for (int i = 0; i < hlist.size(); i++) sum += ret_mp[hlist[i].first][hlist[i].second];
	return sum;
}

//치킨집부터 BFS수행하며 최솟값 갱신
void bfs(int y, int x) {
	int visited[NMX][NMX];
	fill(&visited[0][0], &visited[0][0] + NMX * NMX, 0);
	queue<pair<int, int >> q;
	q.push({ y, x });
	visited[y][x] = 1;
    //cout << "in bfs\n";
	do {
		for (int i = 0; i < 4; i++) {
			//cout << "in dir\n";
			int ny = q.front().first + my[i];
			int nx = q.front().second + mx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])continue;
		    visited[ny][nx] = visited[q.front().first][q.front().second] + 1;
			if (mp[ny][nx] == 1) {
				//cout << "ny, nx : " << ny << ", " << nx << "\n";
				//cout << "visited[ny][nx] : " << visited[ny][nx] << "\n";
				ret_mp[ny][nx] = min(ret_mp[ny][nx], visited[ny][nx] - 1);
			}
			q.push({ ny,nx });
		}
		q.pop();
	} while (q.size());
	return;
}

//해당 조합일 때 최소 치킨거리
int ck_dis(vector<pair<int, int>>* cl) {
	int min_ret = 0;
	//치킨집에서 bfs 시작
	fill(&ret_mp[0][0], &ret_mp[0][0] + NMX * NMX, 2 * NMX + 1); //최솟값을 찾기위한 초기화
	for (int i = 0; i < (*cl).size(); i++) bfs((*cl)[i].first, (*cl)[i].second);
	//집마다 치킨거리 더하기
	min_ret = sum_dis();
	return min_ret;
}


void combi(vector<pair<int, int>> * cl, int start) {
	//cl.sizE()개 중 r개 조합으로 경우의 수
	if ((*cl).size() == m) {
		//치킨집 조합 테스트
		/*
		cout << "조합테스트\n";
		for (int i = 0; i < cl->size(); i++) {
			cout <<  "(" << (*cl)[i].first << "," << (*cl)[i].second << ")  ";
		}
		cout << "\n";
		*/
		int temp = ck_dis(cl);
		ret = min(temp, ret);

		return;
	}

	for (int i = start + 1; i < clist.size(); i++) {
		cl->push_back(clist[i]);
		//cout << "push : " << clist[i].first << ", " << clist[i].second << "\n";
		combi(cl, i);
		//cout << "pop : " << (*cl)[cl->size() - 1].first << ", " << (*cl)[cl->size() - 1].first << "\n";
		cl->pop_back();
	}
	return;
}

//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 2) {
				clist.push_back({ i, j }); //치킨 좌표
				//cout << "push i j c  : " << i << ", " << j << "\n";
				mp[i][j] = 0;
			}
			else if (mp[i][j] == 1) hlist.push_back({ i, j }); //집 좌표
		}
	}
	return;
}

//출력
void output() {
	cout << ret << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	input();

	combi(&cl, -1);

	output();

	return 0; 
}