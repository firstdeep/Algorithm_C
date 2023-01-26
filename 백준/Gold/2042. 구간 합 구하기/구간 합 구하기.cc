#include <iostream>
using namespace std;
using ll = long long;

int si = 1;
ll seg[1024 * 1024 * 2];

// 값 변경
void update(int i, ll n) {
	i += si;
	seg[i] = n;

	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}


// 구간의 합 구하기
ll sum(int a, int b) {
	a += si;
	b += si;

	ll ret = 0;
	while (a <= b) {
		if (a & 1) ret += seg[a];
		if (!(b & 1)) ret += seg[b];

		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	while (si < n)
		si <<= 1;

	for (int i = si; i < si + n; i++)
		cin >> seg[i];

	// 세그먼트 트리 초기화
	for (int i = si - 1; i >= 1; i--)
		seg[i] = seg[i * 2] + seg[i * 2 + 1];

	ll a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(b - 1, c);
		if (a == 2) cout << sum(b - 1, c - 1) << '\n';
	}

	return 0;
}