#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    // Standard I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 1. Read City Tolls (Vertex Weights)
    // Using 1-based indexing for convenience if inputs are 1-based
    vector<long long> toll(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> toll[i];
    }

    // 2. Initialize Distance Matrix
    vector<vector<long long>> d(n + 1, vector<long long>(n + 1, INF));

    // Distance to self is 0 (assuming staying put costs nothing)
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }

    // 3. Process Edges (Combine Weight + Destination Toll)
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // Cost to go u -> v is EdgeWeight + Toll to enter v
        d[u][v] = min(d[u][v], w + toll[v]);

        // If graph is undirected, cost v -> u is EdgeWeight + Toll to enter u
        d[v][u] = min(d[v][u], w + toll[u]);
    }

    // 4. Standard Floyd-Warshall (No changes needed here!)
    // The "toll" logic is already baked into the edge weights.
    // d[i][k] includes toll at k.
    // d[k][j] includes toll at j.
    // Summing them correctly accounts for tolls along the path.
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            // Optimization: Skip if path to k doesn't exist
            if (d[i][k] == INF) continue;

            for (int j = 1; j <= n; j++) {
                if (d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    // 5. Answer Queries
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        if (d[u][v] == INF) {
            cout << -1 << "\n";
        } else {
            // d[u][v] currently includes tolls for:
            // - All intermediate nodes
            // - The destination node v
            // It does NOT include the toll for the start node u.
            
            // If the problem says "You must pay toll at start node too":
            // cout << d[u][v] + toll[u] << "\n";
            
            // Standard "Travel Cost" (Start exempt):
            cout << d[u][v] << "\n";
        }
    }

    return 0;
}