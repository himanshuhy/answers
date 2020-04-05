/*
Himanshu Yadav
2K13 DTU
*/
# include <iostream>
# include <iomanip>
# include <vector>
# include <cstring>
# include <algorithm>
# include <cstdio>
# include <cmath>
# define endl '\n'
# define M 100000000
# define L 100
# define S 10000//also the segment size
using namespace std;
vector <int> allprime;//usage?
int nprime[S],primecnt;
bool pr[S],seg[S];//1 is not prime
void init()
{	
	int i,j;
	pr[0] = pr[1] = 1;//composited :P
	for(i=2;i<L;++i)
	{
		if(!pr[i])//pr[j] = 0 is a prime
		{
			nprime[primecnt++] = i;
			for(j=i*i; j<S;j+=i)
			{
				pr[j] = 1;
			}
		}
	}
	for(;i<S;++i)
		if(!pr[i])
			nprime[primecnt++] = i;
	//now we have primes from 1 to 10^4
	//now calculating all primes till 10^8 using segmented sieve
	int k,maxk = M/S,start;//==S -__-
	for(k = 0;k<=maxk;++k)//because in our array we will have  starting with j=0 hence one more element, 
	{
		start = k*S;
		memset(seg,0,sizeof(seg));//marking all prime initially
		for(i=0; i<primecnt;++i)
		{
			j = (start + nprime[i]-1)/nprime[i];
			j = max(j,2)*nprime[i] - start;
			for(; j<S;j+=nprime[i])
			{
				seg[j] = 1;
			}
			if(k==0)
			{
				seg[0] = seg[1] = 1;//composite
			}
		}
		for(i=0;i<S;++i)
		{
			if(!seg[i])
				allprime.push_back(i+start);
		}
	}
}
float solve (int x)
{
	float ans,temp;
	long long int pi;
	//calculate %age error with ans
	pi = upper_bound(allprime.begin(),allprime.end(),x) - allprime.begin();
	ans = abs(float(pi)- (float(x)/log(x)))/float(pi);
	ans *= 100;
	//rounding off to the 1 digit
	/*int temp1;
	temp1 = ans*10;*/
	return ans;
}
int main ()
{
	init();
	int x;
	cin>>x;
	while(x)
	{
		//cout<<solve(x)<<endl;
		printf("%.1f\n",solve(x));
		cin>>x;
	}
	return 0;
}