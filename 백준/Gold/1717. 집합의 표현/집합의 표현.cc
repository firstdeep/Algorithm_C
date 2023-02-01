#if 1
#include<cstdio> 
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;
int n, m;
vector<int> graph; // 굳이 pair를 사용할 필요가 없네 어차피 index로 접근하는 것 자체가 index를 가지고 있고 그 안에 값만 변경 

int find(int node) { // 재귀로 진행
	if (graph[node] == node) return node;
	else return graph[node] = find(graph[node]); // 해당 값에서 return 값으로 대체 
}

void uni(int a, int b) { // 합친다는 것은 find에서 좌표 값을 가지고 와서 해당 값을 다른 좌표에 할당한다. 
	int pa = find(a);
	int pb = find(b);
	graph[pb] = pa;
}

int main() {
	scanf("%d %d", &n, &m);
	graph.resize(n+1);
	// graph init이 필요한가? 
	iota(graph.begin(), graph.end(), 0);

	for (int i = 0; i < m; i++) {
		int temp, a, b;

		scanf("%d %d %d", &temp, &a, &b);

		if (temp == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b))printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
#endif