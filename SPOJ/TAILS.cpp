# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>
using namespace std;

int n,a;
int dp[1<<20];
queue <int> q;
int mark(int in,int index)
{
	if(index == 0)
		in = in^3;
	else if(index==19)
		in = in^786432;
	else
	{
		index = index-1;
		in = in^(7<<index);
	}
	return in;
}
void solve()
{
	int i,temp1,temp2;
	dp[0]=0;
	dp[3]=dp[786432]=1;
	q.push(3);
	q.push(786432);
	int temp=7;
	for(i=0; i<=17; ++i)
	{
		dp[temp]=1;
		q.push(temp);
		temp<<=1;
	}
	int j=0;
	while(!q.empty())
	{
		temp1 = q.front();
		q.pop();
			if(temp1 == 1047552)
				cout<<"YES\n";
		for(i=0; i<=19;++i)
		{
			temp2 = mark(temp1,i);
			if(dp[temp2]==-1)
			{
				q.push(temp2);
				dp[temp2]=dp[temp1]+1;
			}
		}
	}
}
int main ()
{
	memset(dp,-1,sizeof(dp));
	/*char inp[21];
	scanf("%s",inp);
	for(int i=19,t=1; i>=0;--i)
	{
		if(inp[i]=='1')
			n+=t;
		t<<=1;
	}*/
	int c=19,k;
    int  s=0;
    while(c>=0)
    {
        cin >> k;
        if(k==1)
            s|=(1<<c);
        c--;
    }
	solve();
	printf("%d\n",dp[s]);
	return 0;
}