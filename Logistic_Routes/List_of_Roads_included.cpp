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

    // 1. Setup Distance Matrices
    vector<vector<long long>> d_norm(n, vector<long long>(n, INF));
    vector<vector<long long>> d_disc(n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++)
    {
        d_norm[i][i] = 0;
        d_disc[i][i] = 0;
    }

    // We also need to store the raw special edges for the logic later
    // Storing as adjacency list for easy lookup: special_adj[v] = list of {u, weight}
    // Note: We store by 'v' (destination) to optimize the 'intermediate' step
    struct Edge
    {
        int u;
        long long w;
    };
    vector<vector<Edge>> special_incoming(n);

    // Read Graph Edges
    // NOTE: In this problem, we need to know WHICH edges are "Special".
    // Usually, input gives M edges, then K special edges (or indices).
    // I will assume the input format: M edges, then K, then K pairs of (u, v) that are special.

    // First, read all M edges to build the graph
    // We need to store them temporarily to identify which are special later?
    // Or simply read the graph, then read the list.
    // Let's assume standard format: u, v, w.
    // If the "Special List" is a subset of these, we need to flag them.
    // To keep it generic: I will read M edges for the graph,
    // and then read K lines defining the "Must Include" edges.

    map<pair<int, int>, long long> edge_weights; // Helper to find weights of special edges

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // Populate Normal Graph
        d_norm[u][v] = min(d_norm[u][v], w);

        // Populate Discounted Graph
        long long w_d = max(0LL, w - 1);
        d_disc[u][v] = min(d_disc[u][v], w_d);

        // Store for lookup
        // Keep the smallest weight if multiple edges exist
        if (edge_weights.find({u, v}) == edge_weights.end())
        {
            edge_weights[{u, v}] = w_d;
        }
        else
        {
            edge_weights[{u, v}] = min(edge_weights[{u, v}], w_d);
        }
    }

    // Read Special Edges List
    int k;
    cin >> k;
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        // Check if this edge actually exists in the graph
        if (edge_weights.count({u, v}))
        {
            long long w_d = edge_weights[{u, v}];
            special_incoming[v].push_back({u, w_d});
        }
    }

    // 2. Floyd-Warshall (Normal & Discounted)
    // Complexity: O(N^3)
    for (int p = 0; p < n; p++)
    {
        for (int i = 0; i < n; i++)
        {
            if (d_norm[i][p] != INF)
            {
                for (int j = 0; j < n; j++)
                {
                    if (d_norm[p][j] != INF)
                        d_norm[i][j] = min(d_norm[i][j], d_norm[i][p] + d_norm[p][j]);
                }
            }
            if (d_disc[i][p] != INF)
            {
                for (int j = 0; j < n; j++)
                {
                    if (d_disc[p][j] != INF)
                        d_disc[i][j] = min(d_disc[i][j], d_disc[i][p] + d_disc[p][j]);
                }
            }
        }
    }

    // 3. The "Forced Edge" Calculation
    // Step A: Calculate 'intermediate[i][v]'
    // Min cost from i -> v ending exactly with a special edge (u -> v)
    // Complexity: O(N * K) or O(N^2) depending on sparsity
    vector<vector<long long>> intermediate(n, vector<long long>(n, INF));

    for (int v = 0; v < n; v++)
    { // For every destination of a special edge
        for (auto &edge : special_incoming[v])
        {
            int u = edge.u;
            long long w_special = edge.w;

            for (int i = 0; i < n; i++)
            {
                if (d_disc[i][u] != INF)
                {
                    intermediate[i][v] = min(intermediate[i][v], d_disc[i][u] + w_special);
                }
            }
        }
    }

    // Step B: Calculate 'd_forced[i][j]'
    // Combine intermediate[i][v] + d_disc[v][j]
    // Complexity: O(N^3)
    vector<vector<long long>> d_forced(n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++)
    {
        for (int v = 0; v < n; v++)
        { // v is the "bridge" node
            if (intermediate[i][v] == INF)
                continue;

            for (int j = 0; j < n; j++)
            {
                if (d_disc[v][j] != INF)
                {
                    d_forced[i][j] = min(d_forced[i][j], intermediate[i][v] + d_disc[v][j]);
                }
            }
        }
    }

    // 4. Queries
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        // Option 1: Ignore the list (Normal Price)
        long long ans = d_norm[u][v];

        // Option 2: Force at least one special edge (Discounted Price)
        if (d_forced[u][v] != INF)
        {
            ans = min(ans, d_forced[u][v]);
        }

        if (ans >= INF)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }

    return 0;
}