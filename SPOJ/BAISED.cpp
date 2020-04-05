# include <iostream>
# include <vector>
# include <algorithm>
# define endl '\n'
using namespace std;
vector<int> place;
int main ()
{
	string name;
	long long int t,n,i,temp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		place.clear();
		for(i=0; i<n; ++i)
		{
			cin>>name;
			cin>>temp;
			place.push_back(temp);
		}
		sort(place.begin(),place.end());
		temp = 0;
		for(i=0; i<n;++i)
		{
			temp += abs(place[i]-i-1);
		}
		cout<<temp<<endl;
	}
	return 0;
}
