#include <iostream>
#include <cstring>
using namespace std;

long long int ans[5001];

int main ()
{
	char code[5000];
	int len;
	ans[0] = ans[1] = 1;
	while(1)
	{
		cin>>code;
		if(code[0] == '0')
			break;
		else
		{
			//memset(ans,-1,5001);
			len = strlen(code);
			for(int i=0; i < len ; ++i) // maybe len-1??
			{

				/*if(code[i+2] == '0')
				{
					ans[i+1]=ans[i];
				}*/
				if(code[i+1] == '0')
				{
					ans[i+1+1+1]=ans[i+1+1] = ans[i+1]=ans[i];
					i++;
				}
				else
				{
					if(code[i] == '1' )
						ans[i+1+1] = ans[i+1] + ans[i-1+1];//what if i=0 6= 54
					else if(code[i] == '2')
					{
						if (code[i+1] <= 54 ) // 1-6
						{
							ans[i+1+1] = ans[i+1] + ans[i-1+1];
						}
						else
						{
							ans[i+1+1] = ans[i+1];
						}
					}
					else if(code[i] >50)
					{
						ans[i+1+1] = ans[i+1];
					}
				}
			}
		}
		cout<<ans[len]<<endl;
	}
	return 0;
}
