// https://www.acmicpc.net/problem/2533
// 친구 관계 트리가 주어졌을 때, 모든 개인이 새로운 아이디어를 수용하기 위하여 필요한 최소 얼리 어답터의 수를 구하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>
using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))

vector<int> input_g[1000001];
vector<int> tree[1000001];
vector<vector<int> > dp(1000001, vector<int>(2,-1));

void getInputGraph() {
  int n;
  cin >> n;
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    input_g[a].push_back(b);
    input_g[b].push_back(a);
  }
}

void makeDFSTree(int prev, int curr) {
  for (auto next : input_g[curr]) {
    if (prev != next) {
      tree[curr].push_back(next);
      makeDFSTree(curr, next);
    }
  }
}

int cntMinEA(int curr, bool isEA) {
  int& res = dp[curr][isEA];
  if (res != -1)
    return res;

  res = 0;
  if (isEA) {
    for (auto next : tree[curr])
      res += min(cntMinEA(next, false), cntMinEA(next, true));
    res++;
  } else {
    for (auto next : tree[curr])
      res += cntMinEA(next, true);
  }
  return res;
}

void cntMinEA() {
  cout << min(cntMinEA(1, false), cntMinEA(1, true)) << endl;
}

int main() {
  getInputGraph();
  makeDFSTree(0, 1);
  cntMinEA();

  return 0;
}
