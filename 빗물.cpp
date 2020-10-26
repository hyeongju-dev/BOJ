// https://www.acmicpc.net/problem/14719

#include <iostream>
#include <vector>
using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// or #define INT_MIN (-0x7fffffff-1)
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int h, w;
  cin >> h >> w;

  vector<int> heights(w, 0);
  for (int i = 0; i < w; ++i)
    cin >> heights[i];

  int counter = 0;
  for (int i = 0; i < h; ++i) {
    int blocked = 0;
    int low = INT_MAX, high = INT_MIN;
    for (int j = 0; j < w; ++j) {
      if (heights[j] > i) {
        ++blocked;
        low = min(low, j);
        high = max(high, j);
      }
    }

    if (blocked == 0)
      break;
    else if (blocked == w)
      continue;
    else
      counter += (high - low + 1) - blocked;
  }

  cout << counter << endl;

  return 0;
}
