#include <bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
using vvi = vector<vi>;
typedef long long ll;
const int INF = (int)1e9;
const int MAXN = 200001;
const int LOG_N = 19;
 
struct node3
{
    int u, v, w;
    bool operator < (const node3& t) const {
        return w < t.w;
    }
};
struct node2 { int v, w; };
bool operator<(node2 l, node2 r) { return l.w > r.w; }
vector<vector<node2>> adj_list(MAXN);
 
ll MST_Kruskal(int max_v, vector<node3> v) {
    struct union_find {
        vector<int> parent;
        union_find(int n) {
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) parent[i] = i;
        }
        int find(int v) {
            return v == parent[v] ? v : parent[v] = find(parent[v]);
        }
        bool uni(int u, int v) {
            u = find(u), v = find(v);
            if (u == v) return 0;
            parent[u] = v;
            return 1;
        }
    };
    union_find uf(max_v);
    sort(v.begin(), v.end());
    ll ans = 0;
    for (auto a : v) {
        if (uf.uni(a.u, a.v)) {
            adj_list[a.u].push_back({ a.v,a.w });
            adj_list[a.v].push_back({ a.u,a.w });
            ans += a.w;
        }
    }
    return ans;
}
 
 
//무방향그래프를 인풋으로 받아, 트리로 만들어준다.LCA를 위한 작업도 해준다.
struct result { int root; int max_level; };
vi parent(MAXN), level(MAXN), dist2(MAXN);
// ancestor[y][x] :: x의 2^y번째 조상을 의미
vvi ancestor(LOG_N + 1, vi(MAXN, -INF));  
 
result treefy(vector<vector<node2>>& adj_list, int root=-1,bool base1=false) {
    int max_v = (int)adj_list.size();
    int max_level = LOG_N;
    function<void(node2, int, int)> dfs = [&](node2 n, int par, int lv) {
        parent[n.v] = par, level[n.v] = lv, dist2[n.v] = n.w;
        ancestor[0][n.v] = par;  // 첫번째(2^0) 조상은 부모
        for (auto adj : adj_list[n.v]) {
            if (adj.v == par) continue;  // 부모방향 간선제거
            dfs(adj, n.v, lv + 1);
        }
    };
    dfs({ root,0 }, -INF, 1);
    for (int i = 1; i <= max_level; i++) {
        for (int j = 1; j < max_v; j++) {
            int tmp = ancestor[i - 1][j];
            if (tmp == -INF) continue;
            ancestor[i][j] = ancestor[i - 1][tmp];
        }
    }
 
    return { root, max_level };
}
 
int lca(int u, int v, vi& level, vvi& ancestor)
{
    if (level[u] < level[v]) swap(u, v);  // b가 더 깊도록 조정
 
    int diff = level[u] - level[v];
    for (int i = 0; diff; i++) {
        if (diff & 1) u = ancestor[i][u];  //b를 올려서 level을 맞춘다.
        diff >>= 1;
    }
    if (u == v) return u;
    for (int i = LOG_N; i >= 0; i--) {
        // a와 b가 다르다면 현재 깊이가 같으니, 깊이를 a,b동시에 계속 올려준다.
        if (ancestor[i][u] != ancestor[i][v]) 
            u = ancestor[i][u], v = ancestor[i][v];
    }
    return ancestor[0][u];
 
 
}
 
int N, M, u, v, w;
int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N >> M;
    vector<node3> vv;
    for(int i=0;i<M;i++) {
        cin >> u >> v >> w;
        vv.push_back({ u,v,w });
    }
    auto mst = MST_Kruskal(N, vv);
 
    result r = treefy(adj_list, 1, true);
    vector<vector<int>> max_dp(r.max_level + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) max_dp[0][i] = dist2[i];
    for (int jump = 1; jump <= r.max_level; jump++)
    {
        for (int here = 1; here <= N; here++)
        {
            int tmp = ancestor[jump - 1][here];
            if (tmp == -INF) continue;
            max_dp[jump][here] = 
                max(max_dp[jump - 1][here], max_dp[jump - 1][tmp]);
        }
    }
 
    for(int i=0;i<M;i++)
    {
        auto [s, e, w] = vv[i];
        int l = lca(s, e, level, ancestor);
 
        int mx = -1;
        int diff = level[s] - level[l];
        for (int j = 0; diff; j++) {
            if (diff & 1) mx = max(mx, max_dp[j][s]), s = ancestor[j][s];
            diff >>= 1;
        }
        diff = level[e] - level[l];
        for (int j = 0; diff; j++) {
            if (diff & 1) mx = max(mx, max_dp[j][e]), e = ancestor[j][e];
            diff >>= 1;
        }
 
        cout << mst + w - mx << '\n';
    }
 
    return 0;
}
