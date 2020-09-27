// https://www.acmicpc.net/problem/3687
// 성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수를 찾는 프로그램을 작성하시오.

// cf) Codeforces 1295 A. Display The Number (https://codeforces.com/problemset/problem/1295/A) - 7 segments

#include <cstring>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N;
string mins, maxs;

int need[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int cache[100][101];

int can(int len, int cnt) {
	if (len == 0) {
		if (cnt == 0)
      return 1;
		else
      return 0;
	}
	if (cnt <= 0)
	  return 0;

	int& ret = cache[len][cnt];
	if (ret != -1)
	  return ret;
	ret = 0;
	for (int i = 0; i < 10; i++)
		ret |= can(len - 1, cnt - need[i]);

	return ret;
}

void track(int len, int cnt, int firstPos) {
	if (len == 0)
	  return;

	if (!firstPos && can(len - 1, cnt - need[0])) {
		mins += "0";
		track(len-1, cnt-need[0], 0);
	} else {
		for (int i = 1; i < 10; i++) {
			if (can(len-1, cnt-need[i])) {
				mins += i + '0';
				track(len-1, cnt-need[i], 0);
				break;
			}
    }
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
  cin >> T;
	memset(cache, -1, sizeof(cache));
	while (T--) {
		cin >> N;

		// max - Greedy algorithm
		int n = N;
		maxs = mins = "";
		while (n) {
			if (n & 1)
        maxs += "7", n -= 3;
			else
        maxs += "1", n -= 2;
		}

		// min - Dynamic Programming
		int minlen = 1e4;
		for (int i = 1; i <= 100; i++)
			if (can(i, N))
				minlen = min(minlen, i);
		track(minlen, N, 1);

		cout << mins << ' ' << maxs << endl;
	}

	return 0;
}
