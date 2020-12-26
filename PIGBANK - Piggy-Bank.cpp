#include<bits/stdc++.h>
using namespace std;
int t,e,f,i,j,n,p[505],w[505],diff;
long long int cost[10005];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>e>>f;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>p[i]>>w[i];
		diff = f-e;
		for(i=0;i<=diff;i++)
		{
			(i==0)? cost[i]=0 : 
			cost[i]=INT_MAX;
			for(j=0;j<n;j++)
			{
				if(w[j]<=i) cost[i] = min(cost[i], p[j]+cost[i-w[j]]);
			}
		}
		if(cost[diff]==INT_MAX) cout<<"This is impossible.\n";
		else cout<<"The minimum amount of money in the piggy-bank is "<<cost[diff]<<".\n";	
	}
}
