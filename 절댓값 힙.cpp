// https://www.acmicpc.net/problem/11286
// greater<pii>에서 우선이 되는 기준: 절댓값 => pair.first, 절댓값이 동일할 시 본래 값 => pair.second

#include <queue>
#include <iostream>
using namespace std;

#define endl '\n'
#define abs(a) ((a) < 0 ? -a : a)
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  priority_queue<pii, vector<pii>, greater<pii>> min_heap;

  int N;
  cin >> N;
  while (N--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      if (min_heap.empty()) {
        cout << 0 << endl;
      } else {
        cout << min_heap.top().second << endl;
        min_heap.pop();
      }
    } else {
      min_heap.push({abs(cmd), cmd});
    }
  }
}
