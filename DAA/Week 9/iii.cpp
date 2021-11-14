#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> p;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		p.push_back(a);
	}
	int ans=0;
	sort(p.begin(),p.end());
	ans+=p[0]*(n-1);
	for(int i=1;i<n;i++)
		ans+=p[i]*(n-i);
	cout<<ans<<endl;
	return 0;
}
