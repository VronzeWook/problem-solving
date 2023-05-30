#include<bits/stdc++.h>
using namespace std;
int bill[3];
int ai, ao, bi, bo, ci, co;
int sum, cur_bill, car;
int main() {
	cin >> bill[0] >> bill[1] >> bill[2];
	cin >> ai >> ao >> bi >> bo >> ci >> co;
	for (int i = 1; i < 100; i++) {
		if (ai == i) car++;
		if (bi == i) car++;
		if (ci == i) car++;
		if (ao == i) car--;
		if (bo == i) car--;
		if (co == i) car--;
		if (car == 0) cur_bill = 0;
		else
		{
			cur_bill = bill[car - 1];
			sum += cur_bill * car;
		}
	}
	cout << sum;
}