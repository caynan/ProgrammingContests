#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100030
using namespace std;

int hot[maxn],ot[maxn],from[maxn],que[maxn],tem,save[maxn];

void bfs(int x) {
    int fr=0,re=-1;
    if (from[x] != 0) {
        que[++re] = from[x];
    }

    while(fr <= re) {
        int u = que[fr++];
        if (ot[u]==1) {
            tem++;
            if (from[u] != 0) {
                que[++re] = from[u];
            }
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        memset(ot, 0, sizeof(ot));

        for (auto i = 1; i <= n; ++i) {
            cin >> hot[i];
        }

        for (auto i = 1; i <= n; ++i) {
            cin >> from[i];
            ot[ from[i] ]++;
        }

        int res = -1, beg, cnt = 0;
        for (auto i = 1; i <= n; ++i) {
            if (hot[i]==1) {
                tem = 0;
                bfs(i);
                if (res<tem) {
                    beg=i;
                    res=tem;
                }
            }
        }

        res++;
        cout << res << endl;

        while (cnt < res) {
            save[cnt++] = beg;
            beg = from[beg];
        }

        for (auto i = cnt-1; i>=0; --i) {
            cout << save[i];
            (i != 0) ? cout << " " : cout << endl;
        }
    }
}
