#include <iostream>
#include <string>
using namespace std;
const int MAX = 10004;
const int INIT_N = 666;
int n, cnt, ret;
string s;

int six_index (string t){
	for (int i = 0; i < t.size() - 2; i++) {
		if (t[i] == '6' && t[i + 1] == '6' && t[i + 2] == '6') return i;
	}
	return -1;
}

int main() {
	cin >> n;
	
	for (int i = 0; cnt < n ; i++) {
		s = to_string(i * 1000 + INIT_N);
		int temp = six_index(s);
		ret = 0;

		if (temp != -1 && temp != s.size() - 3) {
			int ntemp = s.size() - 3 - temp;
			string stemp;

			for (int j = 0; j < ntemp; j++) stemp += '9';
			//자리수만큼 9를 만들어서 int 형으로
			int mtemp = stoi(stemp);
			//자릿수만큼 0 ~ n개의 9까지 탐색
			for (int j = 0; j <= mtemp && cnt != n; j++, cnt++) {
				ret = j;
			}
			//만약 cnt가 달성되면 문자열로 변환 후, 문자열 합 그리고 ret에 대입
			if (cnt == n) {
				s = s.substr(0, s.size() - ntemp);
				string sstemp = to_string(ret);
				for (int j = 0; j < ntemp - sstemp.size(); j++) s += '0';
				s += sstemp;
				ret = stoi(s);
				break;	
			}
		}
		else {
			ret += stoi(s);
			cnt++;
		}
	}
	cout << ret;
	return 0;
}