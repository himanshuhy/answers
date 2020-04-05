/*
Himanshu Yadav
2K13 DTU
*/
# include <iostream>
# include <cstring>
using namespace std;
bool isPrime[1000005];
long long int  totient[1000005];
long long int solve(int);
void initialize();
int main ()
{
	ios_base::sync_with_stdio(false);
	int t,n;
	long long int ans;
	cin>>t;
	initialize();
	while(t--)
	{
		cin>>n;
		ans = solve(n);
		cout<<ans<<'\n';
	}
	return 0;
}
long long int solve(int n)
{
	if(n==1)
		return 1;
	/*if(isPrime[n]==1)
		return n-1;*/
	return totient[n];
}
void initialize()
{
	memset(isPrime,1,sizeof(isPrime));
	isPrime[0]=isPrime[1]=0;
	int i,j;
	for(i=1; i<=1000000;++i)
		totient[i] = i;
	for(i=2; i<=1000000;++i)
	{
		if(isPrime[i])
		{
			totient[i]--;
			for(j=i*2;j<=1000000;j+=i)
			{
				isPrime[j]=0;
				totient[j]/=i;
				totient[j]*=(i-1);
			}
		}
	}
}