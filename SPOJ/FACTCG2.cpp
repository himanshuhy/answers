# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <vector>
# define endl '\n'
# define ll long long int
# define MAX 10000000
using namespace std;
vector <int> nprime;
bool sieve[MAX+5];//0 is a prime
int size;
void init()
{
    int i,j;
    for(i=2;i<3163;++i)
    {
        if(sieve[i]==0)
        {
            nprime.push_back(i);
            for(j=i*i;j<MAX;j+=i)
                sieve[j]=1;
        }
    }
    for(;i<MAX;++i)
        if(sieve[i]==0)
        nprime.push_back(i);
    size=nprime.size();
}
int main ()
{
    init();
    int n;
    //printf("%d",nprime[0]);
    while(scanf("%d",&n)!=EOF)
    {
        printf("1");
        if(n==1)
        {
            printf("\n");
            continue;
        }
        //for 2
        while( (n&1) ==0)
        {
            printf(" x 2");
            n>>=1;
        }
        for(int i=1;i<size&&n>1;++i)
        {
            if(sieve[n]==0)//n is prime
            {
                printf(" x %d",n);
                break;
            }
            while(n%nprime[i]==0 && n>1)
            {
                n = n/nprime[i];
                printf(" x %d",nprime[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
