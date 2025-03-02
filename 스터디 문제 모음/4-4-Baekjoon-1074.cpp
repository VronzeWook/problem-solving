#include<bits/stdc++.h>
using namespace std;

const int MAX = 333333;;
int ret, N, r, c, n = 1;

void findZ(int n, int y, int x){

    // 도착했는지 확인
    if (n == 1) {
        return;
    }

    int cumulation = 0;
    // 몇 사분면에 있는지 체크
    if (y < n/2 && x < n/2) {
        cumulation = 0;
    } else if (y < n/2 && x >= n/2) {
        cumulation = n/2 * n/2;
        x -= n/2;
    } else if (y >= n/2 && x < n/2) {
        cumulation = (n/2 * n/2) * 2;
        y -= n/2;
    } else if (y >= n/2 && x >= n/2){
        cumulation = (n/2 * n/2) * 3;
        y -= n/2; x -= n/2;
    }

    ret += cumulation;

    findZ(n/2, y, x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // r행 c열
    cin >> N >> r >> c;

    for(int i = 0; i < N; i++) n *= 2;

    findZ(n, r, c);

    cout << ret;

    return 0;
}
