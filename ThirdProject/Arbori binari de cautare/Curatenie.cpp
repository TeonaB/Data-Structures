#include <fstream>
using namespace std;
ifstream f("curatenie.in");
ofstream g("curatenie.out");
int n, v[500001], stg[500000], dr[500000];
int curatenie(int i, int j)
    {   if (i>j)
            return 0;
        int aux;
        f>>aux;
        stg[aux] = curatenie(i, v[aux]-1);
        dr[aux] = curatenie(v[aux]+1, j);

        return aux;
    }
int main()
{
    f>>n;
    int x;
    for(int i=0; i<n; i++)
        {
            f>>x;
            v[x] = i;
        }
    curatenie(0, n - 1);

    for(int i=1; i<=n; i++)
        g<<stg[i]<<" "<<dr[i]<<'\n';

    return 0;
}
