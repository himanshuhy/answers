#include<cstdio>
int main()
{
	int n;

	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		else
		{
			n=( n * (n+1) * (2*n + 1) ) / 6;
			printf("%d\n", n);
		}
	}
	return 0;
}