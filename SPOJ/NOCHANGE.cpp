# include <iostream>
# include <cstring>
using namespace std;
int main ()
{
    int x,k,i,j;
    cin>>x>>k;
    int v[k];
    for(i=0; i<k; ++i)
        cin>>v[i];
    for(i=1; i<k; ++i)
        v[i]+=v[i-1];
    int a[x+1][k];
    memset(a,0,(x+1)*k*4);
    for(j=0; j<k; ++j)
    {
        for(i=j; i<k;++i)
        {
            a[v[j]][i] = 1;
        }
    }
    for(j=0; j<k; ++j)
        for(i=1; i<=x; ++i)
        {
            if(a[i][j])
            {
                if((i+v[j])<=x)
                {
                    for(int m=j; m<k; ++m)
                        a[i+v[j]][m] = 1;
                    //a[i+v[j]][j] = 1;
                }
            }
        }
    /*for(i=0; i<=x; ++i)
    {
        for(j=0; j<k;++j)
        {
            cout<<a[i][j]<<"   ";
        }
        cout<<"i=="<<i<<endl;
    }*/
    if(a[x][k-1])
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
