#if 1
#include <cstdio>
#include <iostream>

using namespace std;
using ll = long long;

ll seg[1024 * 1024 * 2]; // 배열 크기: 원래는 N값을 받으면 2^k>=N 이후 2^(K+1) 만큼 배열 잡기
int si = 1;

// Indexed 트리는 bottom up 방식?
void update(int b, ll c) { // b-1한 값을 넘겨 받기 
	b += si; // 값 index 설정 

	seg[b] = c; // 값을 업데이트 해야지 

	while (b > 1) { //for 문으로 하면 안된다. while 
		b /= 2;
		seg[b] = seg[b * 2] + seg[b * 2 + 1];
	}
}

// 최대합 함수 
int sum_arr(int a, int b) { 
	a += si;
	b += si;

	ll res = 0;
	while (a <= b) { // 공식처럼 암기하기 
		if (a % 2 == 1)res += seg[a];
		if (b % 2 == 0)res += seg[b];

		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	while (si < n) // 비트 마스킹 연산 이용하여, 받은 값을 저장할 index 업데이트하기 
		si <<= 1;

	for (int i = si; i < si + n; i++)
		cin >> seg[i];

	// 세그먼트 트리 초기화
	for (int i = si - 1; i >= 1; i--)
		seg[i] = seg[i * 2] + seg[i * 2 + 1];

	int a, b, c;
	update(b - 1, c);
	sum_arr(a - 1, b - 1);
	return 0;
}

#endif