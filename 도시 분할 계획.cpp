// https://www.acmicpc.net/problem/1647

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"
#define MAX 100000+1

int N, M, ans;
int parent[MAX];
vector<pair<int, pair<int, int>>> edge;
vector<int> V;

void input() {
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({c, {a, b}});
  }
}

int findParent(int x) {
  if (parent[x] == x)
    return x;
  else
    return parent[x] = findParent(parent[x]);
}

void Union(int x, int y) {
  x = findParent(x);
  y = findParent(y);

  if (x != y)
    parent[y] = x;
  --N;
}

bool hasSameParent(int x, int y) {
  x = findParent(x);
  y = findParent(y);

  if (x == y)
    return true;
  else
    return false;
}

void solution() {
  sort(edge.begin(), edge.end());
  for (int i = 1; i <= N; ++i)
    parent[i] = i;

  for (int i = 0; i < edge.size(); ++i) {
    if (hasSameParent(edge[i].second.first, edge[i].second.second) == false) {
      Union(edge[i].second.first, edge[i].second.second);
      V.push_back(edge[i].first);
    }
  }

  for (int i = 0; i < V.size() - 1; ++i)
    ans = ans + V[i];

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
