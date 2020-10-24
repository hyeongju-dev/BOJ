// https://www.acmicpc.net/problem/1922

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"
#define MAX 100000+1

int N, M, ans;
int parent[MAX];
vector<pair<int, pair<int, int>>> edge;

void input() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({c, {a, b}});
  }
}

int find(int x) {
  if (parent[x] == x)
    return x;
  else
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
  x = find(x);
  y = find(y);

  if (x != y)
    parent[y] = x;
}

bool hasSameParent(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return true;
  else
    return false;
}

void solution() {
  sort(edge.begin(), edge.end());
  for (int i = 1; i <= N; ++i)
    parent[i] = i;  // 초기 값

  for (int i = 0; i < M; ++i) {
    if (!hasSameParent(edge[i].second.first, edge[i].second.second)) {
      Union(edge[i].second.first, edge[i].second.second);
      ans = ans + edge[i].first;
    }
  }

  cout << ans << endl;
}

void solve() {
    input();
    solution();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  solve();

  return 0;
}
