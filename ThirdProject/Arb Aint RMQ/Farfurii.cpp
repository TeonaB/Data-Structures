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
    ///atata timp cat mai putem inca crea perechi de farfurii cu marimea i afisam
    while((N-i) * (N-i-1) /2 > K)
    {
        g<<i<<" ";
        i++;
    }
    ///calculam pentru restul de marimi de farfurii diferents
    long  dif = K - ((N-i) * (N-i-1)/2);

    g<<i+dif<<' ';
    ///si afisam restul [erechilor
    for(long j =N;j>=i;j--)
        if(j!=i+dif)
            g<<j<<" ";

    return 0;

}
