#include<bits/stdc++.h>
using namespace std;

int n, T, ret;
string temp1, temp2;
map<string, int> clo_info;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		ret = 1;
		clo_info.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp1 >> temp2;
			clo_info[temp2]++;
		}
		
		for (auto i = clo_info.begin(); i != clo_info.end(); i++) {
			ret *= (i->second + 1);
		}

		ret -= 1;

		cout << ret << "\n";

	}
	return 0;
}