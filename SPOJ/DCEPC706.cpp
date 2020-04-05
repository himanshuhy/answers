/*
Himanshu Yadav
2K13, DTU
*/
# include <iostream>
# include <vector>
# include <cstring>
# include <queue>
# include <climits>
# include <algorithm>

# define rep(i,n) for(i=0;i<n;++i)
# define rep1(i,n) for(i=1;i<n;++i)
# define endl '\n'
using namespace std;

int m,n;
char inp[205][205];
bool visited[205][205];
int dis1[205][205],dis2[205][205],dis3[205][205];
vector < pair<int,int> > in;
bool iscorrect(pair<int,int> p)
{
	int x = p.first;
	int y = p.second;
	if(x<0 || x>(m+1) || y<0 || y>(n+1))
		return 0;
	return 1;
}
void BFS(pair<int,int>,int [][205]);
int main ()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		in.clear();
		memset(dis1,0,sizeof(dis1));
		memset(dis2,0,sizeof(dis2));
		memset(dis3,0,sizeof(dis3));
		rep1(i,m+1)
		{
			rep1(j,n+1)
			{
				cin>>inp[i][j];
				if (inp[i][j]  != '.' && inp[i][j]  != '#')
					in.push_back(make_pair(i,j));
				if(inp[i][j] == '#')
					dis1[i][j] = dis2[i][j] = dis3[i][j] = INT_MAX;
			}
		}
		rep(i,m+2)
		{
			inp[i][0] = '.';
			inp[i][n+1] = '.';
		}
		rep(i,n+2)
		{
			inp[0][i] = '.';
			inp[m+1][i] = '.';
		}
		BFS(in[0],dis1);
		BFS(in[1],dis2);
		BFS(in[2],dis3);
		int mi = INT_MAX;
		rep(i,m+2)
		{
			rep(j,n+2)
			{
				if(visited[i][j])
					mi = min(mi,max(dis1[i][j],max(dis2[i][j],dis3[i][j])));
			}
		}
		/*cout<<"******\n";
		rep(i,m+2)
		{
			rep(j,n+2)
			{
				cout<<dis1[i][j]<<"  ";
			}
			cout<<endl;
		}
		cout<<"******\n";
		rep(i,m+2)
		{
			rep(j,n+2)
			{
				cout<<dis2[i][j]<<"  ";
			}
			cout<<endl;
		}
		cout<<"******\n";
		rep(i,m+2)
		{
			rep(j,n+2)
			{
				cout<<dis3[i][j]<<"  ";
			}
			cout<<endl;
		}
		cout<<"******\n";*/
		cout<<mi<<endl;
	}
	return 0;
}
void BFS (pair<int,int> p, int A[][205])
{
	memset(visited,0,sizeof(visited));
	queue <pair <int,int> > q;
	q.push(p);
	A[p.first][p.second] = 0;
	visited[p.first][p.second] = 1;
	pair <int,int> top;
	int x,y;
	while(!q.empty())
	{
		top = q.front();
		x=top.first;
		y=top.second;
		q.pop();
		if(x<0 || x>(m+1) || y<0 || y>(n+1)) // this is useless.
		{
			continue;
		}
		else
		{
			if(iscorrect(make_pair(x+1,y)) && !visited[x+1][y] && inp[x+1][y]!='#' )
			{
				q.push(make_pair(x+1,y));
				A[x+1][y] = A[x][y]+1;
				visited[x+1][y] = 1;
			}
			if(iscorrect(make_pair(x,y+1)) && !visited[x][y+1] && inp[x][y+1]!='#' )
			{
				q.push(make_pair(x,y+1));
				A[x][y+1] = A[x][y]+1;
				visited[x][y+1] = 1;
			}
			if(iscorrect(make_pair(x-1,y)) && !visited[x-1][y] && inp[x-1][y]!='#' )
			{
				q.push(make_pair(x-1,y));
				A[x-1][y] = A[x][y]+1;
				visited[x-1][y] = 1;
			}
			if(iscorrect(make_pair(x,y-1)) && !visited[x][y-1] && inp[x][y-1]!='#' )
			{
				q.push(make_pair(x,y-1));
				A[x][y-1] = A[x][y]+1;
				visited[x][y-1] = 1;
			}
		}
	}
}
