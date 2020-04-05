# include <iostream>
# include <string.h>
using namespace std;
int main ()
{
	char inp[100];
	int l,d,one,n;//one here actually stores zero
	float random,shoot;
	cin>>inp;
	n = strlen(inp);
	l=d=one=0;
	for(int i=0; i<n;++i)
	{
		if(inp[(i+n)%n]=='0')
		{
			one++;
			if(inp[(i-1+n)%n]=='0')
				l++;
			else
				d++;
			if(inp[(i+1+n)%n]=='0')
				l++;
			else
				d++;
		}
		//no need for else
	}
	random = ( (n-one)*1.00 )/n;
	shoot = (d*1.0)/(l+d);
	if(random>shoot)
	cout<<"SHOOT"<<endl;
	else if(random==shoot)
	cout<<"EQUAL"<<endl;
	else
	cout<<"ROTATE"<<endl;
	return 0;
}
