#include <bits/stdc++.h>
using namespace std;

const int MAX = 101, DIR = 6; // 배열 인덱스가 아닌 문제 숫자에 맞춰 배열 사용
int visited[MAX], moveTo[MAX], mx[DIR] = {1, 2, 3, 4, 5, 6};
int n, m, t1, t2, ret;

int bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    // n번만에 도착할 수 있는지 탐색
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        // 갈 수 있는 6방향 탐색
        for (int d = 0; d < DIR; d++) {
            int nx = x + mx[d];
            if (visited[nx] || nx >= MAX) continue;

            // 뱀, 사다리가 아닐 경우 기록
            visited[nx] = visited[x] + 1;
            if (!moveTo[nx]) q.push(nx);

            // 뱀, 사다리를 만났을 때
            if (visited[moveTo[nx]]) continue;
            visited[moveTo[nx]] = visited[nx];
            q.push(moveTo[nx]);
        }

        // 100번 째를 방문하면 리턴
        if (visited[MAX - 1]) return visited[MAX - 1] - 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        cin >> t1 >> t2;
        moveTo[t1] = t2;
    }

    // 출력
    cout << bfs();

    return 0;
}
