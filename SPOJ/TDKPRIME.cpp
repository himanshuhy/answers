/*
Himanshu Yadav
2K13 DTU
*/
# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
# define LAST 100000000
# define MAX 10000
# define LMT 100
bool nprime[MAX],seg[MAX];//0=prime & 1=not-prime
int cnt,primes[MAX],primecnt;
int ans[5000000];
void initialize()
{
	int i;
	nprime[0] = nprime[1] = 1;
	for(i=2;i<LMT;++i) //<=???
	{
		if(!nprime[i])
		{
			primes[cnt++] = i;
			for(int j=i*i; j< MAX ; j+=i)
				nprime[j] = 1;
		}
	}
	for(;i<MAX;++i) // [LMT,MAX)
		if(!nprime[i])
			primes[cnt++] = i; 
}
void solve(int a =0, int b = LAST)
{
	int start,i,j,k,maxk = b/MAX;
	for(k=0;k<=maxk;++k)
	{
		start = k*MAX;
		memset(seg,1,sizeof(seg));
		for(i=0;i<cnt;++i)
		{
			j = (start + primes[i] - 1)/primes[i];
			j = max(j,2)*primes[i] - start;
			for(;j<MAX;j+=primes[i])
				seg[j] = 0;
		}
		if(k==0)
			seg[0]=seg[1]=0;
		for(i=0; primecnt<5000000 && i<MAX;++i)
		{
			if(seg[i]==1)
			{
				ans[primecnt++]=i+start;
			}
		}
	}
}
int main ()
{
	initialize();
	solve();
	int q,temp;
	cin>>q;
	while(q--)
	{
		cin>>temp;
		cout<<ans[temp-1]<<"\n";
	}
	return 0;
}