#include<bits/stdc++.h>
using namespace std;

const int MAX = 1024;
int arr[MAX], k, n;
vector<int> bi_tree[13];

void make_bi(int _begin, int _end, int _layer){
	//리프 노드 도달 시 추가
	if (_layer == k) {
		bi_tree[_layer].push_back(_end);
		return;
	}

	//피벗 구하기
	int pivot = (_begin + _end) / 2;

	bi_tree[_layer].push_back(arr[pivot]);
	//왼쪽 탐색
	make_bi(_begin, pivot - 1, _layer + 1);
	//오른쪽 탐색
	make_bi(pivot + 1, _end, _layer + 1);

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	//입력
	cin >> k;
	n = pow(2, k) - 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//이진 트리 만들기
	make_bi(0, n - 1, 0);
	
	//출력
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < bi_tree[i].size(); j++) {
			cout << bi_tree[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}