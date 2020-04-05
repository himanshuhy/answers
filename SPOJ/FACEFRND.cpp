# include <iostream>
# include <set>
using namespace std;
int main ()
{
	ios_base::sync_with_stdio(false);
	set< int> SS; //no reason for this name -__-
	set <int> friends;
	int n,m,temp;
	cin>>n;
	while(n--)
	{
		cin>>temp;
		friends.insert(temp);
		cin>>m;
		for(int i=0; i<m;++i)
		{
			cin>>temp;
			SS.insert(temp);
		}
	}
	for(set<int>::iterator it = friends.begin() ; it!=friends.end(); ++it )
	{
		if(SS.find(*it) != SS.end())
		{
			SS.erase(SS.find(*it));
		}
	}
	cout<<SS.size()<<'\n';
	return 0;
}