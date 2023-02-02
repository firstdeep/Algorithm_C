#if 1 
// 게임 개발, 위상 정렬 일을 처리할 때 순서를 정하는 정렬 
// 동시에 빌딩을 올리 수 도 있다. 
// 구현: Tip 
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int max_idx = 501;
int N;
int build_time[max_idx], inDegree[max_idx];
int result[max_idx];
vector<int> V[max_idx];
// v에다가 list를 깔아주고, build time에는 time 저장하고 Degree에는 얼마나 선택되었는지 저장하기 

int bigger(int a, int b) { if (a > b) return a; return b; }
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &build_time[i]);
		while (1) {
			int a; 
			scanf("%d", &a);
			if (a == -1) break;
			V[a].push_back(i); // 화살표가 현재 건물쪽으로 가야한다. 
			inDegree[i]++; // 화살표가 현재 건물이기 때문에 해당 degree를 ++ 해놓는다. 
		}
	}
	// 세팅 완료 
	
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!inDegree[i]) { // 0인 것은 여기서 건물 번호이다. 건물 번호다
			q.push(i);
			result[i] = build_time[i];
		}// 0인 것 뽑기
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < V[cur].size(); i++) { // cur를 짓기 위해서는 V와 같은 건물 개수가 필요하다. 
			int next = V[cur][i];
			inDegree[next]--;
			result[next] = bigger(result[next], result[cur] + build_time[next]); // 특정 건물을 짓기 위한 시간은 
			if (!inDegree[next]) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++) printf("%d\n", result[i]);

	return 0;
}
#endif
