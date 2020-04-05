# include <iostream>
# include <cstring>
# include <stack>
using namespace std;
const int n = 1000+5;
char inp[n][n];
int ans[n][n];
int main ()
{
	ios_base::sync_with_stdio(false);
	int n,i,j;
	long long int num = 1;
	for(i=0; i<31;++i)
		num = num<<1;
	num--;
	cin>>n;
	//char inp[n][n];
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			//cin.get(inp[i][j]);
			cin>>inp[i][j];
		}
	}
	//int ans[n][n];
	memset(ans,0,sizeof(ans));
	ans[0][0] = 1;
	for(i=1;i<n;++i)
	{
		if(inp[i][0] == '.')
			ans[i][0] = ans[i-1][0];
		if(inp[0][i] == '.')
			ans[0][i] = ans[0][i-1];
	}
	for(i=1;i<n;++i)
	{
		for(j=1;j<n;++j)
		{
			if(inp[i][j] == '.')
				ans[i][j] = ((ans[i-1][j])%num + (ans[i][j-1])%num)%num;
		}
	}
	
	if(ans[n-1][n-1]!=0)
		cout<<ans[n-1][n-1]<<"\n";
	else
	{
		int top_x,top_y,flag = 0;
		stack <pair<int,int> > s;
		int visited[n][n];
		memset (visited,0,sizeof(visited));
		s.push(make_pair(0,0));
		while(!s.empty())
		{
			top_x = s.top().first;//actually it is y axis :P
			top_y = s.top().second;
			s.pop();
			if((top_x<0) || (top_x>=n) || (top_y<0)|| (top_y>=n))
			{
				//s.pop();
				continue;
			}
			else if((inp[top_x][top_y] == '.') && ( visited[top_x][top_y]==0))
			{
				visited[top_x][top_y] = 1;
				if((top_x == n-1) && (top_y== n-1))
				{
					break;
				}
				else
				{
					s.push(make_pair(top_x,top_y-1));
					s.push(make_pair(top_x,top_y+1));
					s.push(make_pair(top_x-1,top_y));
					s.push(make_pair(top_x+1,top_y));
				}
			}
			/*else
			{
				s.pop();// pop out '#' and already visited '.'
			}*/
		}
		if(visited[n-1][n-1]==1)
			cout<<"THE GAME IS A LIE\n";
		else
			cout<<"INCONCEIVABLE\n";
	}
	return 0;
}