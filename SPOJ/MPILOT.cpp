# include <iostream>
using namespace std;
int n;
int dp[10001][5001];
int cap[10001],ass[10001];
int mincost(int,int);
int main ()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n;++i)
	{
		cin>>cap[i]>>ass[i];
	}
	dp[0][n/2] = ass[0];
	int ans;
	ans = mincost(n-2,1) + cap[n-1];
	cout<<ans<<"\n";
	return 0;
}
int mincost(int i, int c)
{
	if(dp[i][c]!=0)
		return dp[i][c];
	else
	{
		if(c==n/2)
		{
			dp[i][c] = mincost(i-1,c) + ass[i];
			return dp[i][c] ;
		}
		else if((n-i-1)/2 == c)
		{
			dp[i][c] = mincost(i-1,c+1) + cap[i];
			return dp[i][c];
		}
		else
		{
			dp[i][c] = min(mincost(i-1,c) + ass[i], mincost(i-1,c+1) + cap[i] );
			return dp[i][c];
		}
	}
}