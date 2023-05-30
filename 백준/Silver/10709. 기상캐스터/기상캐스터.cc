#include<bits/stdc++.h>
using namespace std;

const int MX = 100;
int n, m, ret[MX][MX];
char mp[MX + 4][MX + 4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
		}
	}

	//모든 노드 순회
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//좌측으로 탐색
			int cnt = 0; bool cloudFlag = false;
			for (int k = j; k >= 0; k--) {
				if (mp[i][k] == 'c') { //구름 발견 시
					ret[i][j] = cnt; 
					cloudFlag = true;
					break;
				}
				cnt++; //소요 시간 증가
			}
			if (!cloudFlag) ret[i][j] = -1; //경로 내 구름X
		}
	}

	//출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}