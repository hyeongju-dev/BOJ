// https://www.acmicpc.net/problem/1693
// 트리 색칠하기

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int cache[100001][19];
const int INF = 100000007;

int min(int a, int b) {
  return a < b ? a : b;
}

int dp(int curr, int prev, int color) {
  int& ret = cache[curr][color];
  if (ret != 0)
    return ret;

  int colorSum = 0;
  for (int i = 0; i < adj[curr].size(); ++i) {
    int next = adj[curr][i];
    int curMin = INF;

    if (next != prev) {
      for (int nextColor = 1; nextColor <= 18; ++nextColor)
        if (color != nextColor)
          curMin = min(curMin, dp(next, curr, nextColor));
      colorSum += curMin;
    }
  }

  return ret = colorSum + color;
}

int main() {
  int n, a, b;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ans = INF;
  for (int i = 1; i <= 18; ++i)
    ans = min(ans, dp(1, 0, i));

  cout << ans;

  return 0;
}
