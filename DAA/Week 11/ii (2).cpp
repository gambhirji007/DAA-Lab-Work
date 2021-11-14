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
    vector <int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int s;
    cin>>s;
    int dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(j>=v[i-1])
                dp[i][j]=dp[i-1][j]+dp[i][j-v[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][s]<<endl;
    return 0;
}
