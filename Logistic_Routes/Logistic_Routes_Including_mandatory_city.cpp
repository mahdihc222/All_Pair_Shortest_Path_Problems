#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> d(n, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i < n; i++)
        d[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        long long w;
        cin >> w;
        d[u][v] = min(w, d[u][v]);
    }
    int y, z;
    cin >> y >> z;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        long long dis1 = LLONG_MAX, dis2 = LLONG_MAX;
        if (d[u][y] != LLONG_MAX && d[y][v] != LLONG_MAX)
            dis1 = d[u][y] + d[y][v];
        if (d[u][z] != LLONG_MAX && d[z][v] != LLONG_MAX)
            dis2 = d[u][z] + d[z][v];
        cout << min(dis1, dis2) << endl;
    }
    return 0;
}