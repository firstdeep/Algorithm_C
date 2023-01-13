#if 1
// 모든 문제는 DP로 귀결된다. 
#include<cstdio>
#include<iostream>	

int factorial(int t) {
	int ans = 1;
	for(int i =2;i<=t;i++){
		ans = ans * i;
	}
	return ans;
}
int N, k; 
int main(void) {
	scanf("%d %d", &N, &k);
	printf("%d\n", factorial(N) / (factorial(k) * factorial(N - k)));
	return 0;
}

#endif