#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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
    map<int,int> m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        m[a]++;
        v.pb(a);
    }
    int ma=0,ans=0;
    for(auto i:m)
        ma=max(ma,i.second);
    if(ma>n/2)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    sort(v.begin(),v.end());
    if(n%2==1)
        cout<<v[n/2]<<endl;
    else
        cout<<(v[n/2]+v[n/2-1])/2<<endl;
    return 0;
}
