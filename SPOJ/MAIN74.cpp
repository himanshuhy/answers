# include <iostream>
# define MOD 1000000007
# define ll long long
using namespace std;
void matrix_exp(ll [][2],ll);
int solve (ll);
int main ()
{
    int t;
    ll value;
    cin>>t;
    while(t--)
    {
        cin>>value;
        if(value==0)
            cout<<"0\n";
        else if(value == 1)
            cout<<"2\n";
        else
            cout<<solve(value)<<"\n";
    }
    return 0;
}
int solve (ll value)
{
    ll pow,ans,matrix[2][2] = {{1,1},{1,0}};
    pow = value +1;
    matrix_exp(matrix,pow);
    ans = matrix[0][0] + matrix[0][1];
    ans = ans % MOD;
    //cout<<"MATRX: \n"<<matrix[0][0]<<"  "<<matrix[0][1]<<endl<<matrix[1][0]<<"  "<<matrix[1][1]<<endl;
    return ans;
}
void matrix_exp(ll matrix[][2],ll n)
{
    ll ret[2][2]={1,0,0,1},temp[2][2];
    while(n)
    {
        if(n&1)
        {
            //ret = ret * matrix
            temp[0][0] = ((ret[0][0]*matrix[0][0])%MOD + (ret[0][1]*matrix[1][0])%MOD)%MOD;
            temp[0][1] = ((ret[0][0]*matrix[0][1])%MOD + (ret[0][1]*matrix[1][1])%MOD)%MOD;
            temp[1][0] = ((ret[1][0]*matrix[0][0])%MOD + (ret[1][1]*matrix[1][0])%MOD)%MOD;
            temp[1][1] = ((ret[1][0]*matrix[0][1])%MOD + (ret[1][1]*matrix[1][1])%MOD)%MOD;
            ret[0][0] = temp[0][0];
            ret[0][1] = temp[0][1];
            ret[1][0] = temp[1][0];
            ret[1][1] = temp[1][1];
        }
        n>>=1;
        temp[0][0] = ((matrix[0][0]*matrix[0][0])%MOD + (matrix[0][1]*matrix[1][0])%MOD)%MOD;
        temp[0][1] = ((matrix[0][0]*matrix[0][1])%MOD + (matrix[0][1]*matrix[1][1])%MOD)%MOD;
        temp[1][0] = ((matrix[1][0]*matrix[0][0])%MOD + (matrix[1][1]*matrix[1][0])%MOD)%MOD;
        temp[1][1] = ((matrix[1][0]*matrix[0][1])%MOD + (matrix[1][1]*matrix[1][1])%MOD)%MOD;
        matrix[0][0] = temp[0][0];
        matrix[0][1] = temp[0][1];
        matrix[1][0] = temp[1][0];
        matrix[1][1] = temp[1][1];
    }
    matrix[0][0] = ret[0][0];
    matrix[0][1] = ret[0][1];
    matrix[1][0] = ret[1][0];
    matrix[1][1] = ret[1][1];
}
