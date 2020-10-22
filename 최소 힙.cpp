// https://www.acmicpc.net/problem/1927

#include <queue>
#include <iostream>
using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  priority_queue<int, vector<int>, greater<int> > min_heap;

  int N;
  cin >> N;
  while (N--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      if (min_heap.empty()) {
        cout << 0 << endl;
      } else {
        cout << min_heap.top() << endl;
        min_heap.pop();
      }
    } else {
      min_heap.push(cmd);
    }
  }

  return 0;
}
