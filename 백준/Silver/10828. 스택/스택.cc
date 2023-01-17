#define _CRT_SECURE_NO_WARNINGS

#if 1
#include<cstdio>
#include<stack>
#include<string>
#include<iostream>

using namespace std; 

int main(void) {

	int N;
	scanf("%d", &N);

	stack<int> st; 
	string str; 

	for (int i = 0; i < N; ++i) {
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (str == "pop") {
			if (!st.empty()) {
				printf("%d\n", st.top());
				st.pop();
			}
			else {
				printf("-1\n");
			}
		}
		else if (str == "size") {
			printf("%d\n", st.size());
		}
		else if (str == "empty") {
			if (st.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (str == "top") {
			if (!st.empty()) {
				printf("%d\n", st.top());
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}
#endif