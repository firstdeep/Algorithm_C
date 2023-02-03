#if 1 
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int N, M,MAXK;
bool visit[50001];
vector<int> ad[100001];
int parent[100001][21], depth[100001];


void DFS(int curr, int d) {
	visit[curr] = true;
	depth[curr] = d;
	for (auto next : ad[curr]) {
		if (!visit[next]) {
			parent[next][0] = curr;
			DFS(next, d + 1);
		}
	}
}
void fillparent() {
	for (int k = 1; k <= MAXK; k++) {
		for (int i = 1; i <= N; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
		}
	}
}


int LCA(int a, int b) {
	if (depth[b] < depth[a]) swap(a, b);
	for (int k = MAXK; k >= 0; k--) {
		int diff = depth[b] - depth[a];
		if (diff >= (1 << k))b = parent[b][k];
	}

	if (a == b) return b;

	for (int k = MAXK; k >=0; k--) {
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
	MAXK = (int)floor(log2(N)); // N까지만 사용하면 최대 높이를 알 수 있다. 
	fillparent();
	

	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
}
#endif