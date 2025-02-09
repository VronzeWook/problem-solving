// 문제 : https://school.programmers.co.kr/learn/courses/30/lessons/60057

#include<bits/stdc++.h>
using namespace std;

int result = INT_MAX; // 문자열 최대 입력 길이 1000이므로 초과 값을 min값으로 설정
string input = "";
string output = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 문자열 입력 받기
    cin >> input;

    // 3) 틀린 반례 : 한 글자 입력
    // 한 글자 입력 시 반복문에 아에 진입 x, 예외 처리 필요
    // 처음에 입력을 받고 result를 갱신해주는 로직 추가
    result = input.length();

    // 1) 첫 번째 사고 과정
    // 문자열의 문자 개수(n)만큼 반복문을 작성하여, 여러 문자 갯수 단위로 압축하도록
    // 마지막에는 반환할 가장 짧은 문자열의 개수를 갱신
    // 한번에 압축할 문자의 개수는 n의 절반 이상이 될 수 없음!
    // 1개(압축하지 않은 것) ~ (n / 2)개 까지 반복
    // (추측) 압축 시 (n / 2) 시간 복잡도 예상
    // 총 시간 복잡도 ( n^2 / 4) 으로, (n 최댓값) 1000000 / 4 = 250000 예상
    // 10,000,000 이하는 크게 고려하지 않아도 됌!
    
    for(int i = 1; i <= input.length() / 2; i++) {
        string compressed = "";
        string inputTemp = input;

        // 2) 두 번째 사고과정
        // inputTemp 앞의 문자 i개가 몇번 반복되는지 확인
        // (반복되는 횟수 + 반복된 문자열) 문자열을 compressed 변수에 추가
        // (반복되는 횟수 * 문자열 개수(i))개수 만큼 inputTemp 앞에서 문자 제거
        // inputTemp에 남은 문자 개수가 (i * 2) 미만이 되면 종료
        // compressed의 문자열 길이와 현재까지 최소치를 비교하여 최솟값 갱신

        while(inputTemp.length() >= i * 2) {
            string temp = "";
            int count = 0;

            do {
            count ++;
            temp = inputTemp.substr(0, i); // 0부터 i개를 문자를 복사
            inputTemp.erase(0, i);
            } while (temp == inputTemp.substr(0, i));

            if (count != 1) { compressed += to_string(count); }
            compressed += temp;
        }

        compressed += inputTemp;

        // cout << i << "개 씩 압축된 문자열 : " << compressed << "\n";

        result = min(result, (int)compressed.length());
    }

    cout << result;

    return 0;
}

// 프로그래머스 제출 코드
// #include<bits/stdc++.h>
// using namespace std;

// int result = INT_MAX; // 문자열 최대 입력 길이 1000이므로 초과 값을 min값으로 설정
// string input = "";
// string output = "";

// int solution(string s) {
//     ios_base::sync_with_stdio(false);
//  cin.tie(NULL); cout.tie(NULL);

//     input = s;
//     result = s.length();

//     for(int i = 1; i <= input.length() / 2; i++) {
//         string compressed = "";
//         string inputTemp = input;

//         while(inputTemp.length() >= i * 2) {
//             string temp = "";
//             int count = 0;

//             do {
//             count ++;
//             temp = inputTemp.substr(0, i); // 0부터 i개를 문자를 복사
//             inputTemp.erase(0, i);
//             } while (temp == inputTemp.substr(0, i));

//             if (count != 1) { compressed += to_string(count); }
//             compressed += temp;
//         }

//         compressed += inputTemp;
//         result = min(result, (int)compressed.length());
//     }
//     return result;
// }
