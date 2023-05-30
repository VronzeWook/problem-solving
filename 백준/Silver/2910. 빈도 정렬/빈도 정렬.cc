#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NMAX = 1002;
int n, mx;
ll c;
pair<ll, bool> in[NMAX];
vector<pair<ll, int>> cnt;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> in[i].first;
	}
	for (int i = 0; i < n ; i++) {
		if (in[i].second == true) continue;
		ll current = in[i].first;
		cnt.push_back({current, 1 });
		size_t last = cnt.size() - 1;
		for (int j = i + 1; j < n; j++) {
			if (in[j].first == current) {
				cnt[last].second++;
				in[j].second = true;
			}
		}
		if (cnt[last].second > mx) mx = cnt[last].second;
	}

	for (int i = mx; i > 0; i--) {
		for (int j = 0; j < cnt.size(); j++) {
			if (cnt[j].second == i) {
				for(int k = 0; k < cnt[j].second; k++) cout << cnt[j].first << " ";
			}
		}
	}
	cout << endl;
	return 0;
}