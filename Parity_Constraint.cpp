#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    // optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    // d[i][j][0] = Shortest distance using EVEN number of edges
    // d[i][j][1] = Shortest distance using ODD number of edges
    vector<vector<vector<long long>>> d(n, vector<vector<long long>>(n, vector<long long>(2, INF)));

    // Initialization
    for (int i = 0; i < n; i++)
    {
        // Distance to self with 0 edges (Even) is 0
        d[i][i][0] = 0;

        // Distance to self with Odd edges remains INF (unless a self-loop exists)
    }

    // Input Edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        // Input assumes 0-based indexing. If 1-based, decrement u and v.
        // u--; v--;

        // Direct edge = 1 edge (Odd count)
        d[u][v][1] = min(d[u][v][1], w);

        // If graph is undirected, uncomment below:
        // d[v][u][1] = min(d[v][u][1], w);
    }

    // Floyd-Warshall with Parity
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // 1. Update EVEN path (d[i][j][0])
                // Case A: Even + Even
                if (d[i][k][0] != INF && d[k][j][0] != INF)
                    d[i][j][0] = min(d[i][j][0], d[i][k][0] + d[k][j][0]);

                // Case B: Odd + Odd
                if (d[i][k][1] != INF && d[k][j][1] != INF)
                    d[i][j][0] = min(d[i][j][0], d[i][k][1] + d[k][j][1]);

                // 2. Update ODD path (d[i][j][1])
                // Case C: Even + Odd
                if (d[i][k][0] != INF && d[k][j][1] != INF)
                    d[i][j][1] = min(d[i][j][1], d[i][k][0] + d[k][j][1]);

                // Case D: Odd + Even
                if (d[i][k][1] != INF && d[k][j][0] != INF)
                    d[i][j][1] = min(d[i][j][1], d[i][k][1] + d[k][j][0]);
            }
        }
    }

    // Queries
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        // u--; v--;

        long long even_dist = d[u][v][0];
        long long odd_dist = d[u][v][1];

        // Output format: Even_Distance Odd_Distance
        if (even_dist == INF)
            cout << "-1 ";
        else
            cout << even_dist << " ";

        if (odd_dist == INF)
            cout << "-1\n";
        else
            cout << odd_dist << "\n";
    }

    return 0;
}