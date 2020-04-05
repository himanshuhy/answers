#include <cstdio>
int main()
{
	long long int n,diff,temp,count,candy[10000]={};
	while(1)
	{
		count=0;
		scanf("%lld",&n);
		if(n==-1)
			break;
		else
		{
			for(int i=0; i <n ; ++i)
			{
				scanf("%lld",&candy[i]);
				count+=candy[i];
			}
			if(count%n != 0)
			{
				printf("-1\n");
			}
			else
			{
				temp=count/n;
				count = 0;
				for(int i=0;i<n;++i)
				{
					diff=candy[i]-temp;
					if(diff>0)
						count+=diff;
				}
				printf("%lld\n",count);
			}
		}
	}
	return 0;
}