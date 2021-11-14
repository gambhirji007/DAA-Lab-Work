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
    int s=0;
    cin>>s;
    for(int i=0;i<n;i++)
        s+=v[i];
    if(s%2==1)
    {
        cout<<"no"<<endl;
        return 0;
    }
    int dp[n+1][s/2+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s/2;j++)
        {
            if(j>=v[i-1])
                dp[i][j]=dp[i-1][j]||dp[i][j-v[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<((dp[n][s/2]==1)?"yes":"no")<<endl;
    return 0;
}
