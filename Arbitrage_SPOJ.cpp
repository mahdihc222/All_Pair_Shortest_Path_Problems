#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cas = 0;
    while (true)
    {
        cas++;
        int n;
        cin >> n;
        if (n == 0)
            break;
        unordered_map<string, int> id;
        vector<string> names(n);
        for (int i = 0; i < n; i++)
        {
            cin >> names[i];
            id[names[i]] = i;
        }

        int m;
        cin >> m;
        string from, to;
        double w;
        vector<vector<double>> d(n, vector<double>(n, -1.0));
        for (int i = 0; i < n; i++)
        {
            d[i][i] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> from >> w >> to;
            d[id[from]][id[to]] = max(d[id[from]][id[to]], w);
        }

        

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (d[i][k] != -1.0 && d[k][j] != -1.0)

                        d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
                }
            }
        }

        bool arbitrage = false;
        for (int i = 0; i < n; i++)
        {
            if (d[i][i] > 1 + 1e-12)
            {
                arbitrage = true;
                break;
            }
        }
        if (arbitrage)
            cout << "Case " << cas << ": " << "Yes" << endl;
        else
            cout << "Case " << cas << ": " << "No" << endl;
    }
    return 0;
}