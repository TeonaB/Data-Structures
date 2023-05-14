#include <fstream>
using namespace std;
ifstream f("planeta.in");
ofstream g("planeta.out");
long long n,k;
long long v[65];
void planeta(long i, long j, long long a)
{
    int radacina=i;
    while(radacina<j && a-v[radacina-i]*v[j-radacina]>=0)
    {
        a=a-v[radacina-i]*v[j-radacina];
        radacina+=1;
    }
    g<<radacina<<" ";

    if(radacina>i)
        planeta(i,radacina-1, a/v[j-radacina]);
    if(radacina<j)
        planeta(radacina+1, j, a%v[j-radacina]);
}

int main()
{

    v[0]=1;
    f>>n>>k;
    for(int i=1;i<=64;i++)
        for(int j=1;j<=i;j++)
            v[i]+=v[j-1]*v[i-j];
    planeta(1,n,k-1);

    return 0;
}
