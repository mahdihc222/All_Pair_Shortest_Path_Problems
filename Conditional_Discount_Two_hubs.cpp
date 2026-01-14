#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    // Input format: N, M, then the two hubs V1, V2
    if (!(cin >> n >> m))
        return 0;

    int V1, V2;
    cin >> V1 >> V2;

    // Two matrices for Floyd-Warshall
    // d_norm: Standard weights
    // d_disc: Discounted weights (w - 1)
    vector<vector<long long>> d_norm(n, vector<long long>(n, INF));
    vector<vector<long long>> d_disc(n, vector<long long>(n, INF));

    // Initialize diagonals
    for (int i = 0; i < n; i++)
    {
        d_norm[i][i] = 0;
        d_disc[i][i] = 0;
    }

    // Read Edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // 1. Normal Graph
        d_norm[u][v] = min(d_norm[u][v], w);

        // 2. Discounted Graph
        // If condition met, ALL edges get -1.
        // We ensure non-negative weights with max(0, ...).
        long long w_discount = max(0LL, w - 1);
        d_disc[u][v] = min(d_disc[u][v], w_discount);
    }

    // Step 1: Floyd-Warshall on Normal Graph
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (d_norm[i][k] == INF)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (d_norm[k][j] != INF)
                {
                    d_norm[i][j] = min(d_norm[i][j], d_norm[i][k] + d_norm[k][j]);
                }
            }
        }
    }

    // Step 2: Floyd-Warshall on Discounted Graph
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (d_disc[i][k] == INF)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (d_disc[k][j] != INF)
                {
                    d_disc[i][j] = min(d_disc[i][j], d_disc[i][k] + d_disc[k][j]);
                }
            }
        }
    }

    // Process Queries
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        // Option A: Just go u -> v normally (ignoring the requirement)
        long long ans = d_norm[u][v];

        // Option B: Go u -> V1 -> V2 -> v (Using discounted weights)
        if (d_disc[u][V1] != INF && d_disc[V1][V2] != INF && d_disc[V2][v] != INF)
        {
            long long path_cost = d_disc[u][V1] + d_disc[V1][V2] + d_disc[V2][v];
            ans = min(ans, path_cost);
        }

        // Option C: Go u -> V2 -> V1 -> v (Using discounted weights)
        if (d_disc[u][V2] != INF && d_disc[V2][V1] != INF && d_disc[V1][v] != INF)
        {
            long long path_cost = d_disc[u][V2] + d_disc[V2][V1] + d_disc[V1][v];
            ans = min(ans, path_cost);
        }

        if (ans >= INF)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }

    return 0;
}