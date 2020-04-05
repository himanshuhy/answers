# include <iostream>
# include <vector>
# include <cstring>
using namespace std;
char inp[55][55];
int dp[55][55];
int h,w;
vector <pair<int,int> > start;
int solve (pair<int,int> );
int main ()
{
	ios_base::sync_with_stdio(false);
	int i,j,t = 1,ans;
	cin>>h>>w;
	while(h && w)
	{
		start.clear();
		memset(dp,-1,sizeof(dp));
		for(i=0; i<h;++i)
		{
			for(j=0; j<w; ++j)
			{
				cin>>inp[i][j];
				if(inp[i][j] == 'A')
				{
					start.push_back(make_pair(i,j));
				}
			}
		}
		//cout<<"Size of start is : "<<start.size()<<endl;
		ans = 0;
		for(i=0; i<start.size(); ++i)
		{
			ans = max(ans,1+solve(start[i]));
		}
		cout<<"Case "<<t<<": "<<ans<<"\n";
		t++;
		cin>>h>>w;
	}
	return 0;
}
int solve(pair<int,int> val)
{
	char a = inp[val.first][val.second],c;
	int ret = 0,i,j;
	if(dp[val.first][val.second]!=-1)
		return dp[val.first][val.second];
	for(i=-1;i<=1;++i)
	{
		for(j=-1;j<=1;++j)
		{
			/*if(i==0 && j==0) // actually not needed.
				continue;*/
			if( (val.first+i)<0 || (val.second+j)<0 || (val.first+i)>=h || (val.second+j)>=w )
				continue;
			c = inp[val.first+i][val.second+j];
			if(c-1 == a)
				ret = max (ret , 1+solve(make_pair(val.first+i,val.second+j)));
		}
	}
	dp[val.first][val.second] = ret;
	return ret;
}