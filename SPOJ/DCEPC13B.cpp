#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	long long int a[n],i;
	for(i=0 ; i<n ; i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0 ; i<n ; i++)
	{
		if(a[i]%2==0)
			printf("-1\n");
		else
		{
			long long int p=a[i]/2;
			p = p*p;
			printf("%lld\n",p);
		}
	}
	return 0;
}
