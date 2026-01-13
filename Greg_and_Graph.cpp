#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }
    
    vector<int> order(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> order[i];
    }
    
    vector<long long> ans(n + 1);
    
    // Process in reverse order
    for (int k = n; k >= 1; k--) {
        int v = order[k];
        
        // Standard Floyd-Warshall
        // The trick: at step k, vertices order[k..n] are "alive"
        // We update paths using ALL pairs of alive vertices
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]);
            }
        }
        
        // Sum only alive vertices
        long long sum = 0;
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                sum += dist[order[i]][order[j]];
            }
        }
        ans[k] = sum;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}