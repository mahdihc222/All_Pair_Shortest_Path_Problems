/*
1. The "VVIP" Permit (State Tracking)Scenario: You have a graph of cities. Some roads are marked as "VVIP only" (marked with flag type=1). Regular roads are type=0. You possess a Single-Use Permit that allows you to traverse exactly one VVIP road in your entire journey.Goal: Shortest path between all pairs (i, j) using at most one VVIP road.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<vector<long long>>> d(n, (vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX))));
    for (int i = 0; i < n; i++)
    {
        d[i][i][0] = 0;
        d[i][i][1] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        int isVIP;
        cin >> u >> v;
        long long w;
        cin >> w;
        cin >> isVIP;
        d[u][v][isVIP] = min(w, d[u][v][isVIP]);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k][0] != LLONG_MAX && d[k][j][0] != LLONG_MAX)
                    d[i][j][0] = min(d[i][j][0], d[i][k][0] + d[k][j][0]);
                if(d[i][k][1]!=LLONG_MAX && d[k][j][0]!=LLONG_MAX)
                    d[i][j][1] = min(d[i][j][1],d[i][k][1]+d[k][j][0]);
                if(d[i][k][0]!=LLONG_MAX && d[k][j][1]!=LLONG_MAX)
                    d[i][j][1] = min(d[i][j][1], d[i][k][0]+d[k][j][1]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << min(d[u][v][0], d[u][v][1]) << endl;
    }
    return 0;
}
