# include <iostream>
# include <cstdio> //scanf("%d",&);
using namespace std;

int inp[200][200],dp[200][200];
int h,w;
int max (int,int);

int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	for(i=0; i<t; ++i)
	{
		scanf("%d %d",&h,&w);
		if(h==0 && w==0)
		{
			printf("-1\n");
			continue;
		}
		for(j=0;j<h;++j)
		{
			for(k=0;k<w;++k)
			{
				scanf("%d",&inp[j][k]);
			}			
		}
		for(j=0; j<w;++j)
		{
			dp[h-1][j]=inp[h-1][j];
		}
		for(j=h-2;j>=0;--j)
		{
			for(k=0;k<w;++k)
			{
				if(k==0 && k==w-1)
				{
					dp[j][k] =inp[j][k] + dp[j+1][k];
				}
				else if(k==0)
				{
					dp[j][k] =inp[j][k] + max(dp[j+1][k],dp[j+1][k+1]);
				}
				else if(k==w-1)
				{
					dp[j][k] =inp[j][k] + max(dp[j+1][k-1],dp[j+1][k]);
				}
				else
				{
					dp[j][k] =inp[j][k] + max(max(dp[j+1][k-1],dp[j+1][k]),dp[j+1][k+1]);
				}
			}
		}
		k=0;
		for(j=0;j<w;++j)
		{
			if(k<=dp[0][j])
			{
				k= dp[0][j];
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
int max (int a , int b)
{
	if(a>=b)
	return a;
	else return b;
}
