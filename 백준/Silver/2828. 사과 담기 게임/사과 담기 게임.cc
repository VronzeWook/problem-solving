#include<bits/stdc++.h>
using namespace std;

int n, m, k, temp, ret;
pair<int, int> basket; //start, end
int move_basket(pair<int, int> *bas, int des) {
	if (des >= bas->first && des <= bas->second) return 0;
	
	int move_dis = 0;
	if (des < bas->first) move_dis = des - bas->first;
	else if (des > bas->second) move_dis = des - bas->second;
	bas->first += move_dis;
	bas->second += move_dis;

	return abs(move_dis);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	basket = { 1, m };
	for (int i = 0; i < k; i++) {
		cin >> temp;
		ret += move_basket(&basket, temp);
	}

	cout << ret;

	return 0;
}