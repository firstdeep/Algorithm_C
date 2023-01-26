#if 1
#include <cstdio>
#include <iostream>

using namespace std;
using ll = long long;

ll seg[1024 * 1024 * 2]; // �迭 ũ��: ������ N���� ������ 2^k>=N ���� 2^(K+1) ��ŭ �迭 ���
int si = 1;

// Indexed Ʈ���� bottom up ���?
void update(int b, ll c) { // b-1�� ���� �Ѱ� �ޱ� 
	b += si; // �� index ���� 

	seg[b] = c; // ���� ������Ʈ �ؾ��� 

	while (b > 1) { //for ������ �ϸ� �ȵȴ�. while 
		b /= 2;
		seg[b] = seg[b * 2] + seg[b * 2 + 1];
	}
}

// �ִ��� �Լ� 
int sum_arr(int a, int b) { 
	a += si;
	b += si;

	ll res = 0;
	while (a <= b) { // ����ó�� �ϱ��ϱ� 
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

	while (si < n) // ��Ʈ ����ŷ ���� �̿��Ͽ�, ���� ���� ������ index ������Ʈ�ϱ� 
		si <<= 1;

	for (int i = si; i < si + n; i++)
		cin >> seg[i];

	// ���׸�Ʈ Ʈ�� �ʱ�ȭ
	for (int i = si - 1; i >= 1; i--)
		seg[i] = seg[i * 2] + seg[i * 2 + 1];

	int a, b, c;
	update(b - 1, c);
	sum_arr(a - 1, b - 1);
	return 0;
}

#endif