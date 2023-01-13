#include<iostream>
#include<set>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0); // cin, cout 빨라짐 
	cin.tie(0);

	int freq[26]={0};
	string str; 
	cin >> str;

	for (auto c : str) freq[c - 97]++;
	for (int i = 0; i < 26; ++i)cout << freq[i] << " ";	

}