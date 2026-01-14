#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Three matrices for the three scenarios
    vector<vector<long long>> d_norm(n, vector<long long>(n, INF));
    vector<vector<long long>> d_phase1(n, vector<long long>(n, INF));
    vector<vector<long long>> d_phase2(n, vector<long long>(n, INF));

    // Initialize diagonals
    for (int i = 0; i < n; i++) {
        d_norm[i][i] = 0;
        d_phase1[i][i] = 0;
        d_phase2[i][i] = 0;
    }

    // Read edges and populate all 3 matrices
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // 1. Normal Graph
        d_norm[u][v] = min(d_norm[u][v], w);

        // 2. Phase 1 Graph (Before V): Discount -1
        long long w1 = max(0LL, w - 1);
        d_phase1[u][v] = min(d_phase1[u][v], w1);

        // 3. Phase 2 Graph (After V): Discount -2
        long long w2 = max(0LL, w - 2);
        d_phase2[u][v] = min(d_phase2[u][v], w2);
    }

    // Run Floyd-Warshall 3 times
    
    // Pass 1: Normal
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d_norm[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (d_norm[k][j] != INF)
                    d_norm[i][j] = min(d_norm[i][j], d_norm[i][k] + d_norm[k][j]);
            }
        }
    }

    // Pass 2: Phase 1 (Discount -1)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d_phase1[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (d_phase1[k][j] != INF)
                    d_phase1[i][j] = min(d_phase1[i][j], d_phase1[i][k] + d_phase1[k][j]);
            }
        }
    }

    // Pass 3: Phase 2 (Discount -2)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d_phase2[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (d_phase2[k][j] != INF)
                    d_phase2[i][j] = min(d_phase2[i][j], d_phase2[i][k] + d_phase2[k][j]);
            }
        }
    }

    // Read V
    int V;
    cin >> V;

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        // Option A: Path without special discount rules (or simply ignoring V)
        long long ans = d_norm[u][v];

        // Option B: Path strictly through V
        // u -> V uses Phase 1 weights
        // V -> v uses Phase 2 weights
        if (d_phase1[u][V] != INF && d_phase2[V][v] != INF) {
            long long combined_cost = d_phase1[u][V] + d_phase2[V][v];
            ans = min(ans, combined_cost);
        }

        if (ans >= INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }

    return 0;
}