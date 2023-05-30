#include<bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string s;
vector<int> num;
vector<char> oper_s;

int oper(char a, int n1, int n2) {
	if (a == '+') return n1 + n2;
	if (a == '*') return n1 * n2;
	if (a == '-') return n1 - n2;
}

void go(int idx, int sum) {
	if (idx == num.size() - 1) {
		ret = max(ret, sum);
		return;
	}
	//괄호 x
	if (idx + 1 < num.size()) {
		go(idx + 1, oper(oper_s[idx], sum, num[idx + 1]));
	}

	if (idx + 2 < num.size()) {
		int temp = oper(oper_s[idx + 1], num[idx + 1], num[idx + 2]);
		temp = oper(oper_s[idx], sum, temp);
		go(idx + 2, temp);
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else oper_s.push_back(s[i]);
	}

	go(0, num[0]);

	cout << ret;

	return 0;
}