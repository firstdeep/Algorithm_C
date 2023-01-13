
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0); // cin, cout 빨라짐 
	int arr[4];
	for (int j = 0; j < 3; ++j) {

		for (int i = 0; i < 4; ++i) {
			scanf(" %d", &arr[i]);
		}
		int num = count(begin(arr), end(arr), 1);
		if (num == 3)cout << "A" << "\n";
		else if (num == 2)cout << "B" << "\n";
		else  if (num == 1)cout << "C" << "\n";
		else if (num == 4)cout << "E" << "\n";
		else cout << "D" << "\n";

	}
}