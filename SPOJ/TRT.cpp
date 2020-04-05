# include <iostream>
# include <cstdio>
using namespace std;
int dp[2000][2000];
int v[2000];
int select (int,int,int);
int main ()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d",&v[i]);
	}
	int ans;
	ans = select (0,n-1,1); // is this start correct?
	cout<<ans;
	return 0;
}

int select (int start,int end,int d)
{
	int temp;
	if(dp[start][end] == 0)
	{
		if(start == end)
		{
			temp = d*v[start];
			dp[start][end] = temp;
			return temp;
		}
		else
		{
			temp = max(d*v[start] + select(start+1,end,d+1), d*v[end] + select(start,end-1,d+1));
			dp[start][end] = temp;
			return temp;
		}
	}
	else
	{
		return dp[start][end];
	}
}
