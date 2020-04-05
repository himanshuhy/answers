#include <iostream>
#include <cstdio>
using namespace std;

int main() {

	long long int n,m;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		scanf("%lld",&n);
		n = n*(3*n+1)/2;
		n = n%1000007;
		printf("%lld\n",n);
	}
	return 0;
}
