# include <iostream>

using namespace std;
int main ()
{
	ios_base::sync_with_stdio(false);
	int n,m,p,q,i,intersection_lim;
	long long int sum;
	cin>>n;
	while(n!=0)
	{
		int A[n];
		for(i=0;i<n;++i)
			cin>>A[i];
		cin>>m;
		int B[m];
		for(i=0;i<m;++i)
			cin>>B[i];
		int intersections[n+1];
		p=q=i=0;
		while(p<n && q<m)
		{
			if(A[p]==B[q])
			{
				intersections[i] = A[p];
				i++;
				p++;
				q++;
			}
			else if(A[p] < B[q])
			{
				p++;
			}
			else //A[p] > B[q]
				q++;
		}
		intersection_lim = i;
		intersections[intersection_lim] = A[n-1];//temp value, used for inter_sum_a calculations
		int inter_sum_a[intersection_lim+1];
		int inter_sum_b[intersection_lim+1];
		p=i=0;
		sum =0;
		while(p<n)
		{
			if(A[p]==intersections[i])
			{
				inter_sum_a[i] = intersections[i] + sum;
				sum =0;
				p++;
				i++;
			}
			else
			{
				sum +=A[p];
				p++;
			}
		}
		for(int j=i;j<intersection_lim+1;++j)
			inter_sum_a[j] =0;
		q=i=0;
		sum =0;
		intersections[intersection_lim] = B[m-1];//temp value, used for inter_sum_b calculations
		while(q<m)
		{
			if(B[q]==intersections[i])
			{
				inter_sum_b[i] = intersections[i] + sum;
				sum =0;
				q++;
				i++;
			}
			else
			{
				sum +=B[q];
				q++;
			}
		}
		for(int j=i;j<intersection_lim+1;++j)
			inter_sum_b[j] =0;
		i=sum=0;
		while(i<=intersection_lim)
		{
			sum += max(inter_sum_b[i],inter_sum_a[i]);
			++i;
		}
		cout<<sum<<'\n';
		// end
		cin>>n;
	}
	return 0;
}