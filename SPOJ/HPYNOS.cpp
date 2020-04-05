# include <iostream>
# include <cstdio>
using namespace std;
int temp;
long long int count;
int N[1000];//so that initialized to 0
void find(int );
int main()
{
	int t;
	cin>>t;
	while(t!=0)
	{
		temp+=(t%10)*(t%10);
		t=t/10;
	}
	t=temp;
	count = 1;
	
	if(t==1)
	{
		printf("%lld",count);
		return 0;
	}
	
	N[t]=-1;
	
	temp = 0;
	while(t!=0)
	{
		temp+=(t%10)*(t%10);
		t=t/10;
	}
	count++;
	find(temp);
	return 0;
}
void find (int t)
{
	if(t==1)
	{
		printf("%lld",count);
		return ;
	}
	else if(N[t]== -1)
	{
		printf("-1");
		return ;
	}
	else
	{
		N[t] = -1;
		count ++;
		temp = 0;
		while(t!=0)
		{
			temp+=(t%10)*(t%10);
			t=t/10;
		}
		find(temp);
	}
}
