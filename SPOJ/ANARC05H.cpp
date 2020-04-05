# include <iostream>
# include <string>
using namespace std;
int sum[27];
int function(string, int, int);
int main()
{
	string inp;
	int len, i,k=1;
	cin>>inp;
	while(inp != "bye")
	{
		len = inp.length();
		sum[0] = int(inp[0]-'0');
		for(i=1 ; i<len; ++i)
		{
			sum[i] = int(inp[i]-'0') + sum[i-1];
		}
		cout<<k++<<". "<<function(inp,len-1, sum[len-1])<<"\n";
		cin>>inp;
	}
	return 0;
}
int function(string inp, int start, int num)
{
    int count = 0;
	int x;
	if(start<0)
        return 1;
	else
	{
	    x =int(inp[start]-'0');
        if(x<=num)
        {
            count = function(inp, start-1, x);
        }
		for(int i=start-1; i>=0; --i)
		{
			x =sum[start]-sum[i]+int(inp[i]-'0');
			if( x <= num)
			count += function(inp,i-1,x);
		}
	}
	return count;
}
