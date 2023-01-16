#if 1
#include<iostream>
#include<algorithm>
#include<vector> 

using namespace std;
bool arr[2000001]; // outofbounds
vector<int> v = {};
int ans = 0;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[temp]=1;
		v.push_back(temp);
	}
	int X;
	cin >> X; 
	
	for (int x : v) {
		//cout << x << " " << X - x << "\n";
		if ((X - x) > 0) if(arr[(X - x)]) ans++;
	}

	cout << (int)ans/2 << "\n";

}

#endif