#if 1 
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 40000
using namespace std;
int n, m, visited[MAX_N + 1], dph[MAX_N + 1], par[MAX_N + 1][20], dist[MAX_N + 1], x, y, z;
vector<vector<pair<int, int>>>vt;
void dfs(int v, int dh, int dis) {
	visited[v] = true;
	dph[v] = dh;
	dist[v] = dis;
	for (auto u : vt[v]) {
		if (visited[u.first])
			continue;
		dfs(u.first, dh + 1, dis + u.second);
		par[u.first][0] = v;
	}
}
void f() {
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
	}
}
int lca(int x, int y) {
	if (dph[x] > dph[y])
		swap(x, y);
	for (int i = 19; i >= 0; i--) {
		if (dph[y] - dph[x] >= (1 << i))
			y = par[y][i];
	}
	if (x == y)return x;
	for (int i = 19; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}
int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	vt.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &x, &y, &z);
		vt[x].push_back({ y,z });
		vt[y].push_back({ x,z });
	}
	dfs(1, 0, 0);
	f();
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		int qlca = lca(x, y);
		printf("%d\n", dist[x] + dist[y] - 2 * dist[qlca]);
	}
	return 0;
}

#endif