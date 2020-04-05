# include <iostream>
# include <string>
# include <sstream>
# include <algorithm>
//# define endl '\n'
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string line,s,l;
	int t,ans,len,prev_len,count;
	cin>>t;
	stringstream ss;
	getline(cin,s);
	while(t--)
	{
		getline(cin,line);
		ss.write(line.c_str(),100000);//start ss with the line
		prev_len = len = count = ans = 0;
		//stringstream ss(line);
		while(ss >> s)//>> operator skips/stops at <space> and <\n> chars
		{
			len = s.size();
			if(len == prev_len)
			{
				count++;
			}
			else
			{
				ans = max(ans,count);
				count = 1;
				prev_len = len;
			}
		}
		ans = max(ans,count);
		cout<<ans<<endl;
	}
	return 0;
}