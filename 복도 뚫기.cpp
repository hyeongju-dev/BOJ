// https://www.acmicpc.net/problem/9373

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

using lld = long long;
#define endl "\n"

struct edge {
	int u, v;
	double w;
	bool operator < (const edge& e) const {
		return w < e.w;
	}
};

int find(vector<int>& r, int k) {
	if (k == r[k])
    return k;
	return r[k] = find(r, r[k]);
}

bool merge(vector<int>& root, int p, int q) {
	p = find(root, p);
	q = find(root, q);
	if (p == q)
    return false;
	root[q] = p;
	return true;
}

struct circle {
	int x, y, r;
	double dist(const circle& c) {
		lld dx = x - c.x, dy = y - c.y;
		return sqrt(dx*dx + dy*dy) + 1e-8;
	}
	double distBound(const circle& c) {
		return max(0., dist(c) - r - c.r);
	}
};

int main() {
	int T;
  cin >> T;
	while (T--) {
		int w, n;
    scanf("%d %d", &w, &n);
		vector<circle> a(n);
		for (int i = 0; i < n; ++i)
      scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].r);

		vector<edge> E;
		vector<int> group(n + 2);
		int LEFT = n, RIGHT = n + 1;
		E.push_back({LEFT, RIGHT, w + .0});
		for (int i = 0; i < n; ++i) {
			group[i] = i;
			E.push_back({i, LEFT, 0. + max(0, a[i].x - a[i].r)});
			E.push_back({i, RIGHT, 0. + max(0, w - a[i].x - a[i].r)});
			for (int j = i + 1; j < n; ++j) {
				E.push_back({i, j, a[i].distBound(a[j])});
			}
		}
		group[LEFT] = LEFT;
		group[RIGHT] = RIGHT;
		sort(E.begin(), E.end());

		for (auto& e : E) {
			if (merge(group, e.u, e.v)) {
				if (find(group, LEFT) == find(group, RIGHT)) {
					printf("%.6f\n", e.w / 2.0);
					break;
				}
			}
		}
	}
	return 0;
}
