#if 1
// 모든 문제는 DP로 귀결된다. --> 해당 문제는 DP로 풀어야 한다 왜?? 
// 시간제한 1초당 1억번: 시간복잡도는 문제 없음 
// 이항계수 1에서 10007을 나누면? --> 1007로 나누는 이유는 계산 값이 overflow 발생
// 파스칼 삼각형 성질을 이용해서 푼다. 
// nCr = n-1Cr-1 + n-1Cr

#include<cstdio>
#include<iostream>	

using namespace std;

#define MAX 1001
#define MDD (10007)

int N, k;
int dp[MAX][MAX] = { 0, };

int main(void) {
	scanf("%d %d", &N, &k);
	dp[1][1] = 1;
	dp[1][0] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == j || j == 0) dp[i][j] = 1;
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MDD;
			}
		}
	}
	printf("%d\n", dp[N][k]);
	return 0;
}

#endif