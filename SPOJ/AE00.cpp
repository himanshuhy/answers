#include <cstdio>
#include <cmath>
int main()
{
	int i,j,n,sqr;
	long long int sum=0,temp;
	scanf("%d",&n);
	for(i=1; i<=n;++i)
	{
		sqr=sqrt(i);
		temp = 1;
		for(j=2;j<=sqr;++j)
		{
			if(i%j == 0)
				temp++;
		}
		sum += temp;
	}
	printf("%lld\n",sum);
	return 0;
}