#if 1 
// 앞서 풀었던 것과 동일: 나누는 것이 없기 때문에 MCN 이항계수 이다. 
// 값이 크기 때문에 long long을 생각하기 
// 고려해 볼 것: 순서가 의미 있는 상황, 순서가 무의미한 상황 

#include<cstdio>
#include<iostream>

int t, n, m; 
long long dp[32][32];

int main(void) {
	// DP를 먼저 계산해서 저장해놓기 
	dp[0][0] = dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < 32; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		printf("%lld\n", dp[m][n]);

	}
	return 0;

}
#endif 