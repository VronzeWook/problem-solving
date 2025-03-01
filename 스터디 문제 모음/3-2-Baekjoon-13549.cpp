#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int pos, target;

int bfs() {
    queue<int> q;
    vector<int> timeStamp(MAX + 1, -1);

    timeStamp[pos] = 0;
    q.push(pos);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == target) return timeStamp[cur];

        // 순간 이동 (*2) 후 목표 지점 도달 여부 확인
        int pos_double = cur * 2;
        if (pos_double <= MAX && timeStamp[pos_double] == -1) {
            timeStamp[pos_double] = timeStamp[cur]; // 순간 이동은 시간 증가 없음
            if (pos_double == target) return timeStamp[pos_double];  // 목표 도달 확인
            q.push(pos_double);
        }

        // -1 이동
        if (cur - 1 >= 0 && timeStamp[cur - 1] == -1) {
            timeStamp[cur - 1] = timeStamp[cur] + 1;
            q.push(cur - 1);
        }

        // +1 이동
        if (cur + 1 <= MAX && timeStamp[cur + 1] == -1) {
            timeStamp[cur + 1] = timeStamp[cur] + 1;
            q.push(cur + 1);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> pos >> target;
    cout << bfs();
    return 0;
}
