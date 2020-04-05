# include <iostream>
# include <cstdio>
using namespace std;
int main()
{
	unsigned long long int n,b,c=192,i,a;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		b=c+250*(a-1);
		cout<<b<<endl;
	}
	return 0;
}
