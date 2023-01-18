#if 1
#include<queue>
#include<iostream>
#include<algorithm> 
using namespace std;

// 미로는 거리를 저장하는 배열을 하나더 생성한다. -1을 초기화 하면 vis배열이 굳이 필요가 없다. 
#define X first
#define Y second 

string board[102];
int dis[102][102];

int n, m, max_temp;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) { // 입력 받기 
		cin >> board[i];
	}
	for (int i = 0; i < n; i++) fill(dis[i], dis[i] + m, -1);

	queue<pair<int, int>> Q;
	dis[0][0] = 0;
	Q.push({ 0,0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dis[nx][ny]>=0 || board[nx][ny] != '1')continue; // 다 -1로 처리를 해놨으니까 
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	cout << dis[n - 1][m - 1] + 1<<"\n";

}
#endif