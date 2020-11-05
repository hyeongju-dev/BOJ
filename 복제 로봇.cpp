// https://www.acmicpc.net/problem/1944

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define endl "\n"
#define MAX 50
#define MAX_KEY 255

const int dx[4] = {0, 0, +1, -1};
const int dy[4] = {+1, -1, 0, 0};

int N, M, NumKey, Ans;
int KeyNumber[MAX][MAX];
int parent[MAX_KEY];
char map[MAX][MAX];
bool visited[MAX][MAX];
bool foundKey = true;
pair<int, int> start;
vector<pair<int, int> > key;
vector<pair<int, pair<int, int> > > edge;

void input() {
  NumKey = 1;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> map[i][j];
      if (map[i][j] == 'S') {
        start.first = i;
        start.second = j;
      } else if (map[i][j] == 'K') {
        key.push_back(make_pair(i, j));
        KeyNumber[i][j] = NumKey++;
      }
    }
  }
}

void bfs(int sx, int sy, int ex, int ey, int node1, int node2) {
  memset(visited, false, sizeof(visited));
  queue<pair<pair<int, int>, int> > q;
  q.push(make_pair(make_pair(sx, sy), 0));
  visited[sx][sy] = true;

  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int cnt = q.front().second;
    q.pop();

    if (x == ex && y == ey) {
      edge.push_back(make_pair(cnt, make_pair(node1, node2)));
      return;
    }

    for (int d = 0; d < 4; ++d) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
        if (map[nx][ny] == '1')
          continue;
        if (visited[nx][ny] == true)
          continue;
        visited[nx][ny] = true;
        q.push(make_pair(make_pair(nx, ny), cnt+1));
      }
    }
  }

  foundKey = false;
}

void calculateDistance() {
  for (int i = 0; i < key.size(); ++i) {
    int x = key[i].first;
    int y = key[i].second;
    bfs(start.first, start.second, x, y, 0, KeyNumber[x][y]);

    if (!foundKey) {
      cout << -1 << endl;
      return ;
    }
  }

  for (int i = 0; i < key.size(); ++i) {
    int sx = key[i].first;
    int sy = key[i].second;

    for (int j = i+1; j < key.size(); ++j) {
      int ex = key[j].first;
      int ey = key[j].second;
      bfs(sx, sy, ex, ey, KeyNumber[sx][sy], KeyNumber[ex][ey]);

      if (!foundKey) {
        cout << -1 << endl;
        return ;
      }
    }
  }
}

int findParent(int node) {
  if (parent[node] == node)
    return node;
  else
    return parent[node] = findParent(parent[node]);
}

bool hasSameParent(int node1, int node2) {
  node1 = findParent(node1);
  node2 = findParent(node2);

  if (node1 == node2)
    return true;
  else
    return false;
}

void Union(int node1, int node2) {
  node1 = findParent(node1);
  node2 = findParent(node2);

  if (node1 != node2)
    parent[node2] = node1;
}

void kruskal() {
  sort(edge.begin(), edge.end());

  for (int i = 0; i < NumKey; ++i)
    parent[i] = i;

  for (int i = 0; i < edge.size(); ++i) {
    int cost = edge[i].first;
    int node1 = edge[i].second.first;
    int node2 = edge[i].second.second;

    if (!hasSameParent(node1, node2)) {
      Union(node1, node2);
      Ans += cost;
    }
  }

  cout << Ans << endl;
}

void solution() {
  calculateDistance();
  if (!foundKey)
    return;
  kruskal();
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
