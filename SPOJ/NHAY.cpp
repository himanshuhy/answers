# include <iostream>
# include <string>

using namespace std;

int main ()
{
	ios_base::sync_with_stdio(false);
    int n,m,mark;
    string nee,hay; // needle and haystack
    while(cin>>m)
    {
    	mark = 0;
        cin>>nee>>hay;
        int T[m]; //computing the auxilary function t
        int q,k;
        n = hay.length();
        T[0] = 0;
        k = 0;
        //cout<<"Hello";
        for(q =1; q<m; ++q)
        {
        	while(k>0 && nee[k] != nee[q])
        	{
        		k = T[k-1];
        	}
        	if(nee[k] == nee[q])
        	{
        		++k;
        	}
        	T[q] = k;
        }
        /*for(int i=0; i<m ; ++i)
        	cout<<i<<"  "<<T[i]<<endl;*/
        //prefix function constructed
        //now comparing with the string
        //cout<<"n="<<n<<endl;
        q=0;
        for (int i=0; i<n; ++i)
        {
        	while(q>0 && hay[i] != nee[q])
        	{
        		//cout<<"HELLO"<<endl;
        		q=T[q-1];
        	}
        	if(hay[i] == nee[q])
        		++q;
        	if(q==m)
        	{
        		cout<<i-q+1<<'\n';
        		q = T[q-1];
        		mark = 1;
        	}
        }
        if(mark == 0)
        	cout<<'\n';
    }
    return 0;
}
