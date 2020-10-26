// https://www.acmicpc.net/problem/1662

#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

pair<int, int> getLength(const string& s, int curr) {
  int cnt = 0;
  int i;

  for (i = curr; i >= 0; --i) {
    if (s[i] == '(') {
      break;
    } else if (s[i] == ')') {
      pair<int, int> result = getLength(s, i-1);
      i = result.first;
      cnt += (s[i]-'0')*(result.second);
    } else {
      cnt++;
    }
  }

  return {i-1, cnt};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  string s;
  cin >> s;
  cout << getLength(s, s.size()-1).second << endl;

  return 0;
}
