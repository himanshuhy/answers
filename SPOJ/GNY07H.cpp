# include <iostream>
# include <cstring>
using namespace std;
int dp[100][5];
int tile(int ,int );
int main ()
{
	ios_base::sync_with_stdio(false);
	int x,n,w,i,temp;
	cin>>n;
	x=n;
	while(n--)
	{
		temp = 0;
		cin>>w;
		if(w==0)
			temp =0;
		else
		{
			for(i = 0; i<5; ++i)
				temp += tile(w,i);
		}
		cout<<x-n<<' '<<temp<<"\n";
		//memset(dp,0,sizeof(dp));
	}
	return 0;
}

int tile (int w,int t)
{
	if(dp[w][t] !=0)
		return dp[w][t];
	if(w==0)//only for t==0 && t==4
		return 1;
	int i,temp =0;
	switch(t)
	{
		case 0:
		if(w==1)
			return 1;
		for(i = 0; i<5 ; ++i)
			temp+=tile(w-1,i);
		break;
		case 1:
		if(w==1)
			return 0;
		else if(w==2)
			temp =1;
		else
		{
			for(i = 0; i<5 ; ++i)
				temp+=tile(w-2,i);
			temp+=tile(w-1,3);
		}
		break;
		case 2:
		if(w==1)
			return 0;
		else if(w==2)
			temp =1;
		else
		{
			for(i = 0; i<5 ; ++i)
				temp+=tile(w-2,i);
			//temp = tile(w-2,0);
			if(w>3)
				temp+=tile(w-2,2);
		}
		break;
		case 3:
		if(w==1)
			return 0;
		else if(w==2)
			temp =1;
		else
		{
			for(i = 0; i<5 ; ++i)
				temp+=tile(w-2,i);
			temp += tile(w-1,1);
		}
		break;
		case 4:
		if(w==1)
			return 0;
		else if(w==2)
			temp =1;
		else
		{
			for(i=0; i<5; ++i)
				temp += tile(w-2,i);
		}
		break;
	}
	dp[w][t] =temp;
	return temp;
}