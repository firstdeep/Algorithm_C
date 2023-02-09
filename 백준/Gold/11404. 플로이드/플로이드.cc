#if 1
// https://www.acmicpc.net/problem/11404 
// 플로이드 워셜 문제 
// 문제 잘 읽기 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다...
#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 987654321 // 2개 더하니까 overflow 발생 

using namespace std;

int N, M;
int d[101][101];

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	
	// 초기화 
	for (int i = 1; i <= N; i++) { // 굳이 다 할 필요가 없다. 
		for (int j = 1; j <=N; j++) {
			d[i][j] = INF;
		}
	}
	
	// 대각행렬 0 으로 정렬 
	for (int i = 1; i <= N; i++) {
		d[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = min(d[a][b], c);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//printf("%d ", d[i][j] == INF ? 0 : d[i][j]);
			printf("%d%c", d[i][j] == INF ? 0 : d[i][j], j == N ? '\n' : ' ');
		}
	}
	return 0;
}
#endif