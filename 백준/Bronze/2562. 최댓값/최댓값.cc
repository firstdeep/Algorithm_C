#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0); // cin, cout 빨라짐 
	int max=0, idx;
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x; 
		if (max < x) {
			max = x;
			idx = i+1;
		}
	}
	cout << max << "\n" << idx;
}