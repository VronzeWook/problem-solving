#include<bits/stdc++.h>
using namespace std;

int n, c, temp;
vector<pair<int, int>> num; //숫자, 횟수

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int flag = false;
		cin >> temp;

		//벡터에 인풋이 이미 있는지 검사
		for (int j = 0; j < num.size(); j++) {
			if (num[j].first == temp) {
				flag = true;
				num[j].second++;
			}
		}

		//새로 들어온 숫자일 경우
		if (!flag) num.push_back({ temp, 1 });
		
	}
    
    //정렬 (바뀌지 않을 때 기존 순서 보장 stable_sort)
	stable_sort(num.begin(), num.end(), cmp);

    //출력
	for (int i = 0; i < num.size(); i++) {
		for (int j = 0; j < num[i].second; j++) {
			cout << num[i].first << " ";
		}
	}

	return 0;
}