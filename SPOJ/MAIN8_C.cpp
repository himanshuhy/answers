# include <iostream>
# include <climits>
using namespace std;
# define endl '\n'
# define ll long long int
ll n,k,candy[50005],maxc;
bool check(ll mid)
{
    //check if mid no of candy's can be distributed to all
    ll tempk=k;
    for(ll i=0;i<n;++i)
    {
        tempk-=candy[i]/mid;
    }
    if(tempk<=0)return 1;
    return 0;
}
ll solve()
{
    ll lo=1,hi=maxc,mid;//lo==0?
    mid=(lo+hi+1)/2;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(check(mid))//successful
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(check(lo))return lo;//l0==hi
    return 0;
}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        maxc=0;
        for(ll i=0;i<n;++i)
        {
            cin>>candy[i];
            if(maxc<candy[i])maxc=candy[i];
        }
        //i/p done
        cout<<solve()<<endl;
    }
    return 0;
}
