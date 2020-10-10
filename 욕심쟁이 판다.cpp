// https://www.acmicpc.net/problem/1937

#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

int n;
vector<vector<int>> arr;
vector<vector<int>> cache;

int dfs(int y, int x) {
	int now = arr[y][x];

	int &ret = cache[y][x];
	if (ret != -1)
		return ret;
	ret = 1;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		if (arr[ny][nx] <= now)
			continue;

		ret = max(ret, dfs(ny, nx) + 1);
	}

	return ret;
}

int main() {
	cin >> n;
	arr.resize(n, vector<int>(n));
	cache.resize(n, vector<int>(n, -1));

	for (int row = 0; row < n; ++row)
		for (int col = 0; col < n; ++col)
			cin >> arr[row][col];

	int ans = 0;
	for (int row = 0; row < n; ++row)
		for (int col = 0; col < n; ++col)
			ans = max(ans, dfs(row, col));

	cout << ans << endl;

	return 0;
}
