#include<bits/stdc++.h>
using namespace std;

string str, ans;
char alpha[26];
int odd_cnt, center = -1;
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//입력
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		alpha[str[i] - 'A'] ++;
	}
	//가능 여부 판단
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			center = i;
			odd_cnt++;
		}
		if (odd_cnt > 1) {
			flag = true;
			break;
		}
	}
	//팰린드롬 만들고 출력
	if (!flag) {
		for (int i = 0; i < 26; i++) {
			if (alpha[i] == 0) continue;
			for (int j = 0; j < alpha[i] / 2; j++) {
				ans += i + 'A';
			}
		}
		string temp = ans;
		reverse(temp.begin(), temp.end());
		if (center != -1) ans += center + 'A';
		ans += temp;
		cout << ans << "\n";
	}
	else {
		cout << "I'm Sorry Hansoo\n";
	}
	return 0;
}