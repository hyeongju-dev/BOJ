// https://www.acmicpc.net/problem/12849

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define div 1000000007

int D;
long long ans;
vector<int> graph[10];
long long cache[10][100003];

long long go(int n, int t) {
  if (t == D) { // base case: "산책을 시작한지 D분일 때, 정보과학관에 도착해야 한다."
    if (n == 7)
      return 1;
    else
      return 0;
  }

  long long& ret = cache[n][t];
  if (ret != -1)
    return ret;

  ret = 0;
  for (int i = 0; i < graph[n].size(); ++i) {
    int next = graph[n][i];
    ret += go(next, t+1);
    ret %= div;
  }

  return ret % div; // 가능한 경로의 수
}

int main() {
    memset(cache, -1, sizeof(cache));

    graph[0].push_back(1), graph[1].push_back(0);
    graph[0].push_back(2), graph[2].push_back(0);
    graph[2].push_back(3), graph[3].push_back(2);
    graph[1].push_back(3), graph[3].push_back(1);
    graph[1].push_back(4), graph[4].push_back(1);
    graph[3].push_back(4), graph[4].push_back(3);
    graph[3].push_back(5), graph[5].push_back(3);
    graph[4].push_back(5), graph[5].push_back(4);
    graph[4].push_back(6), graph[6].push_back(4);
    graph[5].push_back(6), graph[6].push_back(5);
    graph[5].push_back(7), graph[7].push_back(5);
    graph[6].push_back(7), graph[7].push_back(6);

    cin >> D;
    ans = go(7,0);  // 정보과학관 -> [본대 산책] -> 정보과학관

    cout << ans << endl;

    return 0;
}
