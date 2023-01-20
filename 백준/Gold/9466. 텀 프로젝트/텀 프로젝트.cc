#if 1
#include<iostream> 
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>

// 텀 프로젝트 
// 핵심은 연결되어 있는 것을 어떻게 구현할 것인가?.. 
// 4 - 7 - 6 - 4는 하나의 팀이다. 이것을 원형 큐? 아니면 set? 


using namespace std;

int T, n;
int arr[1000002];
bool vis[1000002]; // 다 0으로 초기화 된다. false 
bool done[1000002]; // 변수 하나 추가 

int dx[2] = { 1,-1 };
int cnt;

void DFS(int n) {
	vis[n] = true;
	int next = arr[n];
	if (!vis[next])
		DFS(next);
	else if (!done[next]) {
		cout << next;
		// 사이클 검사 -> 방문 했던 점들 중 끝나지는 않았다면 무조건 사이클!
		for (int i = next; i != n; i = arr[i]) 
			//6이 가르키는 것부터 시작해서 6이 아닐때까지 i를계속 돌린다음 
			cnt++; 
		cnt++; // 최종적으로 6일때 자기 자신을 count한 것이다. 
	}
	done[n] = true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	scanf("%d ", &T);
	while (T--) {

		scanf("%d ", &n);
		for (int i = 1; i <= n; i++) { //index 1부터 시작이니까 헷깔리지 않도록 1부터 시작 
			scanf(" %d", &arr[i]);
		}
		//bfs 진행 어차피 1차원 이기 때문에 +1, -1 컨셉 사용 
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				DFS(i);
			}
		}
		printf("%d\n", (n - cnt));
		//다음 case를 위한 초기화
		cnt = 0;
		memset(vis, false, sizeof(vis)); // fill(done, done+100001, false);
		memset(done, false, sizeof(done));
	}

	return 0;
}
#endif
