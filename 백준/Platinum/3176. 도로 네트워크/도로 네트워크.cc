#if 1
// 도로 네트워크 문제 
// 유일한 경로를 찾아야 한다? - 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구해라 
// 트리라고 정의가 되면 root노드는 내가 정의하기 나름이다. 
// 경로에는 반드시 최소 공통 조상이 존재한다. 

#include <cstdio> 
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

int T, N, M;
vector<pair<int, int>> ad[100001];
bool visit[100001];
int parent[100001][21][3]; // 0은 parent index, 1은 min값, 2는 max 값  
int depth[100001];

void DFS(int curr, int d) {
	visit[curr] = true;
	depth[curr] = d;
	for (auto next : ad[curr]) {
		if (!visit[next.first]) {
			parent[next.first][0][0] = curr;
			parent[next.first][0][1] = next.second;
			parent[next.first][0][2] = next.second;
			// min, max 처리 
			DFS(next.first, d + 1);
		}
	}
}

void fillparent() {
	for (int k = 1; k < 21; k++) {
		for (int i = 1; i <= N; i++) {
			parent[i][k][0] = parent[parent[i][k - 1][0]][k - 1][0]; // 부모 업데이트 완료
			// min, max 업데이트 진행 
			parent[i][k][1] = min(parent[parent[i][k - 1][0]][k - 1][1], parent[i][k - 1][1]);
			// 이거 parent 안에 들어가는 값이 0이 들어가야 한다. 1은 min값이 들어간다... 
			parent[i][k][2] = max(parent[parent[i][k - 1][0]][k - 1][2], parent[i][k - 1][2]);

		}
	}
}

pair<int, int>  LCA(int a, int b) {
	int min_load = INT_MAX;
	int max_load = 0;
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = 20; k >= 0; k--) {
		int diff = depth[a] - depth[b];
		if (diff >= (1 << k)) {
			min_load = min(min_load, parent[a][k][1]);
			max_load = max(max_load, parent[a][k][2]);
			a = parent[a][k][0];
		}

	}

	if (a != b) {
		// 여기서도 서로 min,max 업데이트 한 후에 최종적으로 다시한번 업데이트 필요 
		for (int k = 20; k >= 0; k--) {
			if (parent[a][k][0] != parent[b][k][0]) {
				min_load = min(min_load, min(parent[b][k][1], parent[a][k][1]));
				max_load = max(max_load, max(parent[b][k][2], parent[a][k][2]));
				a = parent[a][k][0];
				b = parent[b][k][0];
			}
		}
		min_load = min(min_load, min(parent[b][0][1], parent[a][0][1]));
		max_load = max(max_load, max(parent[b][0][2], parent[a][0][2]));
	}

	pair<int, int> p_a;
	p_a.first = min_load;
	p_a.second = max_load;
	// return 값 제대로 하자...int면 int 하나만 return 가능하다. 여러개 보낼꺼면 pair 사용
	return p_a;
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ad[a].push_back(make_pair(b, c));
		ad[b].push_back(make_pair(a, c));
	}
	DFS(1, 0);
	fillparent();
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pair <int, int> x = LCA(a, b);
		printf("%d %d\n", x.first, x.second);
	}
	return 0;
}
#endif

