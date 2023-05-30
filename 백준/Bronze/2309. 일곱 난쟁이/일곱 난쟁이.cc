#include<bits/stdc++.h>
using namespace std;

const int SUM = 100;
int smp[9];

void print_ans(int arr[]) {
	sort(&arr[0], &arr[0] + 7);
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << "\n";
	}
	return;
}

bool find_seven(int arr[]) {
	int temp[7];
	fill(&temp[0], &temp[0] + 7, 0);
	bool ans_flag = false;
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += arr[i];
		}
		if (sum == SUM) {
			ans_flag = true;
			break;
		}
	} while (next_permutation(&arr[0], &arr[9]));

	if (ans_flag) {
		print_ans(arr);
		return 0;
	}
	return 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> smp[i];
	}

	sort(&smp[0], &smp[0] + 9);
	
	find_seven(smp);

	return 0;
}