# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;

int O[1001],N[1001],W[1001];
int dp[22][80][1001];
int bot_down(int,int,int);
int main ()
{
	ios_base::sync_with_stdio(false);
	int c,a,t,n;
	cin>>c;
	while(c--)
	{
		cin>>t>>a;
		cin>>n;
		for(int i=0;i<=t;++i)
			for(int j=0 ; j<=a; ++j)
				for(int k=0; k<n; ++k)
					dp[i][j][k] = -1;
		for(int i=0;i<n;++i)
			cin>>O[i]>>N[i]>>W[i];
		cout<<bot_down(t,a,n-1)<<'\n';
	}
	return 0;
}

int bot_down(int t,int a, int n)
{
	if(n==-1)
	{
		if(t<=0 && a <=0)
			return 0;
		else
			return 999999999;
	}
	if(t<=0 && a<=0)
		return 0;
	if(dp[max(t,0)][max(0,a)][n]!=-1)
		return dp[max(t,0)][max(0,a)][n];
	if(t>0 && a<=0)
		return dp[t][0][n] = min(bot_down(t,a,n-1), W[n]+bot_down(t-O[n], 0, n-1) ) ;
	if(t<=0 && a>0)
		return dp[0][a][n] = min(bot_down(t,a,n-1), W[n]+bot_down(0, a-N[n], n-1) );
	return dp[t][a][n] =min(bot_down(t,a,n-1), W[n]+bot_down(t-O[n], a-N[n], n-1) );
}