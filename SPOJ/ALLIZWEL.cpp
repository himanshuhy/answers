# include <iostream>
# include <cstring>
# include <vector>
# include <stack>
using namespace std;
char matrix[105][105];
int visited[105][105];
const char check[11] = "ALLIZZWELL";
int r,c,mark;
void DFS(pair<int,int>,int);
int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	int i,j;
	vector <pair<int,int> > v;
	cin>>t; //max 1000
	while(t--)
	{
		cin>>r>>c; //max 100 each
		v.clear();
		mark = 0;
		for(i=0;i<r;++i)
		{
			for(j=0; j<c; ++j)
			{
				cin>>matrix[i][j];
				if(matrix[i][j] == 'A')
					v.push_back(make_pair(i,j));
			}
		}
		for(i=0; i<v.size();++i)
		{
			memset(visited,0,sizeof(visited));//this is  redundant.
			DFS(v[i],0);
			if(mark==1)
			{
				break;
			}
		}
		if(mark)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
void DFS(pair<int,int> p,int n)
{
	int i,j;
	if(n==9)
	{
		mark = 1;
		return;
	}
	visited[p.first][p.second] = 1;
	for(i=-1; i<=1; ++i)
	{
		for(j=-1; j<=1; ++j)
		{
			if(p.first+i <0 ||p.second+j<0 || p.first+i>=r ||p.second+j>=c)
				continue;
			else
			{
				if(visited[p.first+i][p.second+j]==0 && matrix[p.first+i][p.second+j]==check[n+1])
				{
					DFS(make_pair(p.first+i,p.second+j),n+1);
				}
			}
		}
	}
	visited[p.first][p.second] = 0;
}