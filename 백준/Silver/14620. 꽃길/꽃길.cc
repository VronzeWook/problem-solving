#include<bits/stdc++.h>
using namespace std;

const int MAX = 14;
const int INF = 987654321;
int visited[MAX][MAX], mp[MAX][MAX];
int n, cost_temp, cnt , ret = INF;
int my[4] = { 1, 0, -1, 0 }, mx[4] = { 0, 1, 0, -1 };

int cnt_cost() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) sum += mp[i][j];
		}
	}
	return sum;
}

void pop_flower(int y, int x) {
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = my[i] + y;
		int nx = mx[i] + x;
		visited[ny][nx] = 0;
	}
	return;
}

void push_flower(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = my[i] + y;
		int nx = mx[i] + x;
		visited[ny][nx] = 1;
	}
	return;
}

bool is_flower(int y, int x) {
	if (visited[y][x]) return false;
	for (int i = 0; i < 4; i++) {
		int ny = my[i] + y;
		int nx = mx[i] + x;
		if (visited[ny][nx]) return false;
	}
	return true;
}

void go(int r, int y, int x) {
	int cost = cnt_cost();
	//cout << "cost : " << cost << "\n";
	if (cost > ret) return;
	if (r == 3) {
		//cout << "갱신\n";
		ret = min(cost, ret);
		return;
	}

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			//꽃을 심을 수 있다면
			if (is_flower(i, j)) {
				//cout << "push : " << i << ", " << j << "\n";
				push_flower(i, j);
				go(r + 1, i, j);
				//cout << "pop : " << i << ", " << j << "\n";
				pop_flower(i, j);
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost_temp;
			mp[i][j] = cost_temp;
		}
	}


	//백트레킹
	go(0, 1, 1);

	cout << ret;

	return 0;
}