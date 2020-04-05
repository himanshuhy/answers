# include <iostream>
using namespace std;
int s[2000],v[2000];
int dp[2001][2001];
int bot_down_knap(int,int);
int main ()
{
	ios_base::sync_with_stdio(false);
	int S,N;
	cin>>S>>N;
	for(int i=0; i<N;++i)
		cin>>s[i]>>v[i];
	cout<<bot_down_knap(S,N-1)<<"\n";
	return 0;
}
int bot_down_knap(int S,int N)
{
	if(S<=0 || N<0)
		return 0;
	if(dp[S][N])
		return dp[S][N];
	if(S>=s[N])
		return dp[S][N] = 	max(bot_down_knap(S,N-1), v[N] + bot_down_knap(S-s[N],N-1));
	else
		return dp[S][N] = 	bot_down_knap(S,N-1);
}