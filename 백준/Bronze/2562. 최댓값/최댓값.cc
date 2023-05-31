#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<pair<int, int>> input; int temp = 0;
	for (int i = 0; i < 9; i++) {
		cin >> temp;
		input.push_back({ temp, i + 1 });
	}
	sort(input.begin(), input.end());
	cout << input[8].first << "\n" << input[8].second;
	return 0;
}