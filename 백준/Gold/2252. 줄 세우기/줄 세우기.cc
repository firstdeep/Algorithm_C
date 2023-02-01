#if 1 
// 줄 세우기 
// 위상정렬: 방향성이 있고 사이클이 없다. 또한 값이 여러개가 나올 수 있다. 
// 나한테 화살을 쏘는 간선이 몇개이냐
// 구현: 저장까지는 ok -> search 를 통해서 진행하면 n^2이 나올 것 같은데.. n^2을 n으로 어떻게 바꿀 수 있을까?... 
// 포인트1: 인접리스트 구현 - vector로 구현 
// 포인트2: in-degree 배열 작성방법 생각해보기 - 배열로 선언 
// 포인트3: 위상 정렬 프로그래밍 방법 - Queue를 사용한다. 
#include<cstdio> 
#include<numeric>
#include<vector>
#include<queue>
using namespace std;

int n, m, a,b;
int inDegree[32001];
vector<int> graph[32001];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		inDegree[b]++; // 선택을 받은 것의 degree를 늘려준다.
		//seg[b].push_back(a); // 만약 방향성이 있으면 양쪽 방향성을 해줘야 한다. 
	}

	queue<int> q; // q선언해서 0인 것부터 즉 하나도 선택 못받은 것 부터 출력한다. 
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int curr = q.front(); // 0 인것 부터 출력한다. 
		q.pop();
		printf("%d ", curr); // 0 인것 즉 선택 안받은 것 부터 출력하고 출력을 했으니 indegree 차수 내려주기 
		for (int node : graph[curr]) {
			if (--inDegree[node] == 0) q.push(node);
		}
	}

	return 0;
}
#endif