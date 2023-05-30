#include<bits/stdc++.h>
using namespace std;

int n, fp, lp, cnt;
string str, temp, fstr, lstr;
bool flag = true;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> str;
	fstr = str.substr(0, str.find('*'));
	lstr = str.substr(str.find('*') + 1, str.size());
	reverse(&lstr[0], &lstr[0] + lstr.size());

	for (int i = 0; i < n; i++) {
		cin >> temp;
		
		flag = true;

		for (int j = 0; j < fstr.size(); j++) {
			if (fstr[j] != temp[j]) flag = false;
		}
		
		if(fstr.size()) temp.erase(0, fstr.size());
		reverse(&temp[0], &temp[0] + temp.size());

		for (int j = 0; j < lstr.size(); j++) {
			if (lstr[j] != temp[j]) flag = false;
		}

		if (flag) cout << "DA\n";
		else cout <<"NE\n";
		
	}

	return 0;
}