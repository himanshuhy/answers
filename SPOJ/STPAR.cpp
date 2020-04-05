#include <iostream>
using namespace std;
int inp[1001],side_street[10001];
int main ()
{
	int n,top,current,i;
	cin>>n;
	while(n!=0)
	{
		top = 0;
		current = 1;
		for(i=0;i<n;i++)
		{
			cin>>inp[i];
		}
		i=0;
		while(current <= n)
		{
			//cout<<"n ="<<n<<endl<<"current = "<<current<<endl<<"i ="<<i<<endl;		
			if(i<n &&inp[i] == current)
			{
				current++;
				++i;
			}
			else if(top>0 && current == side_street[top-1])
			{
				top--;
				current++;
			}				
			else if(top>0 && inp[i] < side_street[top-1])
			{
				side_street[top] = inp[i];
				
				top++;
				++i;
			}
			else if(top==0)
			{
				side_street[top] = inp[i];
				top++;
				++i;
			}
			else
			{
				break;
			}
		}
		//cout<<"current = "<<current<<endl;
		if(current > n)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
		cin>>n;
	}
    return 0;
}
