#include<bits/stdc++.h>
using namespace std;

bool visited[34][34];
int n, m, h, temp1, temp2, cnt;
int ret = 987654321;

bool is_way() {
	for (int p = 1; p <= n; p++) { //세로 줄마다
		int pos = p;
		for (int i = 1; i <= h; i++) { //가로줄로 내려오기
			if (visited[i][pos]) pos += 1;
			else if (pos > 1 && visited[i][pos - 1]) pos -= 1;
		}
		if (pos != p) return false;
	}
	return true;
}

void find_way(int now, int cnt) {
	//조건 초과 시 리턴
	if (cnt > 3 || cnt >= ret) return;
	//길을 찾으면 cnt갱신 리턴
	if (is_way()) {
		ret = min(ret, cnt);
		return;
	}
	for (int i = now; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			//해당 노드, 이전, 다음에 가로선이 있으면 continue 
			if (visited[i][j] || visited[i][j + 1] || visited[i][j - 1]) continue;
			visited[i][j] = 1;
			find_way(i, cnt + 1);
			visited[i][j] = 0;
		}
	 }
	return;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		visited[temp1][temp2] = 1; 
	}
	
	find_way(1, 0);

	if (ret == 987654321) cout << "-1";
	else cout << ret;

	return 0;
}