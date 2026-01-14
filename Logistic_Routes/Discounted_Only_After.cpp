#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    // Two matrices:
    // d_norm: Original weights
    // d_disc: Weights with fixed discount (w - 1)
    vector<vector<long long>> d_norm(n, vector<long long>(n, INF));
    vector<vector<long long>> d_disc(n, vector<long long>(n, INF));

    // Initialize diagonals
    for (int i = 0; i < n; i++)
    {
        d_norm[i][i] = 0;
        d_disc[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // 1. Normal Graph
        d_norm[u][v] = min(d_norm[u][v], w);

        // 2. Discounted Graph
        // Discount is fixed (non-increasing). We subtract 1.
        // Use max(0, w-1) to ensure weights don't become negative.
        long long discounted_w = max(0LL, w - 1);
        d_disc[u][v] = min(d_disc[u][v], discounted_w);
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

    // Read target V
    int V;
    cin >> V;

    // Process Queries
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        // Option 1: Direct path (no discount used, or V not visited)
        long long ans = d_norm[u][v];

        // Option 2: Path through V
        // Path u -> V (Normal cost) + Path V -> v (Discounted cost)
        if (d_norm[u][V] != INF && d_disc[V][v] != INF)
        {
            ans = min(ans, d_norm[u][V] + d_disc[V][v]);
        }

        if (ans >= INF)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }

    return 0;
}