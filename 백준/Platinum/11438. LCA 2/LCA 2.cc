#if 1 
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
int N, M, MAXk;
vector<int> ad[100001];
bool visit[100001];
int parent[100001][21], depth[100001]; // 부모가 누구인지를 저장하는 변수와 depth를 저장하는 변수 

void DFS(int curr, int depth_value) {
	visit[curr] = true;
	depth[curr] = depth_value;
	for (auto next : ad[curr]) {
		if (!visit[next]) {
			parent[next][0] = curr;
			DFS(next, depth_value + 1);
		}
	}
}

void fillparent() {
	for (int k = 1; k <= MAXk; k++) {
		for (int i = 1; i <= N; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}
}

int LCA(int a, int b) {
	if (depth[b] < depth[a]) swap(a, b);
	for (int k = MAXk; k >= 0; k--) {
		int diff = depth[b] - depth[a];
		if (diff >= (1 << k)) b = parent[b][k]; // 부모노드로 할당한다.
	}
	
	if (b == a) return b;

	for (int k = MAXk; k >= 0; k--) {
		if (parent[b][k] != parent[a][k]) {
			b = parent[b][k];
			a = parent[a][k];
		}
	}
	return parent[b][0];
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	DFS(1, 0);
	MAXk = (int)floor(log2(N)); // N까지만 사용하면 최대 높이를 알 수 있다. 
	fillparent();
	
	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
}
#endif