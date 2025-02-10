#include <bits/stdc++.h>
using namespace std;

const int MAX = 1004;
int n, state, number = 1;
int triangle[MAX][MAX];
vector<int> solution;

void fillTriangle(int n) {
    int y = -1, x = 0; // 첫 번째 이동에서 y를 0부터 시작하기 위해 -1로 설정
    
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            switch (state % 3) {
                case 0: // 아래로 이동
                    y += 1;
                    break;
                case 1: // 오른쪽으로 이동
                    x += 1;
                    break;
                case 2: // 왼쪽 위 대각선 이동
                    y -= 1;
                    x -= 1;
                    break;
            }
            triangle[y][x] = number++;
        }
        state++; // 이동 방향 변경
    }

    return;
}

void makeSolution() {
    for(int i = 0; i < n; i++) {        
        solution.insert(solution.end(), triangle[i], triangle[i] + i + 1);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n;

    // 삼각형 배열 채우기
    fillTriangle(n);

    // 삼각형 배열을 vector에 차례로 담기
    makeSolution();
    
    //출력
    for (int num : solution) {
        cout << num << " ";
    }

    return 0;
}

// 프로그래머스 제출
// 틀린 이유 : 전역으로 선언된 n이 전역 변수로 사용한 n과 solution 변수 이름이 중복되어 문제가 발생
// 프로그래머스에서 문제를 풀기 전에 주어진 매개 변수와 함수 이름을 주의
// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 1004;
// int num, state, number = 1;
// int triangle[MAX][MAX];
// vector<int> result;

// void fillTriangle(int n) {
//     int y = -1, x = 0; // 첫 번째 이동에서 y를 0부터 시작하기 위해 -1로 설정
    
//     for(int i = n; i > 0; i--) {
//         for(int j = 0; j < i; j++) {
//             switch (state % 3) {
//                 case 0: // 아래로 이동
//                     y += 1;
//                     break;
//                 case 1: // 오른쪽으로 이동
//                     x += 1;
//                     break;
//                 case 2: // 왼쪽 위 대각선 이동
//                     y -= 1;
//                     x -= 1;
//                     break;
//             }
//             triangle[y][x] = number++;
//         }
//         state++; // 이동 방향 변경
//     }

//     return;
// }

// void makeSolution() {
//     for(int i = 0; i < num; i++) {        
//         result.insert(result.end(), triangle[i], triangle[i] + i + 1);
//     }

//     return;
// }

// vector<int> solution(int n) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
    
//     num = n;
    
//     // 삼각형 배열 채우기
//     fillTriangle(n);
    
//     // 삼각형 배열을 vector에 차례로 담기
//     makeSolution();
    
//     return result;
// }
