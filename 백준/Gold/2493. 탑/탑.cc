#if 1
// stack 하나로 구현??
// pair 이용
#include<iostream>
#include<stack>
#include<algorithm>
#include<utility>

using namespace std;
int N; 
stack<int> s;
stack<pair<int, int>> s_p;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	s_p.push(make_pair(100000001, 0));

	for (int i = 1; i < N+1; i++) {
		int temp;
		cin >> temp;

		while (s_p.top().first < temp) {
			s_p.pop();
		}
		cout << s_p.top().second << ' ';
		s_p.push(make_pair(temp, i));
		/*
		if (s_p.top().first > temp) {
			cout << s_p.top().second<<" ";
			s_p.push(make_pair(temp, i));
		}
		else if (s_p.top().first < temp) {
			s_p.pop();
			cout << s_p.top().second << " ";
			s_p.push(make_pair(temp, i));
		}*/
	}

}
#endif