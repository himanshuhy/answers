# include <iostream>
# include <string>
# include <cstring>
using namespace std;
//char inp[205];
string inp;
int aux[205];
int main ()
{
	ios_base::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>inp;
		//finding the auxilary function
		int aux[n][n];
		for(int i=0; i<n;++i)
		{
			if(inp[i]=='0')
				aux[i][i]=0;
			else
				aux[i][i]=1;
		}
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				if(inp[j]=='0')
				{
					aux[i][j]=aux[i][j-1];
				}
				else
					aux[i][j]=aux[i][j-1]+1;
			}
		}
		int ans[n][n];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;++i)
			ans[i][i]=aux[i][i];
		int len,i,j,m,k;
		for(len=2;len<=n;++len)
		{
			for(i=0; i<=n-len;++i)
			{
				j=i+len-1;
				if(aux[i][j] > (len/2))
					ans[i][j] = len;
				else
				{
					m = -1;
					for(k=i ;k<j ;++k)
					{
						m = max(m,ans[i][k]+ans[k+1][j]);
					}
					ans[i][j] = m;
				}
			}
		}
		cout<<ans[0][n-1]<<'\n';
	}
	return 0;
}