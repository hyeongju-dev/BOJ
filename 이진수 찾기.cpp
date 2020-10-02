// https://www.acmicpc.net/problem/2248
// N(1 ≤ N ≤ 31)자리의 이진수가 있다. 이러한 이진수 중에서, L(1 ≤ L ≤ N)개 이하의 비트만 1인 것을 크기 순으로 나열했을 때, I번째로 나오는 이진수를 구해내는 프로그램을 작성하시오. 이진수는 0으로 시작할 수도 있다.

#include <iostream>
using namespace std;

int cache[32][32];
char res[32];
int n, l, p;
long long i;

int skip(int n, int l) {
  // base case
  if (l < 0)
    return 0;
  if (n == 0)
    return 1;

  if (cache[n][l])
    return cache[n][l];

  return cache[n][l] = skip(n-1,l) + skip(n-1,l-1);
}

int main() {
  cin >> n >> l >> i;

  while (n) {
    if (skip(n-1,l) < i) {
      res[p++] = '1';
      i -= skip(n-1,l);   // do not recalculate: cuz I solve it using DP
      l--;
    } else {
      res[p++] = '0';
    }
    n--;
  }

  cout << res << endl;

  return 0;
}
