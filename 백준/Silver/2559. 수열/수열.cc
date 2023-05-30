#include<bits/stdc++.h>
using namespace std;

int n, date, sum, ret;
int temper[100004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> date;
	for (int i = 0; i < n; i++) {
		cin >> temper[i];
	}

	//초기값 설정
	for (int i = 0; i < date; i++) sum += temper[i];
	ret = sum;

	//최댓값 갱신
	for (int i = 1; i < n - date + 1; i++) {
		sum -= temper[i - 1];
		sum += temper[i + date - 1];
		ret = max(ret, sum);
	}

	//출력
	cout << ret << "\n";

	return 0;
}