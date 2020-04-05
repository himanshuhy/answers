# include <iostream>
# include <cstring>
using namespace std;
long long int dp[100000][3];
int toy[100000];
int total;
long long int solve(int , int );
int main ()
{
	ios_base::sync_with_stdio(false);
	int t,i;
	long long int ans;
	cin>>t;
	while(t--)
	{
		cin>>total;
		memset(dp,-1,sizeof(dp));
		for(i = 0; i<total; ++i)
			cin>>toy[i];
		ans = 0;
		ans = max(solve(0,0),max(solve(0,1),solve(0,2)));
		cout<<ans<<endl;
	}
	return 0;
}
long long int solve(int n, int x)
{
	if(n+x>=total)
		return 0;
	if(dp[n][x] !=-1)
		return dp[n][x];
	int temp = 0;
	for(int i=0; i<=x; ++i)
		temp += toy[n+i];
	int y = 2*(x+1);
	dp[n][x] = temp + max(solve(n+y,0),max(solve(n+y,1),solve(n+y,2)));
	return dp[n][x];
}