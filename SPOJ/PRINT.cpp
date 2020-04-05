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
	int n = b-a+1;
	int k=0, maxk = n/s;
	for(;k<=maxk;++k)
	{
		memset(seg,1,sizeof(seg));
		int start = a + k*s;
		for(int i=0; i<cnt;++i)
		{
			int start_idx = (start+primes[i]-1)/primes[i];
			int j = max(start_idx,2)*primes[i] - start;
			for(;j<s;j+=primes[i])
				seg[j]=0;
		}
		//print the primes.
		for(int i=0;i< s; ++i)
		{
			if(i+start>b)
				break;
			if(seg[i])
				cout<<i + start<<"\n";
		}
	}
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