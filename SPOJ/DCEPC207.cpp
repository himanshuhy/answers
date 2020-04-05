# include <iostream>
# include <sstream>
# include <cstring>
# include <string>
# include <cstdlib>
# include <cstdio>
# define endl '\n'
using namespace std;
char maxf;
int ch[26];//to count frequency of each element
bool correct(string in)
{
    int c[26] = {};//initialize to 0
    int len = in.length();
    for(int i=0;i<len;++i)
    {
        c[int(in[i])-97]++;
    }
    int max1=0;
    char mx=0;
    for(int i=0;i<26;++i)
    {
        if(c[i]>max1)
        {
            max1 = c[i];
            mx = char(i+97);
        }
    }
    for(int i=0;i<26;++i)
    {
        if(c[i] == max1 )
        {
            if(mx != char(i+97))
                return 0;
        }
    }
    if(mx == maxf)
        return 1;
    return 0;
}
int main ()
{
    char arr[10];
    cin.getline(arr,10,'\n');
    int t;
    string inp,name;
    t = atoi(arr);
    int k = 1;
    while(t--)
    {
        getline(cin,inp);
        int len = inp.size();
        int temp;
        stringstream ss(inp);
        memset(ch,0,sizeof(ch));
        for(int i=0;i<len;++i)
        {
            if(inp[i]<'a' || inp[i]>'z')continue;
            ch[int(inp[i])-97]++;
        }
        temp = ch[0];
        maxf = 'a';
        for(int i=0;i<26;++i)
            if(ch[i]>temp)
            {
                temp = ch[i];
                maxf = char(i+97);
            }
        cout<<"Case #"<<k++<<":\n";
        while(ss>>name)
        {
            if(correct(name))
            {
                cout<<name<<endl;
            }
        }
    }
    return 0;
}
