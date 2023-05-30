#include<bits/stdc++.h>
using namespace std;

int n;
string temp;
vector<string> str, ret;
string number = "0123456789";

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) return a[i] < b[i];
		}
	}

	return a.size() < b.size();

}

void rez(string* s) {
	int idx = 0;
	for (int i = 0; i < (*s).size(); i++) {
		if ((*s)[i] != '0') break;
		else (*s).erase(0, 1);
		i = -1;
	}
	if ((*s).empty()) (*s) = "0";
	return;
}

void find_num(string s) {
	string token = "";
	bool flag = false;
	char _prev = 'a';
	for (int i = 0; i < s.size(); i++) {
		if (number.find(_prev) != string::npos && number.find(s[i]) == string::npos) {
			rez(&token);
			ret.push_back(token);
			token = "";
		}
		else if (number.find(s[i]) != string::npos) token += s[i];
		_prev = s[i];
	}
	if (token != "") {
		rez(&token);
		ret.push_back(token);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		str.push_back(temp);
	}

	for (int i = 0; i < str.size(); i++) {
		find_num(str[i]);
	}

	sort(ret.begin(), ret.end(), cmp);

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << "\n";
	}

	return 0;
}