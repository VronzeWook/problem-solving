#include<iostream>
using namespace std;
typedef long long ll;
ll a, b, c;

ll run(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll n = run(a, b / 2, c) % c;
	n = (n * n) % c;
	if (b % 2) n =  (n * a % c)% c;
	return n;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	cout << run(a, b, c);

	return 0;
}