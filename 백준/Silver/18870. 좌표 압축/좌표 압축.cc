
#if 1
// 좌표압축 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n;

int arr[1000001];
vector<int> seg;
int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		seg.push_back(arr[i]);
	}

	sort(seg.begin(), seg.end()); // 정렬했으면 unique로 erase 하기 
	seg.erase(unique(seg.begin(), seg.end()), seg.end());

	for (int i = 0; i < n; ++i) {
		int idx = lower_bound(seg.begin(), seg.end(), arr[i]) - seg.begin();
		printf("%d ", idx);
	}
	return 0;
}

#endif