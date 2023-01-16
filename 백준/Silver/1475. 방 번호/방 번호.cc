
#if 1
#include<iostream>	
#include<algorithm>
	using namespace std;

	int arr[10];

	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		string N;
		cin >> N;
		int len = N.length();
		for (int i = 0; i < len; ++i) {
			arr[N[i] - '0']++;
		}

		int s_n = (arr[6] + arr[9] + 1) / 2;
		arr[6] = s_n;
		arr[9] = s_n;

		int* max = max_element(arr, arr + sizeof(arr) / sizeof(arr[0]));

		cout << *max << "\n";


	}
#endif