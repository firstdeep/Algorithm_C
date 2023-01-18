#if 1
#include<queue>
#include<iostream>
#include<algorithm> 
using namespace std;

#define X first
#define Y second 

int board[512][512];
bool vis[512][512];
int n, m, max_temp;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) { // 입력 받기 
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int mx = 0; // 크기가 가장 큰 것 
    int num = 0; // 그림의 숫자 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || vis[i][j])continue;
            // 여기 왔다는 것은 그림의 첫번째 수를 찾았다는 것 
            num++;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({ i,j });
            int area = 0;

            while (!Q.empty()) {
                area++;
                pair<int, int> cur = Q.front(); 
                Q.pop();
                for (int dir=0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1)continue;
                    vis[nx][ny] = 1;
                    Q.push({ nx,ny });
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;

}
#endif