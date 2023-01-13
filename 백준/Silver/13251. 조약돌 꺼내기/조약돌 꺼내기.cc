#include<iostream>
#include<cstdio>
#include<vector>
using namespace std; 

int M,K;
int v[51];
bool v_b[51];


double sum = 0, top = 0, bot = 1;

int main(void) {
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int x; 
		scanf(" %d", &x);
		v[i]=x;
		sum += x;
	}
	scanf("%d", &K);

	for (int i = 0; i < M; i++) {// 예외 처리
		if (v[i] >= K) v_b[i] = true;
	}  
	
	for (int i = 0; i < M; i++) {
		if (v_b[i]) {
			double temp = 1;
			for (int j = 0; j < K; j++) {
				temp *= (v[i] - (double)j);
			}
			top += temp;
		}
	}

	for (int i = 0; i < K; i++) {
		bot *= (double)(sum - i);
	}
	printf("%.16f\n", top / bot);

	return 0; 
}