# include <cstdio>
#include <cmath>
# include <iostream>
using namespace std;
int dp[521];
int main()
{
	int n,count=0,i;
	double total_overhang=0,inp;
	while(1)
	{
		scanf("%lf",&inp);
		if(inp == 0.00)
			break;
		else
		{
			n = floor(inp*100);
			if(double(n)<=total_overhang)
			{
				printf("%d card(s)\n",dp[n]);
			}
			else
			{
				while(double(n) > total_overhang)
				{
					i=total_overhang+1;
					count++;
					total_overhang += 100 * ( 1.0 / (1.0 + count) );
					for(;i<=total_overhang;++i)
					{
						dp[i]=count;
					}
				}
				printf("%d card(s)\n",dp[n]);
			}
		}
	}
	return 0;
}