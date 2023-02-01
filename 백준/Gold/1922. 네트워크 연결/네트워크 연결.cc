#if 1
// 트리는 정점이 N개 간선이 N-1개 있다. 
// 크루스칼 알고리즘
// 백준 네트워크 연결 문제 
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int N, M, graph[1001];

int find(int node){
	if (graph[node] == node) return node;
	else return graph[node] = find(graph[node]);
}
void join(int a, int b) { // 이게 왜 필요??
	int A = find(a), B = find(b);
	graph[B] = A;
}

struct MyStruct
{
	int a, b, weight;
}Edge[100000];

bool compare(const MyStruct& p1, const MyStruct& p2) {
	return p1.weight < p2.weight;
}

int main() {
	scanf("%d %d", &N, &M); // 줄이 떨어져 있어도 공백이 화이트 스페이트 역할을 한다. 
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &Edge[i].a, &Edge[i].b, &Edge[i].weight);
	}
	// graph 초기화 
	for (int i = 1; i <= N; i++)graph[i] = i;
	// 구조체 sort 하는 법 
	sort(Edge, Edge + M, compare);
	// 크루스칼 알고리즘 돌리기 
	int Ans = 0;
	for (int i = 0; i < M; i++) { // 모든 간선에 대해서 가장 최소 값들만 더하기
		if (find(Edge[i].a) == find(Edge[i].b)) continue;
		join(Edge[i].a, Edge[i].b); // 이미 가장 최소값으로 정렬이 되어있으니까 join을 통해서 정점이 이어진 간선이라고 통일
		Ans += Edge[i].weight;
	}
	printf("%d\n", Ans);
	return 0;
}
#endif