#include<bits/stdc++.h>
using namespace std;

string number = "0123456789";
int n;
string input, ret_max, ret_min, temp;
vector<char> com;
bool stopFlag;


bool is_accep() {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '<' && com[i] >= com[i + 1]) return false;
		else if (input[i] == '>' && com[i] <= com[i + 1]) return false;
	}
	return true;
}


void combi(int idx, bool _switch) {
	if (com.size() == n + 1) {
		if (_switch) {
			do {
				if (is_accep()) {
					stopFlag = true;
					break;
				}
			} while (prev_permutation(com.begin(), com.end()));
		}
		else{
			do {
				if (is_accep()) {
					stopFlag = true;
					break;
				}
			} while (next_permutation(com.begin(), com.end()));
		}
		return;
	}

	for (int i = idx + 1; i < number.size(); i++) {
		com.push_back(number[i]);
		combi(i, _switch);
		if (stopFlag) return;
		com.pop_back();
	}

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	//설계
	//조합 0 ~ 9 중 부등호 갯수 + 1개
	//최솟값은 012... 부터 최댓값은 987... 부터 탐색
	//뽑힌 조합으로 순열 만들기
	//순열에서 나온 수가 부등호에 맞으면 break;
	//최대 최소 출력

	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		input += temp;
	}

	//최솟값 구하기
	stopFlag = false; //초기화
	combi(-1, false); //실행
	for (int i = 0; i < com.size(); i++) {
		ret_min += com[i]; //결과 대입
	}

	//최댓값 구하기
	stopFlag = false; com.clear(); //초기화
	reverse(number.begin(), number.end()); //내림차순을 위한 reverse()
	combi(-1, true); //실행, 내림차순 flag : true
	for (int i = 0; i < com.size(); i++) {
		ret_max += com[i]; //결과 대입
	}

	//출력
	cout << ret_max << "\n" << ret_min << "\n";


	return 0;
}