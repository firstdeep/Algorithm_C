#if 1	
//순열은 dfs로 풀고 조합은 DP 메모리제이션을 통해서 구현한다. 
// 순서가 의미있는 상황: 정렬이 필요한가 아닌가? 
// 해당문제는 기본 풀이도 가능하고 DFS를 통해서도 가능하다. 
// next_permutation, prev_permutation
#include<iostream>
#include<cstdio> 
#include<vector>
#include<set>
#include <string>

using namespace std;	

set<int> numbers;
vector<int> card; 
bool check[10]; // 10장의 카드가 max 이기 때문에 

int n, k;

void func(int cnt, string s) {
	if (cnt == k) { // K는 카드 뽑는 것 
		numbers.insert(stoi(s));
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == true) continue; 
		check[i] = true; 
		string after = s; 
		after += to_string(card[i]);
		func(cnt + 1, after); // 이게 결국 dfs로 구현한 코드 이다. 
		check[i] = false;
	}
}

int main(void) {
	cin >> n >> k; 
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x; 
		card.push_back(x);
	}

	func(0, "");

	cout << numbers.size();
	return 0;
}
#endif 