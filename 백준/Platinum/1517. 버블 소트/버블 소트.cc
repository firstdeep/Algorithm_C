#if 1
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long 
//https://nicotina04.tistory.com/113 
using namespace std;


int ar[500001];
int idx[500001];
vector<int> crd;

inline int get_idx(int val) {
	return (lower_bound(crd.begin(), crd.end(), val) - crd.begin()) + 1;
}

ll sum(vector<ll>& tree, int pos) {
	ll res = 0;
	while (pos) {
		res += tree[pos];
		pos &= (pos - 1);
	}
	return res;
}

void add(vector<ll>& tree, int pos, ll val) {
	while (pos < tree.size()) {
		tree[pos] += val;
		pos += (pos & -pos);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ar[i]);
		crd.push_back(ar[i]);
	}

	vector<ll> fenwick(n + 1);

	sort(crd.begin(), crd.end());
	crd.erase(unique(crd.begin(), crd.end()), crd.end());

	for (int i = 1; i <= n; i++) {
		idx[i] = get_idx(ar[i]);
	}
	
	ll res = 0;

	// A[i] 뒤에 A[i] 보다 작은 원소가 몇개 존재하는지 
	for (int j = n; j >= 1; --j) {
		int num = idx[j]; // 원소의 좌표 압축 결과 index 가져오기 
		res += sum(fenwick, num - 1); // num-1까지의 출현 
		add(fenwick, num, 1);
	}
	printf("%lld\n", res);
	return 0;
}
#endif