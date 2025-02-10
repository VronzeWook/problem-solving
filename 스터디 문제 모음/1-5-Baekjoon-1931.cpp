#include<bits/stdc++.h>
using namespace std;

const int MAX = 100004;
pair<int, int> table[MAX];
int n, result, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 가장 많은 회의를 진행할 수 있는 수
    // 가정) 가장 빨리 끝나는 회의를 선택하는 것이 최적해
    // 증명?) 가장 빨리 끝나는 회의 이후의 회의를 선택해서 최대값을 구하더라도, 가장 빨리 끝나는 회의와 시간차 x
    // 끝나는 시간이 같다면, 시작 시간이 큰 회의를 선택
    
    //입력
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> table[i].second >> table[i].first;
    }
    
    // 정렬
    sort(table, table + n);

    // 값 찾기
    for(int i = 0; i < n; i++) {
        if (t > table[i].second) continue; // 현재 시간보다 시작 시간이 작다면
        result ++;
        t = table[i].first;
    }

    cout << result;

    return 0;
}