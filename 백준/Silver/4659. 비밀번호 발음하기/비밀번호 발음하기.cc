#include<bits/stdc++.h>
using namespace std;
string s;
string cmps = "aeiou";
string excep = "eo";
int main() {
	while(1) {
		cin >> s;
		if (s == "end") break;
		bool aorb = false, con = false;
		int check_a = 0, check_b = 0;
		for (int i = 0; i < s.size(); i++) {
			bool aflag = false;
			//모음 유무 판별
			if (cmps.find(s[i]) != string::npos) {
				con = true;
				aflag = true;
				check_a++;
			}
			else {
				aflag = false;
				check_b++;
			}
			//자음 모음 연속 3개 이상 판별
			if (check_a * check_b != 0) {
				if (aflag) { check_a = 1; check_b = 0; }
				else { check_a = 0; check_b = 1; }
			}
			else if (check_a > 2 || check_b > 2) {
				con = false;
				break;
			}
			//연속 두글자 판별 ee oo 제외
			if (i < s.size() - 1 && s[i] == s[i + 1]) {
				if (excep.find(s[i]) == string::npos) {
					con = false;
					break;
				}
			}
		}
		if (con) cout << "<" << s << "> is acceptable.\n";
		else cout << "<" << s << "> is not acceptable.\n";
	}
	return 0;
}