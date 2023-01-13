#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0); // cin, cout 빨라짐 
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		cout << a + b<<"\n";
	}
}