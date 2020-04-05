#include <iostream>
#include <algorithm>
using namespace std;
int G[1000000],M[1000000];
int main ()
{
    int t;
    cin>>t;
    int ng,nm;
    int min_g,min_m;
    for(int i=0;i<t;i++)
    {
        cin>>ng>>nm;
        if(ng == 0)
        {
            if(nm == 0)
                cout<<"uncertain"<<endl;
            else
                cout<<"MechaGodzilla"<<endl;
            continue;
        }
        if(nm == 0)
        {
            cout<<"Godzilla"<<endl;
            continue;
        }
        for(int j=0;j<ng;++j)
            cin>>G[j];
        for(int j=0;j<nm;++j)
            cin>>M[j];
        sort(G,G+ng);
        sort(M,M+nm);
        min_g = 0;
        min_m = 0;
        while(min_g != ng && min_m != nm)
        {
            if(M[min_m] == G[min_g])
            {
                min_m++;
            }
            else if(M[min_m] > G[min_g])
            {
                min_g ++;
            }
            else if(M[min_m] < G[min_g])
            {
                min_m ++;
            }
        }
        //cout<<min_g<<endl<<min_m<<endl;
        if(min_g == ng)
            cout<<"MechaGodzilla"<<endl;
        else
            cout<<"Godzilla"<<endl;
    }
    return 0;
}
