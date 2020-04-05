# include <iostream>
# include <algorithm>
int height [20001];
using namespace std;
int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int k,n,temp,min;
	while (t--)
	{
		cin>>n>>k;
		for(int i=0;i<n;++i)
			cin>>height[i];
		sort(height,height+n);
		temp = 0;
		min = height[n-1]-height[0];
		for(int i=0;i<=n-k;++i)
		{
			temp = height[i+k-1]-height[i];
			if(temp < min)
				min = temp;
		}
		cout<<min<<'\n';
	}
	return 0;
}