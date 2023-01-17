#if 1 
#include<iostream> 
#include<cstdio>
#include<stack>

using namespace std;
// 사고의 확장이 필요하다. stack하나로만 사용하지 않고 stack을 보조해줄 수 있는 것을 사용 

stack<int> s;
int ans[1000001];
int seq[1000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int count; 
	cin >> count;

	for (int i = 0; i < count; i++) {
		int temp;
		cin >> temp;
		seq[i] = temp;
	}

	for (int i = count-1; i >=0; i--) {
		while (!s.empty() && s.top() <= seq[i]) s.pop();
		if (s.empty()) ans[i] = -1;
		else {
			ans[i] = s.top();
		}
		s.push(seq[i]);
	}

	for (int i = 0; i < count; i++) {
		cout << ans[i] << " ";
	}
}
#endif