#if 1
// c++ struct는 C의 구조체를 담고 있고 더 나아가 확장된 개념이다. 
// c++에서 struct와 class의 차이점?? 
// struct는 접근제어자가 기본으로 public이고 class는 private 이다. 

#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits> // INT_MAX가능 백준에서는 안될 수 있음 
#define INF 1000000

using namespace std;
int V, E, K, start; 
int d[20001];
vector<pair<int, int>> graph[20001];


void dij(int start_node) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start_node });
	d[start_node] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (d[curr] < cost) continue;

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int ncost = graph[curr][i].second;

			if (cost + ncost < d[next]) {
				d[next] = cost + ncost;
				pq.push({ -d[next], next });
			}

		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	scanf("%d", &start);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
	}

	// 초기화 
	fill(d, d + 20001, INF);
	dij(start);

	// 출력
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) printf("INF\n");
		else { printf("%d\n", d[i]); }
	}

	return 0;
}
#endif

