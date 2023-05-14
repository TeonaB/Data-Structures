#include <fstream>
#include <iostream>
using namespace std;

ifstream f("farfurii.in");
ofstream g("farfurii.out");

int main()
{
    long N, K;
    f>>N>>K;
    long  i=1;
    while((N-i) * (N-i-1) /2 > K)
    {
        g<<i<<" ";
        i++;
    }

    long  dif = K - ((N-i) * (N-i-1)/2);

    g<<i+dif<<' ';

    for(long j =N;j>=i;j--)
        if(j!=i+dif)
            g<<j<<" ";

    return 0;

}
