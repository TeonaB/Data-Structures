#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream f("baruri.in");
ofstream g("baruri.out");
int t, n, m, op, b, d, x;
int aib[100005];
int lsb(int x)
{
    return (x&(-x));
}
void update(int x, int val)
{
    while(x <= n)
    {
        aib[x] += val;
        x += lsb(x);
    }
}
int suma(int x)
{
    int sum=0;
    while(x > 0)
    {
        sum += aib[x];
        x -= lsb(x);
    }
    return sum;
}
int main()
{
    f >> t;

    while (t--)
    {
        f >> n;
        for (int i = 1; i <= n; i++)
            {f >> x;
             update(i, x);}

        f >> m;
        while (m--)
        {
            f >> op;
            if (op == 0)
            {
                f >> b >> d;
                g << suma( min(n, b+d) ) - suma(b) + suma(b-1) - suma( max(b-d-1, 0) ) << '\n';
            }
            else if (op == 1)
            {
                f >> x >> b;
                update(b,x);
            }
            else if (op == 2)
            {
                f >> x >> b;
                update(b,-x);
            }
            else if (op == 3)
            {
                f >> x >> b >> d;
                update(b,-x);
                update(d,x);
            }
        }
        for (int i = 1; i <= n; i++)
            aib[i]=0;
    }
    return 0;
}
