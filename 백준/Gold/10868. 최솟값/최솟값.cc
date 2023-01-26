#if 1 
// 최솟값과 최댓값 
#include<cstdio>
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
using ll = long long;

int n, m, si=1;

ll min_arr[1024 * 1024 * 2];
ll max_arr[1024 * 1024 * 2];

ll find_min(int a, int b) {
	ll result = LLONG_MAX;
	a += si;
	b += si;
	while (a <= b) {
		if (a % 2 == 1) result = min(result, min_arr[a]);
		if (b % 2 == 0) result = min(result, min_arr[b]);

		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	return result;
}
ll find_max(int a, int b) {
	ll result = LLONG_MIN;
	a += si;
	b += si;
	while (a <= b) {
		if (a % 2 == 1) result = max(result, max_arr[a]);
		if (b % 2 == 0) result = max(result, max_arr[b]);

		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	return result;
}

int main() {
	scanf("%d %d", &n, &m);
	
	while (si < n) si <<= 1; //어디서부터 값을 저장할 지 시작 index 값 업데이트 
	for (int i = si; i < si + n; i++) { // 값 저장하기 바로 찾으면 된다. 
		ll temp;
		scanf(" %lld", &temp);
		min_arr[i] = temp;
		max_arr[i] = temp;
	}
	// 부모 노드 까지 채우기 
	for (int i = si - 1; i >= 1; i--) {
		// 0 인거 control 해줘야 한다.
		if (min_arr[2 * i] == 0) min_arr[i] = min_arr[2 * i + 1];
		else if (min_arr[2 * i + 1] == 0) min_arr[i] = min_arr[2 * i];
		else min_arr[i] = min(min_arr[2 * i], min_arr[2 * i + 1]);
		max_arr[i] = max(max_arr[2 * i], max_arr[2 * i + 1]);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld \n", find_min(a - 1, b - 1));
	}

	return 0;

}
#endif