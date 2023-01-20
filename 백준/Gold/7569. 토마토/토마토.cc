#if 1
#include<iostream> 
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>

#define X first
#define Y second
using namespace std;

int n, m, h;
int vis[102][102][102]; // 높이 세로 가로 순서 
int board[102][102][102]; // 높이 세로 가로 순서 
queue<pair<int, pair<int,int>>> q;
// dx dy dz 도 정의해야 한다. 
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> h;


    //fill(&vis[0][0][0], &vis[101][102][102], -1); // input 받기 
    fill_n(&vis[0][0][0], 102 * 102 * 102, -1);

    for (int k = 0; k < h; k++) { // input 받기 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[k][i][j];
                if (board[k][i][j] == 1) {
                    q.push({ k,{i,j} });
                    vis[k][i][j] = 0;
                }
                else  if (board[k][i][j] == -1) {
                    vis[k][i][j] = 0;
                }
            }
        }
    }
       
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = cur.Y.X + dx[i];
            int ny = cur.Y.Y + dy[i];
            int nz = cur.X + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
            if (vis[nz][nx][ny] != -1)continue;
            vis[nz][nx][ny] = vis[cur.X][cur.Y.X][cur.Y.Y]+1;
            q.push({ nz, {nx,ny} });

        }
    }

    int ans = 0;
    for (int k = 0; k < h; k++) { 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[k][i][j] == -1) {
                    cout << -1 << "\n";
                    return 0;
                }
                ans = max(ans, vis[k][i][j]);
            }
        }
    }

    cout << ans<<"\n";
   
    return 0;
}
#endif