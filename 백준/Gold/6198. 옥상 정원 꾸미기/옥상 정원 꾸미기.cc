#if 1 
#include<iostream> 
#include<cstdio>
#include<stack>

using namespace std;
//stack size로 접근 
// 8만부터 다 더한다는 가정하에 64억임으로 long long을 answer로 받아야 된다. 
stack<int> s;
long long answer = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int count; 
	cin >> count;

	for (int i = 0; i < count; i++) {
		int height;
		cin >> height;
		if (s.empty())s.push(height);
		while (!s.empty() && s.top() <= height)s.pop();
		answer += s.size();
		s.push(height);
	}
	cout << answer << '\n';

}
#endif