#include <iostream>
#include <algorithm>

using namespace std;
long long dp[101][101][4];

int main() {
	int R, C;
	cin >> C >> R;
	int mod = 100000;
	for (int i = 1; i <= R; i++) {
		dp[i][1][0] = 1;
	}
	for (int j = 1; j <= C; j++) {
		dp[1][j][2] = 1;
	}

	for (int i = 2; i <= R; i++) {
		for (int j = 2; j <= C; j++) {
			// 위에서 내려오는것
			dp[i][j][0] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % mod;
			dp[i][j][1] = dp[i - 1][j][2];

			// 왼쪽에서 오는것
			dp[i][j][2] = (dp[i][j - 1][3] + dp[i][j - 1][2]) % mod;
			dp[i][j][3] = dp[i][j - 1][0];
		}
	}
	int ans = 0;
	for (int k = 0; k < 4; k++) {
		ans += dp[R][C][k];
	}
	cout << ans % mod;

	return 0;
}