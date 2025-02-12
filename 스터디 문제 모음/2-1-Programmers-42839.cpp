// numbers는 길이 1 이상 7 이하인 문자열입니다.
// numbers는 0~9까지 숫자만으로 이루어져 있습니다.
// "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

// 소수 =>  에라토스테네스의 체
// 조합할 수 있는 가장 큰 수를 찾아
// 해당 숫자까지 에라토스테네스의 체를 배열에 만들고 에라토스테네스의 체는 O(NloglogN)
// 숫자로 조합하며 소수인지 확인

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000004; // 천만
string input, current;
vector<int> nums;
set<int> ret;
bool mp[MAX], visited[9999];

void combi(string cur) {
    // 현재 조합 배열이 있다면 소수 여부를 체크해서 기록, 비어있다면 패스
    if(!cur.empty() && !mp[stoi(cur)] ) {
        ret.insert(stoi(cur)); }

    // 방문하지 않았던 노드에 방문
    // i번 노드에 방문 표시
    // combi()에 인덱스를 넣어서 재귀 호출
    // i번 노드 방문 표시 제거
    for(int i = 0; i < input.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        combi(cur + input[i]);
        visited[i] = false;
    }

    return;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> input;
    for(int i = 0; i < input.size(); i++ ) nums.push_back(input[i] - '0');
    sort(nums.begin(), nums.end(), greater<int>());
    
    // 에라토스테네스의 체
    mp[0] = mp[1] = true;
    for(int i = 2; i < MAX; i++) {
        if(mp[i]) continue;
        for(int j = i + i; j < MAX; j += i) {
            mp[j] = true;
        }
    }

    // 조합 찾으며 소수인지 검사
    combi(current);

    // 출력
    cout << ret.size(); 

    return 0;
}

// 프로그래머스 풀이
// #include<bits/stdc++.h>
// using namespace std;

// const int MAX = 10000004; // 천만
// string input, current;
// vector<int> nums;
// set<int> ret;
// bool mp[MAX], visited[9999];

// void combi(string cur) {
//     if(!cur.empty() && !mp[stoi(cur)] ) {
//         ret.insert(stoi(cur)); }
    
//     for(int i = 0; i < input.size(); i++) {
//         if(visited[i]) continue;
//         visited[i] = true;
//         combi(cur + input[i]);
//         visited[i] = false;
//     }

//     return;
// };

// int solution(string numbers) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     // 입력
//     input = numbers;
//     for(int i = 0; i < input.size(); i++ ) nums.push_back(input[i] - '0');
//     sort(nums.begin(), nums.end(), greater<int>());
    
//     // 에라토스테네스의 체
//     mp[0] = mp[1] = true;
//     for(int i = 2; i < MAX; i++) {
//         if(mp[i]) continue;
//         for(int j = i + i; j < MAX; j += i) {
//             mp[j] = true;
//         }
//     }

//     // 조합 찾으며 소수인지 검사
//     combi(current);

//     // 출력
//     return ret.size();
// }