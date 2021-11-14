#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v(n,{{0,0},0});
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first.second;
        v[i].second=i+1;
    }
    for(int i=0;i<n;i++)
        cin>>v[i].first.first;
    sort(v.begin(),v.end());
    vector <int> ans;
    ans.pb(v[0].second);
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(v[i].first.first>=v[j].first.first)
        {
            ans.pb(v[i].second);
            j=i;
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}
