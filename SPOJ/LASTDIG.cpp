#include <cstdio>
int main()
{
	int t;
	scanf("%d",&t);
	int a,b,repeat,last,temp,count;
	for(int i=0; i<t ; ++i)
	{
		scanf("%d %d",&a,&b);
		if(b==0)
		{
			printf("1\n");
			continue;
		}
		if(a==1)
			printf("1\n");
		else if(a==5)
			printf("5\n");
		else if(a==10)
			printf("0\n");
		else if(a==15)
			printf("5\n");
		else if(a==20)
			printf("0\n");
		else
		{
			repeat=0;
			temp = last = a%10;
			do
			{
				temp = (last*temp)%10;
				repeat++;
			}while(last!=temp);
			b--;
			count=b%repeat;
			for(int j=0;j<count;++j)
			{
				temp=(last*temp)%10;
			}
			printf("%d\n",temp);
		}
	}
	return 0;
}
