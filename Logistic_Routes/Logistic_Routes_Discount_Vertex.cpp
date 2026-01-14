#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> d(n, vector<long long>(n, LLONG_MAX)), d2(n, vector<long long>(n, LLONG_MAX));

    for (int i = 0; i < n; i++)
    {
        d[i][i] = 0;
        d2[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        long long w;
        cin >> w;
        d[u][v] = min(w, d[u][v]);
        d2[u][v] = min(w - 1, d2[u][v]);
    }

    int V;
    cin >> V;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
                if (d2[i][k] != LLONG_MAX && d2[k][j] != LLONG_MAX)
                {
                    d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << min(d[u][v], d2[u][V]+d2[V][v]) << endl;
    }
}