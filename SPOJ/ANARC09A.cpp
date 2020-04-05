# include <iostream>
# include <string>
# include <stack>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    stack <int> inp;
    string input;
    int len,count,j;
    cin>>input;
    j=1;
    while(input[0]!='-')
    {
        count = 0;
        len = input.length();
        for(int i=0;i<len;++i)
        {
            if(input[i] == '{')
            {
                inp.push(1);
            }
            else
            {
                if(inp.empty())
                {
                    count++;
                    inp.push(1);
                }
                else
                    inp.pop();
            }
        }
        if(!inp.empty())
        {
            count += inp.size() / 2;
        }
        cout<<j<<". "<<count<<'\n';
        while(!inp.empty())
            inp.pop();
        cin>>input;
        j++;
    }
    return 0;
}
