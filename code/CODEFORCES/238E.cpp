// codeforces #238E
// Fuboat
// Graph
// DP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define pii std::pair<int, int>
#define REP(i, x, y) for(int i = x, _ = y; i <= _; i ++)
#define rep(i, x, y) for(int i = x ,_ = y; i >= _; i --)
#define CLEAR(a) memset(a, 0, sizeof(a))
#define MSET(a, x) memset(a, x, sizeof(a))
#define MK(a, b) std::make_pair(a, b)
template <typename T> bool Chkmin(T &x, T y) { return y < x? x = y, true : false; }
template <typename T> bool Chkmax(T &x, T y) { return y > x? x = y, true : false; }
const int MAXN = 100 + 100, oo = 0x3f3f3f3f;
int n, m, a, b, k;
bool vis[MAXN];
int from[MAXN], to[MAXN], g[MAXN], dp[MAXN];
int far[MAXN][MAXN];
bool InTheSameWay(int u, int v, int k)
{
}
int Dfs(int u, int End)
{
	if (u == End)
		return dp[End];
	if (vis[u])
		return g[u];
		
	vis[u] = true;
	g[u] = 0;
	
	REP (v, 1, n)
		if (far[u][v] == 1 && far[u][v] + far[v][End] == far[u][End])
		// 'far[u][v] == 1' is neccesary.
		// node 'u' must reach node 'v' directly.
			Chkmax(g[u], Dfs(v, End));
	
	g[u] = std::min(g[u], dp[u]);
	return g[u]; 
}

void Init()
{
	MSET(far, 0x3f);
	
	int u, v;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	REP(i, 1, m) {
		scanf("%d%d", &u, &v);
		far[u][v] = 1;
	}
	scanf("%d", &k);
	REP(i, 1, k)
		scanf("%d%d", &from[i], &to[i]);
	
	REP(i, 1, n)
		far[i][i] = 0;
	
	REP(k, 1, n)
		REP(i, 1, n)
			REP(j, 1, n)
				Chkmin(far[i][j], far[i][k] + far[k][j]);
}

int cut[MAXN][MAXN];
void Solve()
{
	bool flag;
	int u, v, S, T;
	REP(i, 1, k) {
		S = from[i];
		T = to[i];
		if (far[S][T] == oo)
			continue;
			
		REP (j, 0, far[S][T]) {
			u = 0;
			REP (v, 1, n)
				if (far[S][v] == j && far[S][v] + far[v][T] == far[S][T]) {
					if (u)
						u = -1;
					else u = v;
				}
			if (u != -1)
				cut[i][u] = true;
		}
	}
	
	REP (i, 1, n)
		dp[i] = oo;
	dp[b] = 0;
		
	do {
		flag = false;
		REP (i, 1, k) {
			CLEAR(vis);
			REP (j, 1, n)
				if (cut[i][j]) {
					if (Chkmin(dp[j], Dfs(j, to[i]) + 1))
						flag = true;
				}
		}
	} while (flag);
	
	if (dp[a] == oo)
		dp[a] = -1;
	printf("%d\n", dp[a]);
}
int main()
{
	Init();
	Solve();
}
