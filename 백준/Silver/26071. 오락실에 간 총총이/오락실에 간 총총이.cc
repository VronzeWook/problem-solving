#include<bits/stdc++.h>
using namespace std;

const int MAX = 1504;
char mp[MAX][MAX];
int n, ret, cnt, top_y, bot_y, top_x, bot_x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	top_y = 0; top_x = 0; bot_y = n; bot_x = n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'G') {
				cnt++;
				if (i > top_y) top_y = i;
				if (i < bot_y) bot_y = i;
				if (j > top_x) top_x = j;
				if (j < bot_x) bot_x = j;
			}
		}
	}

	if (top_y == bot_y) {
		ret = min(bot_x, n - 1 - top_x);
	}
	else if (top_x == bot_x) {
		ret = min(bot_y, n - 1 - top_y);
	}
	else {
		ret = min(min( bot_x + bot_y, bot_y + (n - 1 - top_x)), min((n - 1 - top_y) + bot_x, (n - 1 - top_y) + (n - 1 - top_x)));
	}

	ret += (top_y - bot_y) + (top_x - bot_x);
	if (cnt == 1) ret = 0;

	cout << ret << '\n';

	return 0;
}