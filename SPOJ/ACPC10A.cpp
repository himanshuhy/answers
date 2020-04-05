#include<cstdio>
int main()
{
	int a,b,c,d,e;
	while(1)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a==0 && b==0 && c==0)
			break;
		else
		{
			if((c-b)==(b-a))
			{
				d=c-b;
				e=c+d;
				printf("AP %d\n",e);
			}
			else
			{
				d=c/b;
				e=d*c;
				printf("GP %d\n",e);
			}
		}
	}
	return 0;
}