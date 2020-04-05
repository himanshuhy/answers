# include <iostream>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    long long int sum = 0;
    int temp;
    while (n--)
    {
        cin>>temp;
        sum = sum^temp;
    }
    cout<<sum;
    return 0;
}
