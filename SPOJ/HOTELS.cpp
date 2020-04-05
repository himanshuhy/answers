# include <iostream>
# include <cstdio>
using namespace std;
int A[300001];
int main ()
{
	long long int sum,max,m;
	int n,start;
	sum = max = start = 0;
	scanf("%d %lld",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&A[i]);
	for(int i=0;i<n;)
	{
		if(A[i]==m)
		{
			max = m;
			break;
		}
		if(A[i] > m )
		{
			i = i+1;
			start = i;
			sum = 0;
			continue;
		}
		if(sum+A[i] <= m)
		{
			sum+=A[i];
			if(sum>max)
				max = sum;
			++i;
		}
		else if(sum + A[i] > m)
		{
			while(sum +A[i] > m)
			{
				sum -= A[start];
				start ++;
			}
		}
	}
	printf("%lld\n",max );
	return 0;
}