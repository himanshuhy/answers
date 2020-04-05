# include <iostream>
using namespace std;
int main ()
{
	ios_base::sync_with_stdio(false);
	int t,n,m,d,count;
	cin>>t;
	int hero[500];
	while(t--)
	{
		count=0;
		cin>>n>>m>>d;
		for(int i=0;i<n;++i)
		{
			cin>>hero[i];
		}
		for(int i=0;i<n;++i)
		{
			if(hero[i]%d > 0)
			{
				count+= (hero[i]/d);
			}
		}
		if(count>=m)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
