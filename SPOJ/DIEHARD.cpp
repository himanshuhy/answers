# include <iostream>

using namespace std;
int dp[1200][1200];
int calculate(int,int);
int main ()
{
	int t,h,a;
	cin>>t;
	while(t--)
	{
		cin>>h>>a;
		cout<<calculate(h,a)<<'\n';
	}
	return 0;
}
int calculate(int h, int a)
{
	if(h<=0 || a<=0) //meanning the second step did not complete.
		return -1;
	if(dp[h][a])
		return dp[h][a];
	return dp[h][a] = max (calculate(h-2,a-8), calculate(h-17,a+7)) +2;
}