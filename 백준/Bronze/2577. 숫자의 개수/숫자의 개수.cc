#include<iostream>
#include<set>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {

	int a, b, c;
	cin >> a >> b >> c;
	int t = a * b * c;
	int d[10] = {};

	while (t > 0) {
		d[t % 10] ++;
		t /= 10;
	}
	for (int i = 0; i < 10; ++i) cout << d[i] << '\n';

}