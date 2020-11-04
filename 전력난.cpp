// https://www.acmicpc.net/problem/6497
// TODO: "입력은 여러 개의 테스트 케이스로 구분되어 있다. 입력의 끝에서는 첫 줄에 0이 2개 주어진다."

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl "\n"

int m, n, sum;
int parent[200001];
vector<pair<int, pair<int, int> > > edge;

void input() {
  sum = 0; edge.clear();

  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    edge.push_back(make_pair(z, make_pair(x, y)));
    sum += z;
  }
}

int find(int x) {
  if (parent[x] == x)
    return x;
  else
    return parent[x] = find(parent[x]);
}

bool hasSameParent(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return true;
  else
    return false;
}

void Union(int x, int y) {
  x = find(x);
  y = find(y);

  if (x != y)
    parent[y] = x;
}

void solution() {
  sort(edge.begin(), edge.end());

  for (int i = 0; i < m; ++i)
    parent[i] = i;

  for (int i = 0; i < n; ++i) {
    if (!hasSameParent(edge[i].second.first, edge[i].second.second)) {
      Union(edge[i].second.first, edge[i].second.second);
      sum -= edge[i].first;
    }
  }

  cout << sum << endl;
}

void solve() {
  input();
  solution();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  solve();

  return 0;
}
