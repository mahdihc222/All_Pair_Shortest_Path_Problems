// https://cses.fi/problemset/task/1672
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> d(n + 1, vector<long long>(n + 1, LLONG_MAX));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    for (int i = 0; i < n + 1; i++)
        d[i][i] = 0;

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] < LLONG_MAX && d[k][j] < LLONG_MAX)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    bool shortest_route_unavail = false;
    for (int i = 1; i <= n; i++)
    {
        if (d[i][i] != 0)
            shortest_route_unavail = true;
    }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (shortest_route_unavail || d[u][v] == LLONG_MAX)
            cout << -1 << endl;

        else
            cout << d[u][v] << endl;
    }
    return 0;
}