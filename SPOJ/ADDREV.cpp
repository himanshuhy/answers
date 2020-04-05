#include<iostream>
#include<cstdio>
using namespace std;
int rev(int);
int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&a,&b);
		a=rev(a);
		b=rev(b);
		c=a+b;
		c=rev(c);
		printf("%d\n",c);
	}
	return 0;
}
int rev(int n)
{
	int a=0;
	while(n%10==0)
	{
		n=n/10;
	}
	while(n!=0)
	{
		a=(a*10)+(n%10);
		n=n/10;
	}
	return a;
}