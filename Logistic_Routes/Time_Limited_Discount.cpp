#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Adjacency Matrix for O(1) edge lookup
    // Using simple adjacency list for iteration is better for sparsity, 
    // but matrix is fine for O(N^4) logic.
    vector<vector<long long>> adj(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++) adj[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w); // Handle multiple edges
    }

    int V, k_limit;
    cin >> V >> k_limit;

    // dp[len][i][j][state]
    // To save memory and match typical FW/Bellman structure:
    // dist[len][i][j][0] = Min cost i->j with 'len' edges, V NOT visited
    // dist[len][i][j][1] = Min cost i->j with 'len' edges, V visited (within constraint)
    
    // Dimensions: [Length][Source][Dest][State]
    // N <= 60 is safe for this. N=100 is borderline.
    vector<vector<vector<vector<long long>>>> d(
        n + 1, vector<vector<vector<long long>>>(
            n, vector<vector<long long>>(n, vector<long long>(2, INF))
        )
    );

    // Initialization (Length 0)
    for (int i = 0; i < n; i++) {
        d[0][i][i][0] = 0;
        if (i == V) d[0][i][i][1] = 0; // If we start at V, we visited V
    }

    // DP Loop: Iterate length 'len' from 1 to N
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n; i++) {       // Source
            for (int j = 0; j < n; j++) {   // Destination
                for (int mid = 0; mid < n; mid++) { // Intermediate (Previous node)
                    
                    // If no edge mid->j, skip
                    if (adj[mid][j] == INF) continue;

                    long long w = adj[mid][j];
                    long long w_discount = max(0LL, w - 1); // Subtract 1 per edge

                    // --- State 0: V NOT visited yet ---
                    // Transition: (Not Visited) -> (Not Visited)
                    // Only possible if j is NOT V
                    if (j != V) {
                        if (d[len-1][i][mid][0] != INF) {
                            d[len][i][j][0] = min(d[len][i][j][0], d[len-1][i][mid][0] + w);
                        }
                    }

                    // --- State 1: V IS visited ---
                    
                    // Case A: Visited V previously (in earlier steps)
                    // Transition: (Visited) -> (Visited)
                    // We apply discount because we already satisfied the condition
                    if (d[len-1][i][mid][1] != INF) {
                        d[len][i][j][1] = min(d[len][i][j][1], d[len-1][i][mid][1] + w_discount);
                    }

                    // Case B: Visiting V right now! (mid -> j where j == V)
                    // Transition: (Not Visited) -> (Visited)
                    // Constraint: This must happen within k_limit edges. (len <= k_limit)
                    if (j == V && len <= k_limit) {
                        if (d[len-1][i][mid][0] != INF) {
                            // Apply discount to this edge too? 
                            // Based on your instruction "subtract 1 for each edge", likely yes.
                            d[len][i][j][1] = min(d[len][i][j][1], d[len-1][i][mid][0] + w_discount);
                        }
                    }
                }
            }
        }
    }

    // Aggregate answers over all lengths
    vector<vector<long long>> ans(n, vector<long long>(n, INF));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int len = 0; len <= n; len++) {
                // Min of (Path without V) and (Path with V)
                ans[i][j] = min(ans[i][j], d[len][i][j][0]);
                ans[i][j] = min(ans[i][j], d[len][i][j][1]);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (ans[u][v] == INF) cout << -1 << "\n";
        else cout << ans[u][v] << "\n";
    }

    return 0;
}