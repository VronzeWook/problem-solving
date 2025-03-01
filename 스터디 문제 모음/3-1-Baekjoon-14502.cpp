#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;
int n, m, ret;
bool visited[MAX][MAX];
int mp[MAX][MAX], mp_copy[MAX][MAX];
int dy[4] = {1, 0 , -1, 0}, dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> safeArea;
vector<int> wall;

void virusSpreadDFS(int (&mp_temp)[MAX][MAX], int y, int x){
    if (mp_temp[y][x] == 1 ) { return; }
    mp_temp[y][x] = 2;

    for(int i = 0 ; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || mp_temp[ny][nx] != 0) continue; 
        virusSpreadDFS(mp_temp, ny, nx);
   }
}

void combi(int depth, int start) {
    if (depth == 3 ) {
        memcpy(mp_copy, mp, sizeof(mp));
        for(int i = 0; i < wall.size(); i++) {
            int y = safeArea[wall[i]].first;
            int x = safeArea[wall[i]].second;
            mp_copy[y][x] = 1;
        }

        // 바이러스 뿌리기
        for(int i = 0; i < n; i ++){
            for(int j = 0 ; j < m; j++ ){
                if (mp_copy[i][j] != 2) continue;
                virusSpreadDFS(mp_copy, i, j);
            }
        }

        // 안전 지대 개수 체크
        int count = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j++){
                if(mp_copy[i][j] == 0) count ++;
            }
        }

        ret = max(ret, count);
        return;
    }

    // 해당 인덱스 좌표를 벽으로
        for(int i = start; i < safeArea.size(); i ++) {
            wall.push_back(i);
            combi(depth + 1, i + 1);
            wall.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        for(int j = 0 ; j < m; j++) {
            cin >> mp[i][j];
            mp_copy[i][j] = mp[i][j];
            if (mp[i][j] == 0) { safeArea.push_back({i, j}) ;}
            }
    }

    // 조합하고 벽 세운 후, 바이러스 퍼뜨리고, 개수 체크
    combi(0, 0);

    // 출력 
    cout << ret;

    return 0;
}