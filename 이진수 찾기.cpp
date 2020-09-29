// https://www.acmicpc.net/problem/2248
// N(1 ≤ N ≤ 31)자리의 이진수가 있다. 이러한 이진수 중에서, L(1 ≤ L ≤ N)개 이하의 비트만 1인 것을 크기 순으로 나열했을 때, I번째로 나오는 이진수를 구해내는 프로그램을 작성하시오. 이진수는 0으로 시작할 수도 있다.

#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll N, L, I;
ll cache[35][35];
string s = "";

ll binary(int n, int m) {
	if (n == 0 || m == 0)
		return 1;
	ll& ret = cache[n][m];
	if (ret != -1)
		return ret;

	ret = binary(n-1, m);
	if (m > 0)
		ret += binary(n-1, m-1);

	return ret;
}

void skip(int n, int m, ll k, int p) {
	if (n == 0)
		return;

	if (m == 0) {
		for (int i = 0; i < n; ++i)
			s += "0";
		return;
	}

	ll pivot = binary(n-1, m);
	if (k < pivot) {
		s += "0";
		skip(n-1, m, k, p+1);
	} else {
		s += "1";
		skip(n-1, m-1, k-pivot, p+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> I;
	memset(cache, -1, sizeof(cache));
	skip(N, L, I-1, 0);
	cout << s << endl;

	return 0;
}
