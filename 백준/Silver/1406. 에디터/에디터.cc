#if 1 
// 연결리스트 문제: 임의의 위치에 원소를 추가 원소를 제거 할때 o(1)로 되어있음 
// stl list 방법을 사용 - 연결리스트 이다. 
// 에디터 문제 시간제한 0.3초 최대 600,000글자 입력 가능 
// L은 커서를 왼쪽으로 한칸 옮김, D는 오른쪽으로 옮김 
// B는 왼쪽에 있는 문자를 삭제 
// P는 커서 왼쪽에 문자 삽입 

#include<iostream>
#include<algorithm>
#include<list>
#include<string>

using namespace std; 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	list<char> L;
	for (auto c: s)L.push_back(c);

	auto cursor = L.end();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char op;
		cin >> op;
		if (op == 'P') {
			char add;
			cin >> add;
			L.insert(cursor, add);
		}
		else if (op == 'L') {
			if (cursor != L.begin()) cursor--;
		}
		else if (op == 'D') {
			if (cursor != L.end()) cursor++;
		}
		else {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}

	for (auto c : L) cout << c;
}

#endif 