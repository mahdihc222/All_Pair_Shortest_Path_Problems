// https://www.spoj.com/problems/SOCIALNE/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            m[0][i] = (s[i] == 'Y' ? 1 : 0);
        }
        for (int i = 1; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                m[i][j] = (s[j] == 'Y' ? 1 : 0);
            }
        }

        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    res[i][j] += m[i][k] * m[k][j];
                }
            }
        }

        vector<int> friends(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && res[i][j] && m[i][j]==0)
                    friends[i]++;
        int max_ind = 0, max_friends = friends[0];
        for (int i = 1; i < n; i++)
        {
            if (friends[i] > max_friends)
            {
                max_friends = friends[i];
                max_ind = i;
            }
        }
        cout << max_ind << " " << max_friends << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << m[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
}