# include <iostream>
# include <cstdio>
using namespace std;
long long int dp[101][101];//contains (a+b)%100 in one half and min_smoke in other.
//int colors[101];
int main ()
{
	int n,i,l,k;
	long long int temp,temp_k,temp_a;
	while(scanf("%d",&n)!=-1)
	{
		for(i=0;i<n;++i)
		{
			scanf("%lld",&dp[i][i]);
		}
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		for(i=0;i<n-1;++i)
		{
			dp[i][i+1] = (dp[i][i]+dp[i+1][i+1])%100;
			dp[i+1][i] = dp[i][i]*dp[i+1][i+1];
		}
		for(l=2;l<n;++l)
		{

			for(i=0;i<n-l;++i)
			{
				temp_a = dp[i][i]*dp[i+1][i+l]+0+dp[i+l][i+1];
				temp_k = i;
				for(k=i+2;k<i+l;++k)
				{
					temp = dp[i][k-1]*dp[k][i+l]+dp[k-1][i]+dp[i+l][k];
					if(temp < temp_a)
					{
						temp_a = temp;
						temp_k = k;
					}
				}
				temp = dp[i][i+l-1]*dp[i+l][i+l] + dp[i+l-1][i] + 0;
				if(temp < temp_a)
				{
					temp_a = temp;
					temp_k = i+l;
				}
				dp[i][i+l]=(dp[i][k-1]+dp[k][i+l])%100;
				dp[i+l][i]=temp_a ;
			}
		}
		printf("%lld\n",dp[n-1][0]);
	}
	return 0;
}