#include<bits/stdc++.h>
using namespace std;

const int MAX = 505;
int triangle[MAX][MAX], dp[MAX][MAX];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 삼각형 숫자 입력
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    // 점화식 생성
    // D[i][j] = max(D[i - 1][j], D[i - 1][j + 1]) + S[i][j]

    // 초기값 설정
    for(int j = 0; j < n; j++) { dp[n - 1][j] = triangle[n - 1][j]; }

    // 테이블 채워가기
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }

    cout << dp[0][0];

    return 0;
}