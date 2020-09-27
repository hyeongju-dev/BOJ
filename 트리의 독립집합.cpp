// https://www.acmicpc.net/problem/2213
// 트리(연결되어 있고 사이클이 없는 그래프)와 각 정점의 가중치가 양의 정수로 주어져 있을 때, 최대 독립 집합을 구하는 문제

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int inf = 1e9+7;
vector<int> g[10010];
vector<int> tree[10010];
int table[10010][2];
int chk[10010];
int maxi = -inf;
int cost[10010];
vector<int> ansArr;

void dfs(int now, int prv) {
	for (int i = 0; i < g[now].size(); ++i) {
		int nxt = g[now][i];
		if (nxt != prv) {
			tree[now].push_back(nxt);
			dfs(nxt, now);
		}
	}
}

int dp(int now, bool include) {
	int &res = table[now][include];
	if (res != -1)
    return res;

	if (include) {
		int ans = 0;
		for (int i = 0; i < tree[now].size(); ++i) {
			int nxt = tree[now][i];
			ans += dp(nxt, 0);
		}
		return res = ans + cost[now];
	} else {
		int ans = 0;
		for (int i = 0; i < tree[now].size(); ++i) {
			int nxt = tree[now][i];
			int t1 = dp(nxt, 0);
			int t2 = dp(nxt, 1);
			if (t1 < t2) {
				chk[nxt] = 1;
			} else {
				chk[nxt] = 0;
			}
			ans += max(t1, t2);
		}
		return res = ans;
	}
}

void track(int now, int include) {
	if (include) {
		ansArr.push_back(now);
		for (int i = 0; i < tree[now].size(); ++i) {
			int nxt = tree[now][i];
			track(nxt, 0);
		}
	} else {
		for (int i = 0; i < tree[now].size(); ++i) {
			int nxt = tree[now][i];
			track(nxt, chk[nxt]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int n;
  cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
		table[i][0] = table[i][1] = -1;
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
    cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);

	int t1 = dp(1, 0);
	int t2 = dp(1, 1);
	if (t1 < t2)
    chk[1] = 1;
	else
    chk[1] = 0;

	int maxi = max(t1, t2);
	cout << maxi << endl;

  track(1, chk[1]);
	sort(ansArr.begin(), ansArr.end());

	for (int i = 0; i < ansArr.size(); ++i)
    cout << ansArr[i] << " ";
}
