#if 1
// 모든 알고리즘 문제가 어떻게 풀지 알고 보면 그 이후부터는 구현 문제이다. 
// 따라서 문제를 어떻게 풀어야 하는지 어떤 유형인지를 파악하는 능력과 구현하는 능력을 기르자. 
// 위상정렬 문제 - 키순서 
// 위상정렬 컨셉을 가져가면서 순위를 알아야 겠다... 
// 이거는 위상정렬 진행하면 어떻게 접근하는지에 결과가 변하는데 결과가 딱 변하지 않는 값이 몇개인지를 찾는게 목표 
// 위상정렬 DFS? 
// 핵심: 순서를 어떻게 알 것인가 부터 생각했어야 했다... 
// 키큰사람 수 + 키 작은사람 수를 더한 것이 N-1이 되면 자신의 키 순서를 확정할 수 있다. 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, ans;
const int idx = 501;
int info[idx][idx],cnt[idx];
bool visit[idx];

void init(bool* arr) {
	for (int i = 0; i < idx; i++) visit[i] = false;
}

void DFS(int src, int next) {
	if (src != next) { // 자신이랑 같을 경우도 있으니까 그걸 exception 으로 빼줘야 한다. 
		cnt[src]++;
		cnt[next]++;
	}
	visit[next] = true;
	for (int i = 1; i <= N; i++) { // 숫자를 돌면서 
		if (!visit[i] && info[next][i]) { // 방문하지 않고 포인트가 가르키고 있는 것이 클 경우 (1로 표시) 
			DFS(src, i);
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		info[a][b] = 1; // a는 b보다 작다. 
	}
	
	for (int i = 1; i <= N; i++) {
		init(visit);
		DFS(i, i);
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == N - 1) ans++;
	}

	printf("%d\n", ans);
	return 0;
}
#endif