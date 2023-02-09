#if 1
// 벨만포드는 음의 가중치가 있어도 가능하다. 
// 다익스트라는 BFS를 기본으로 가지고 나온 것이다. 
#include<cstdio>
#include<algorithm>
#define INF 9876654321
using namespace std;

int N, M;
long long d[501];
struct e_t {
	int From, To, Cost;
}E[6001];

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	fill(d, d + 501, INF);
	for (int j = 0; j < M; j++) {
		scanf("%d %d %d", &E[j].From, &E[j].To, &E[j].Cost);
	}

	bool isCycle = false;
	d[1] = 0;

	// N-1 돌리기 
	for (int i=0; i < N-1; i++) {
		for (int j = 0; j < M; j++) {
			if (d[E[j].From] == INF) continue;
			if (d[E[j].To] > d[E[j].From] + E[j].Cost)  d[E[j].To] = d[E[j].From] + E[j].Cost;
		}
	}

	//변하는 것 check 하기 
	for (int j = 0; j < M; j++) {
		if (d[E[j].From] == INF) continue;
		if (d[E[j].To] > d[E[j].From] + E[j].Cost) { 
			isCycle = true; 
			break;
		}
	}

	if (isCycle) printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) { // 2번 도시에서 출발하는 것 이기 때문에  2부터 시작 
			printf("%lld\n", d[i] >= INF ? -1 : d[i]);
		}
	}
	return 0;
}
#endif