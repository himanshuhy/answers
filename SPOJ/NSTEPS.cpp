#include<cstdio>
int value(int,int);
int main()
{
	int t;
	scanf("%d",&t);
	int x,y,ans;
	for(int i=0;i<t;++i)
	{
		scanf("%d%d",&x,&y);
		ans=value(x,y);
		if(ans==-1)
			printf("No Number\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
int value(int x,int y)
{
	if(x==y)
	{
		if(x==0)
			return 0;
		else if(x==1)
			return 1;
		else if(x%2==0)
			return 2*x;
		else
			return (2*x - 1);
	}
	else if(y==(x-2))
	{
		int temp=value(x-1,y+1);
		if(temp%2==0)
			return temp-1;
		else
			return temp+1;
	}
	else
		return -1;
}