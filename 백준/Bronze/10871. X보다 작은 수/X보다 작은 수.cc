#if 1 
#include<iostream>	
#include<vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, X; 
	cin >> N >> X;
	vector<int> v = { };

	for (int i = 0; i < N; i++) {
		int x; 
		cin >> x;
		if (x < X) {
			v.push_back(x);
		}
		
	}
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] <<' ';
	}
}
#endif