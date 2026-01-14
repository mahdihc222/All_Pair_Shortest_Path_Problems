#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 1. Initialize Distance Matrix
    vector<vector<long long>> d(n, vector<long long>(n, INF));

    // Distance to self is 0
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    // 2. Read Edges
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        
        // Assuming 0-based input. If 1-based, use u--; v--;
        d[u][v] = min(d[u][v], w);
        
        // If the graph is undirected (roads go both ways), uncomment this:
        // d[v][u] = min(d[v][u], w); 
    }

    // 3. Standard Floyd-Warshall Algorithm
    // Computes shortest paths between all pairs
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            // Pruning: If path i->k doesn't exist, skip
            if (d[i][k] == INF) continue; 
            
            for (int j = 0; j < n; j++) {
                if (d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    // 4. Process Queries (Finding the best Meeting Point)
    int q;
    cin >> q;
    while (q--) {
        int u, v; // Friend A is at 'u', Friend B is at 'v'
        cin >> u >> v;

        long long best_time = INF;
        int best_node = -1;

        // Try every node 'k' as a potential meeting spot (Cafe)
        for (int k = 0; k < n; k++) {
            
            // Both friends must be able to reach node k
            if (d[u][k] != INF && d[v][k] != INF) {
                
                // The meeting happens when the LAST person arrives.
                // So we take the MAX of the two travel times.
                long long time_to_meet = max(d[u][k], d[v][k]);

                if (time_to_meet < best_time) {
                    best_time = time_to_meet;
                    best_node = k;
                }
            }
        }

        if (best_time == INF) {
            cout << -1 << "\n"; // Impossible to meet
        } else {
            // Output format: Minimum Time (and optionally the Meeting Node)
            cout << best_time << "\n"; 
            // cout << "Meeting at node: " << best_node << " in time " << best_time << "\n";
        }
    }

    return 0;
}