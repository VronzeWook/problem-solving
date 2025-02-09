#include<bits/stdc++.h>
using namespace std;

const int MAX = 30; // 최대 25
int n, result;
char mp[MAX][MAX];
int visited[MAX][MAX];
int my[4] = {1, 0, -1, 0}, mx[4] = {0, 1, 0, -1};
vector<int> totalCount;

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    int count = 1;
    visited[y][x] = 1;
    q.push({y, x});

    while(q.size()){
        // cout << "in while" << "\n";
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d++) {
            int ny = my[d] + nowy;
            int nx = mx[d] + nowx;
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || mp[ny][nx] == '0') continue;
            visited[ny][nx] = 1;
            count ++;
            q.push({ny, nx});
        }
    }

    // 노드 개수를 기록
    totalCount.push_back(count);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 사고 과정
    // 지도에서 지도 값이 1이면서, 방문하지 않은 곳이라면 탐색 시작
    // 탐색 중 visited를 기록할 때마다 해당 단지 내 집 count를 증가
    // 탐색이 끝나면(Queue가 비면) count를 vector에 추가
    // vector의 size와 요소를 정렬 후 출력

    // 틀린 부분 : map 입력 시 자료형
    // 한 줄의 문자열 단위로 입력되기 때문에 분리해서 배열에 넣어줘야함
    // char형 배열로 입력을 받아 자동으로 분리되었지만, 조건을 검사할 때도 char형으로 해줬어야 했음

    // 입력
    cin >> n;

    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }
    
    // 맵 순회
    for(int i = 0 ; i < n; i++ ) {
        for(int j = 0 ; j < n; j++) {
            if (visited[i][j] || mp[i][j] == '0') continue;
            BFS(i, j);
        }
    }

    // 정렬
    sort(totalCount.begin(), totalCount.end());

    // 출력
    cout << (int)totalCount.size() << "\n";
    for( int i = 0 ; i < totalCount.size(); i ++) {
        cout << totalCount[i] << "\n";
    }
    
    return 0;
}