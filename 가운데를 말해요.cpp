// https://www.acmicpc.net/problem/1655
// 여태 입력받은 값 중 중간값을 구하는 프로그램 (현재까지 입력된 숫자들의 개수가 짝수라면, 둘 중 더 작은 값 출력)

#include <iostream>
#include <queue>
using namespace std;

#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  priority_queue<int, vector<int>, greater<int> > min_heap;
  priority_queue<int, vector<int>, less<int> > max_heap;

  int N;
  cin >> N;
  while (N--) {
    int num;
    cin >> num;

    if (min_heap.size() == max_heap.size())
      max_heap.push(num);
    else
      min_heap.push(num);

    if (min_heap.size() && max_heap.size() && max_heap.top() > min_heap.top()) {
      int maxTop = max_heap.top(); max_heap.pop();
      int minTop = min_heap.top(); min_heap.pop();
      max_heap.push(minTop); min_heap.push(maxTop);
    }

    cout << max_heap.top() << endl;
  }

  return 0;
}
