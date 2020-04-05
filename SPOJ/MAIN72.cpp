# include <iostream>
# include <cstring>
# include <algorithm>
using namespace std;
const int s = 100000;
int inp[100];
int subsetsum[101][s+1];
int main ()
{
	ios_base::sync_with_stdio(false);
	int t,n;
	int sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(inp,0,sizeof(inp));
		memset(subsetsum,0,sizeof(subsetsum));
		sum = 0;
		for(int i=0; i<n; ++i)
		{
			cin>>inp[i];
		}
		//calculating the subset sum array
		for(int i=0; i<=n;++i)
			subsetsum[i][0] = 1;
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=s;++j)
			{
				if(inp[i-1]<=j)
				{
					subsetsum[i][j] = subsetsum[i-1][j] || subsetsum[i-1][j-inp[i-1]];
				}
				else
				{
					subsetsum[i][j] = subsetsum[i-1][j];
				}
			}
		}
		for(int i=1; i<=s;++i)
		{
			sum += i*subsetsum[n][i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}