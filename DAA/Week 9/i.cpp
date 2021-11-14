#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
#define ll long long
vector<vector<ll>> floydWarshall(vector<vector<ll>> &g, ll V)
{
    vector<vector<ll>> ans(V,vector<ll>(V));
    for (ll i = 0; i < V; ++i)
        for (ll j = 0; j < V; ++j)
            ans[i][j] = g[i][j];
    for (ll i = 0; i < V; ++i)
        for (ll j = 0; j < V; ++j)
            for (ll k = 0; k < V; ++k)
                if (ans[i][k] != INF && ans[k][j] && ans[i][j] > ans[i][k] + ans[k][j])
                    ans[i][j] = ans[i][k] + ans[k][j];
    return ans;
}
int main()
{
    ll V;
    cin >> V;
    vector<vector<ll>> g(V,vector<ll>(V)),ans(V,vector<ll>(V));
    for (ll i = 0; i < V; ++i)
        for (ll j = 0; j < V; ++j)
            if (i != j)
                g[i][j] = INF;
            else
                g[i][j] = 0;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            ll x;
            cin >> x;
            if (i != j && x != 0)
                g[i][j] = x;
        }
    }
    ans=floydWarshall(g, V);
    cout << "Shortest Distance Matrix:" << endl;
    for (ll i = 0; i < V; ++i)
    {
        for (ll j = 0; j < V; ++j)
            if (ans[i][j] != INF)
                cout << ans[i][j] << "\t";
            else
                cout << "INF"<< "\t";
        cout << endl;
    }
    return 0;
}