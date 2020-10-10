// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <cstring>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))

int N, K;
int time[1002];
int build_order[1002][1002];
int delay[1002];
int final_build;

int calc(int order) {
    int& ret = delay[order];
    if (ret != -1)
        return ret;

    int this_time = 0;
    for (int i = 1; i <= N; ++i)
        if (build_order[i][order])
            this_time = max(this_time, calc(i));

    return ret = this_time + time[order];
}

int main() {
    int T,X,Y;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        memset(time, 0, sizeof(time));
        memset(build_order, 0, sizeof(build_order));
        memset(delay, -1, sizeof(delay));

        for (int i = 1; i <= N; i++)
            cin >> time[i];
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            build_order[X][Y] = 1;
        }

        cin >> final_build;
        cout << calc(final_build) << endl;
    }

    return 0;
}
