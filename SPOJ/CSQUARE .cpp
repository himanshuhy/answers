# include <iostream>
# include <cstring>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    long long int t,a,m,ans,sz;
    char b[255];
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>m;
        ans = 1;
        sz = strlen(b);
        for(int i=sz-1;i>=0;--i)
        {
            if(b[i]=='1')
                ans = (ans*a)%m;
            else if(b[i]=='2')
                ans = (((ans*a)%m)*a)%m;
            a = (((a*a)%m)*a)%m; // a^3
        }
        cout<<ans<<"\n";
    }
    return 0;
}
