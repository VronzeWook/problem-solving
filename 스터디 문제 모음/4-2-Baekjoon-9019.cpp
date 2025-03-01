#include<bits/stdc++.h>
using namespace std;

const int MAX = 10001, DIR = 4;
string path[MAX];
bool visited[MAX];
int a, b, T;
char command[DIR] = {'D', 'S', 'L', 'R'};

int commandDSLR(int n, int cmd) {
    switch (cmd) {
    case 0:
        return (2 * n) % 10000;
    case 1:
        return (n == 0) ? 9999 : n - 1;
    case 2:
        return (n % 1000) * 10 + n / 1000;
    case 3:
        return (n % 10) * 1000 + n / 10;
    }
    return -1;
}

string bfs() {
    queue<int> q;
    q.push(a);
    visited[a] = true;
    path[a] = "";

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        // 4방향 탐색
        for(int d = 0; d < DIR; d++) {
            int nx = commandDSLR(x, d);
            if (visited[nx]) continue;
            visited[nx] = true;
            path[nx] = path[x] + command[d];
            q.push(nx);

            if(nx == b) return path[nx];
        }
    }
    return "failed";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for(int t = 0; t < T; t++) {
        fill(&visited[0], &visited[MAX], false);
        cin >> a >> b;

        cout << bfs() << "\n";
    }

    return 0;
}