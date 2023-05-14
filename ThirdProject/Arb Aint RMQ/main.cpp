#include <fstream>
#include <iostream>
using namespace std;
ifstream f("kami.in");
ofstream g("kami.out");
int N,M,z[100001],sum,maxim;
void zapada(int a)
{
    sum=0;
    sum += z[a];
    a--;
    while(sum > z[a] && sum<=maxim)
    {
        sum += z[a];
        a--;
    }
    if(sum>maxim)
        g<<0<<'\n';
    else
        g<<a<<'\n';
}
int main()
{   z[0]=10000000000;
    maxim=0;
    f>>N;
    for(int i=1; i<=N; i++)
        {f>>z[i];
        maxim=max(maxim,z[i]);}
    f>>M;
    for(int i=1; i<=M; i++)
    {
        int x,y,a,b;
        f>>x;
        if(x==1)
        {
            f>>y;
            zapada(y);
        }
        else
        {
            f>>a>>b;
            z[a]=b;
            maxim=max(maxim,z[i]);
        }
    }
    return 0;

}
