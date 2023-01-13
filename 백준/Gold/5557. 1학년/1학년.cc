#if 1
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std; 

// 계산된 식이 0이상 20이하여야 한다. 
// input은 100개가 나온다. 
// 최대 100개의 +와 -를 조합하는 경우의 수를 구한후에 
// DP를 통해서 구현? 
// 위에서 구현했던 이항계수2와 비슷한 느낌으로 구현할 수 있다. 
int n;
long long answer; 
vector<int> v; 
long long dp[100][21];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf(" %d", &x);
		v.push_back(x);
	}
	dp[0][v[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j] > 0) {
				int add = j + v[i];
				int sub = j - v[i];
				if (add < 21)	dp[i][add] += dp[i - 1][j];
				if (sub >=0)	dp[i][sub] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 2][v[n - 1]];
	return 0;
}
#endif