#include <bits/stdc++.h>
using namespace std;
bool comp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
{
    return ((double)a.first.second/(double)a.first.first)>((double)b.first.second/(double)b.first.first);
}
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
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        cin>>v[i].first.first;
        v[i].second=i+1;
    }
    for(int i=0;i<n;i++)
        cin>>v[i].first.second;
    int w,c=0;
    cin>>w;
    double ans=0.0;
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++)
    {
        //cout<<v[i].first<<" "<<v[i].second<<" "<<(double)v[i].second/(double)v[i].first<<endl;
        if(c+v[i].first.first<=w)
        {
            a.push_back(make_pair(v[i].second,v[i].first.first));
            ans+=v[i].first.second;
            c+=v[i].first.first;
        }
        else
        {
            int x=w-c;
            a.push_back(make_pair(v[i].second,x));
            ans+=v[i].first.second*((double)x/(double)v[i].first.first);
            break;
        }
    }
    cout<<ans<<endl;
    for(auto i:a)
        cout<<i.first<<"-"<<i.second<<endl;
    return 0;
}
