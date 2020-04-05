/*
Himanshu Yadav
2K13 DTU
*/
# include <iostream>
# include <cstring>
# include <cmath>
using namespace std;
#define MAX 46656 //we generate primes upto MAX
#define LMT 216   //using primes upto LMT

const int s = 100000;
bool nprime[MAX],seg[s+5];
int primes[MAX],cnt;

void segmented_sieve(int,int);
void sieve();
int main ()
{
	int t;
	int m,n;
	cin>>t;
	sieve();
	while(t--)
	{
		cin>>m>>n;
		segmented_sieve(m,n);
	}
	return 0;
}
void segmented_sieve(int a,int b)
{
	if(a<2) a =2;
	if(b<a) return;
	memset(seg,1,sizeof(seg));
	int lim = b-a+1;
	int start = a;
	for(int i=0;i<cnt;++i)
	{
		int start_idx = (start+primes[i]-1)/primes[i];
		int j = max(start_idx,2)*primes[i]-start;

		for(;j<lim;j+=primes[i])
			seg[j]=false;
	}
	for(int i=0;i<lim;++i)
		if(seg[i])
			cout<<i+a<<"\n";
}
void sieve()
{
	int i,j;
	memset(nprime,1,sizeof(nprime));
	for(i=2;i<=LMT;++i)
		if(nprime[i])
		{
			primes[cnt++]=i;
			for(j=i*i;j<=MAX;j+=i)
				nprime[j]=0;
		}
	for(;i<=MAX;++i)
		if(nprime[i])
			primes[cnt++]=i;
}