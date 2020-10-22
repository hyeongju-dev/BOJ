// https://www.acmicpc.net/problem/11279

#include <queue>
#include <iostream>
using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  priority_queue<int, vector<int>, less<int> > max_heap;

  int N;
  cin >> N;
  while (N--) {
    int cmd;
    cin >> cmd;
    if (cmd == 0) {
      if (max_heap.empty()) {
        cout << 0 << endl;
      } else {
        cout << max_heap.top() << endl;
        max_heap.pop();
      }
    } else {
      max_heap.push(cmd);
    }
  }

  return 0;
}
