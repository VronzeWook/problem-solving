#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> _tm;
int tn, n, as, bs, ac, bc, cur_t, prev_t;
string s;


int split_t(string ss) {
	int sec = 0, pos = ss.find(":");
	sec = stoi(ss.substr(0, pos)) * 60;
	ss.erase(0, pos + 1);
	sec += stoi(ss);
	return sec;
}
void Tprint(int t) {
	string min = to_string(t / 60);
	string sec = to_string(t % 60);
	if (min.size() < 2) min = "0" + min;
	if (sec.size() < 2) sec = "0" + sec;
	cout << min << ":" << sec << "\n";
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tn;
		cin >> s;
		cur_t = split_t(s);
		if (ac > bc) as += cur_t - prev_t;
		else if (bc > ac) bs += cur_t - prev_t;

		if (tn == 1) ac++;
		else bc++;
		prev_t = cur_t;
	}
	if (ac > bc) as += 48*60 - prev_t;
	if (bc > ac) bs += 48*60 - prev_t;

	Tprint(as);
	Tprint(bs);

	return 0;
}
