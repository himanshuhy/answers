/*
Himanshu Yadav
2K13 DTU
*/
# include <iostream>
# include <cstring>
using namespace std;
bool isPrime[1000005];
int factorcount[1000005];
long long int dp[1000005][11];
void initialize ();
int main ()
{
	ios_base::sync_with_stdio(false);
	int t,a,b,n;
	cin>>t;
	initialize();
	while(t--)
	{
		cin>>a>>b>>n;
		cout<<dp[b][n]-dp[a-1][n]<<'\n';
	}
	return 0;
}
void initialize ()
{
	memset(isPrime,1,sizeof(isPrime));
	factorcount[1]=0;
	isPrime[0]=isPrime[1]=0;
	int i,j;
	for(i=2;i<=1000000;++i)
	{
		if(isPrime[i])
		{
			factorcount[i]=1;
			for(j=i*2;j<=1000000;j+=i)
			{
				isPrime[j]=0;
				factorcount[j]++;
			}
		}
	}
	//making the dp table
	int temp;
	dp[1][0] =1;
	for(i=2;i<=1000000;++i)
	{
		temp = factorcount[i];
		for(j=0;j<=10;++j)
			dp[i][j]=dp[i-1][j];
		if(temp<=10)
			dp[i][temp]++;
	}
}