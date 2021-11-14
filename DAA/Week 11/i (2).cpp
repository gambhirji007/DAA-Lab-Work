#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int dp[500][500];
int mcm(vector<int>&v,int i,int j)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
        dp[i][j]=min(dp[i][j],(mcm(v,i,k)+mcm(v,k+1,j)+v[i-1]*v[k]*v[j]));
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    vector<int> v;
    int a,b,n;
    cin>>n>>a>>b;
    v.pb(a);
    v.pb(b);
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.pb(y);
    }
    memset(dp,-1,sizeof(dp));
    cout<<mcm(v,1,n)<<endl;
    return 0;
}
