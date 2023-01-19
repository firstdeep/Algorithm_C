#if 1
#include<iostream> 
#include<queue>
using namespace std;
int n, m;
queue<int> q;
int arr[1000002];
int d[3] = { 1,-1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fill(arr, arr + 1000001, -1);

    q.push(n);
    arr[n] = 0;

    while (arr[m]==-1) {
        auto cur = q.front(); q.pop();
        for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
            if (nxt < 0 || nxt>100000) continue; // 이 가정이 틀렸음 수빈이가 0~10만을 넘어갈 수 있음.. 
            if (arr[nxt]!=-1)continue;
            arr[nxt] = arr[cur] + 1;
            q.push(nxt);
        }

    }
   
    cout << arr[m] << "\n";
}
#endif