// https://lightoj.com/problem/travel-company
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //amr ta hoy nai, gpt bolse eta NP Hard - Pari na ||.||
    //For faster I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // unties cin from cout
    int t;
    cin>>t;
    for(int c=1; c<=t; c++){
        int n,r,p;
        cin>>n>>r>>p;
        vector<vector<int>> d(n,vector<int>(n,INT_MIN));
        //vector<vector<int>> de(n,vector<int>(n,INT_MAX));

        for(int i=0; i<n; i++){
            d[i][i]=0;
        }

        for(int i=0; i<r; i++){
            int u,v;
            int inc,e;
            cin>>u>>v>>inc>>e;
            d[u][v] = max(d[u][v],inc-p*e);
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(d[i][k]!=INT_MIN && d[k][j]!=INT_MIN){
                        d[i][j] = max(d[i][j],d[i][k]+d[k][j]);
                    }
                    
                }
            }
        }
        bool isPossible = false;
        for(int i=0; i<n && !isPossible; i++){
            if(d[i][i]>0)
                isPossible = true;
        }

        cout<<"Case "<<c<<": "<<((isPossible)? "YES":"NO")<<endl;
    }
}