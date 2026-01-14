#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    // Two matrices:
    // d_normal:  Stores shortest paths with original weights 'w'
    // d_penalty: Stores shortest paths with penalized weights 'w + 1'
    vector<vector<long long>> d_normal(n, vector<long long>(n, INF));
    vector<vector<long long>> d_penalty(n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++)
    {
        d_normal[i][i] = 0;
        d_penalty[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // Load Normal Graph
        d_normal[u][v] = min(d_normal[u][v], w);

        // Load Penalty Graph (w + 1)
        d_penalty[u][v] = min(d_penalty[u][v], w + 1);
    }

    // Pass 1: FW on Normal Graph (For paths strictly through V)
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (d_normal[i][k] == INF)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (d_normal[k][j] != INF)
                    d_normal[i][j] = min(d_normal[i][j], d_normal[i][k] + d_normal[k][j]);
            }
        }
    }

    // Pass 2: FW on Penalty Graph (For paths that might skip V)
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (d_penalty[i][k] == INF)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (d_penalty[k][j] != INF)
                    d_penalty[i][j] = min(d_penalty[i][j], d_penalty[i][k] + d_penalty[k][j]);
            }
        }
    }

    // Read V
    int V;
    // Note: The problem prompt usually gives V either at the start or with queries.
    // Based on previous problem format, assuming V is given before queries.
    cin >> V;

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        // Option 1: Take the path with penalty (calculated on w+1 graph)
        long long option1 = d_penalty[u][v];

        // Option 2: Go through V (using normal weights)
        long long option2 = INF;
        if (d_normal[u][V] != INF && d_normal[V][v] != INF)
        {
            option2 = d_normal[u][V] + d_normal[V][v];
        }

        long long ans = min(option1, option2);

        if (ans >= INF)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }

    return 0;
}