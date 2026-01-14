// https://codeforces.com/contest/25/problem/C
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> d(n + 1, vector<long long>(n + 1, LLONG_MAX));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
        }
    }
    // vector<vector<long long>> d(n + 1, vector<long long>(n + 1, LLONG_MAX));
    // d = adj;
    // for (int k = 1; k <= n; k++)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 1; j <= n; j++)
    //         {
    //             if (d[i][k] != LLONG_MAX && d[k][j] != LLONG_MAX)
    //             {
    //                 d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    //             }
    //         }
    //     }
    // }
    int k;
    cin >> k;
    for (int s = 0; s < k; s++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = min(d[u][v], w);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][u] != LLONG_MAX && d[v][j] != LLONG_MAX)
                {
                    d[i][j] = min(d[i][j], d[i][u] + w + d[v][j]);
                }
                if (d[i][v] != LLONG_MAX && d[u][j] != LLONG_MAX)
                {
                    d[i][j] = min(d[i][j], d[i][v] + w + d[u][j]);
                }
            }
        }
        long long sum = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
                sum += d[i][j];
        cout << sum << endl;
    }
}