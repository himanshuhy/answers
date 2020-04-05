# include <iostream>
# include <cstring>
using namespace std;
# define MAX 20000
# define endl '\n'
int BIT[MAX+1],n,DATA[MAX+1];
void update(int idx)
{
    while(idx<=n)
    {
        BIT[idx]++;
        idx += idx&(-idx);
    }
}
int read(int idx)
{
    int ret = 0;
    while(idx>0)
    {
        ret += BIT[idx];
        idx -= idx & (-idx);
    }
    return ret;
}
void solve()
{
    int i=0,mark = 1,l,r,jump,beg,en,mid;
    if(n==1)
    {
        DATA[1] = 1;
        return;
    }
    while((i+mark+1)<=n)
    {
        i += (mark+1);
        DATA[i] = mark;
        mark++;
        update(i);
    }
    beg = 1;
    en = n;
    mid = i;
    while(mark<=n)
    {
        beg = 1;
        en = n;
        jump = mark%(n-mark+1)+1;
        int temp = ( (en - mid + 1) - (read(en)-read(mid-1) ) );
        if(jump <= temp)
        {
            jump = jump + (en-mark+1-temp);
        }
        else
        {
            jump = jump - temp;
        }
        while(beg<en)
        {
            mid = (beg+en+1)/2;
            l = read(mid-1) - read(beg-1);
            r = read(en) - read(mid-1);//includes mid pos
            l = mid - beg  - l;
            r = en - mid + 1 - r;
            if(l>=jump)
            {
                en = mid-1;
            }
            else
            {
                jump = jump - l;
                beg = mid;
            }
        }
        DATA[en] = mark;
        update(en);
        mark++;
        mid = en;
    }
}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(BIT,0,sizeof(BIT));
        memset(DATA,0,sizeof(DATA));
        solve();
        for(int i=1;i<=n;++i)
            cout<<DATA[i]<<' ';
        cout<<endl;
    }
    return 0;
}
