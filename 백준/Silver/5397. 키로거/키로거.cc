#if 1
#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		list<char> L;
		L.clear();
		auto cursor = L.begin();
		for (auto c : str) {
			if (c == '<') {
				if (cursor != L.begin()) cursor--;
			}
			else if (c == '>') {
				if (cursor != L.end()) cursor++;
			}
			else if (c == '-') {
				if (cursor != L.begin()) {
					cursor = L.erase(--cursor);
				}

			}
			else {
				L.insert(cursor, c);
			}
		}
		for (auto cur = L.begin(); cur != L.end(); cur++) {
			cout << *cur;
		}
		cout << "\n";

	}
}
#endif