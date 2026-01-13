// This is better with dijkstra
#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<vector<float>> adj(n, vector<float>(n, std::numeric_limits<float>::infinity()));
        vector<pair<int, int>> points;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            points.push_back({a, b});

            for (int j = 0; j < i; j++)
            {
                auto it = points[j];
                int a1 = it.first;
                int b1 = it.second;
                float dist = sqrt((a1 - a) * (a1 - a) + (b1 - b) * (b1 - b));
                adj[i][j] = adj[j][i] = dist;
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
                }
            }
        }

        cout << adj[0][1] << endl;
    }
}