/*
Himanshu Yadav
2k13 DTU
*/
# include <iostream>
# include <cstring>
using namespace std;
char inp[10][10];
int n;
int calculate();
int DFS(int,int);
int main ()
{
	int marked,ans,a,b,i,j;
	int cas=1; //case
	cin>>n;
	while(n)
	{
		memset(inp,'0',sizeof(inp));
		marked=0;
		for(i=0; i<n; ++i)
		{
			cin>>a>>b;
			for(j=0;j<a;++j)
				inp[i][j]='.';
			for(j=a+b;j<10;++j)
			{
				marked++;
				inp[i][j]='.';
			}
			marked+=a;
		}
		for(i=n;i<10;++i)
		{
			for(j=0;j<10;++j)
			{
				inp[i][j]='.';
				marked++;
			}
		}
		ans = calculate();
		ans = 100-marked-ans;
		if(ans!=1)
			cout<<"Case "<<cas<<", "<<ans<<" squares can not be reached.\n";
		else
			cout<<"Case "<<cas<<", "<<ans<<" square can not be reached.\n";
		cas++;
		cin>>n;
	}
	return 0;
}
int calculate()
{
	//calculate starting position (0,x)
	int i;
	for(i=0;i<10;++i)
	{
		if(inp[0][i]=='0')
			break;
	}
	return DFS(0,i);
}
int DFS(int x,int y)
{
	//check if it is valid
	if(x>=0&&x<10&&y>=0&&y<10)
	{
		if(inp[x][y]=='0')
		{
			inp[x][y]='.';
			int ret = 0;
			ret = max(ret,DFS(x-2,y-1));
			ret = max(ret,DFS(x-2,y+1));
			ret = max(ret,DFS(x-1,y-2));
			ret = max(ret,DFS(x-1,y+2));
			ret = max(ret,DFS(x+1,y-2));
			ret = max(ret,DFS(x+1,y+2));
			ret = max(ret,DFS(x+2,y-1));
			ret = max(ret,DFS(x+2,y+1));
			inp[x][y]='0';
			return ret+1;
		}
		return 0;
	}
	return 0;
}