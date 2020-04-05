# include <iostream>
# define endl '\n'
typedef long long int ll;
using namespace std;
ll n,A[100005],temp[100005];
ll ans,sum,big;
void merge_sort(ll,ll);
void merge(ll,ll,ll);
int main ()
{
	ll t,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0; i<n; ++i)
			cin>>A[i];
		ans = sum = big = 0;
		merge_sort(0,n-1);
		for(i=1; i<n; ++i)
		{
			big += A[i-1];
			ans+=big;
		}
		cout<<ans-sum<<endl;
	}
	return 0;
}
void merge_sort(ll lo, ll hi)
{
	if(lo < hi)
	{
		ll mid = (lo + hi)/2;
		merge_sort(lo,mid);
		merge_sort(mid+1,hi);
		merge(lo,hi,mid);
		return;
	}
}
void merge(ll lo,ll hi, ll mid)
{
	ll a,b,c;
	a=lo;
	b=mid+1;
	c=lo;
	while(a <= mid && b <=hi)
	{
		if(A[a] < A[b])
		{
			temp[c] = A[a];
			c++;
			a++;
		}
		else if (A[a] >= A[b])
		{
			temp[c] = A[b];
			sum += A[b] * ( ll )(mid - a + 1);
			b++;
			c++;			
		}
	}
	while(a <= mid)
	{
		temp[c] = A[a];
		a++;
		c++;
	}
	while(b <= hi)
	{
		temp[c] = A[b];
		b++;
		c++;
	}
	for(ll i= lo; i<=hi ;++i)
		A[i] = temp[i];
	return;
}