#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> adj(26, vector<int>(26, INT_MAX));
    int m;
    cin >> m;
    for (int i = 0; i < 26; i++)
        adj[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        char c1, c2;
        int w;
        cin >> c1 >> c2 >> w;
        int u = c1 - 'a';
        int v = c2 - 'a';
        adj[u][v] = min(adj[u][v], w);
    }
    if (s1.size() != s2.size())
    {
        cout << -1 << endl;
    }
    else
    {
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX)
                    {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        int cost = 0;
        string ans;
        for (int i = 0; i < s1.size(); i++)
        {
            int curCost = INT_MIN;
            char c;
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';

            if (adj[u][v] < adj[v][u])
            {
                curCost = adj[u][v];
                c = s2[i];
            }
            else
            {
                curCost = adj[v][u];
                c = s1[i];
            }

            for (int i = 0; i < 26; i++)
            {
                if (adj[u][i] != INT_MAX && adj[v][i] != INT_MAX && curCost > adj[u][i] + adj[v][i])
                {
                    curCost = adj[u][i] + adj[v][i];
                    c = i + 'a';
                }
            }
            if (curCost == INT_MAX)
                break;
            ans.push_back(c);
            cost += curCost;
        }
        if (ans.size() != s1.size())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << cost << endl;
            cout << ans << endl;
        }
    }
}