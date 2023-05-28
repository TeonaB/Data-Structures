#include <fstream>
#include <iostream>
using namespace std;

ifstream f("kami.in");  
ofstream g("kami.out");  

int N, M, z[100001], sum, maxim;  

void zapada(int a)
{
    sum = 0;
    sum += z[a];  // Adaugam valoarea din nivelul z[a] la suma
    a--;  
    while (sum > z[a] && sum <= maxim)
    {
        sum += z[a];  
        a--;  // Coboram ca si nivel
    }
    if (sum > maxim)
        g << 0 << '\n';  // Daca ajungem la baza
    else
        g << a << '\n';  // Atfel va fi o afisare normala
}

int main()
{
    z[0] = 10000000000;  // Initializam nivelul z[0] cu o valoare mare
    maxim = 0;  // Initializam variabila maxim cu 0

    f >> N;  
    for (int i = 1; i <= N; i++)
    {
        f >> z[i];  
        maxim = max(maxim, z[i]);  // Actualizam valoarea maxim
    }
    ///conform cerintei, in functi de ce x citim efectuam operatiile
    f >> M;  
    for (int i = 1; i <= M; i++)
    {
        int x, y, a, b;
        f >> x;  
        if (x == 1)
        {
            f >> y; 
            zapada(y);  
        }
        else
        {
            f >> a >> b;  
            z[a] = b;  // Actualizam valoarea nivelului z[a] cu b
            maxim = max(maxim, z[i]);  // Actualizam valoarea maxim
        }
    }

    return 0;  
}
