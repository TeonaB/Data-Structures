#include <fstream>
#include <stack>
#include <string>

using namespace std;
ifstream f("alibaba.in");
ofstream g("alibaba.out");
int main() {
    int n, k;
    string numar;
    stack<char> stiva;
    ///folosim stiva ca sa ne fie mai usor sa cautam numarul
    f >> n >> k >> numar;
    for (char cifra : numar) {
        ///eliminam din stiva atata timp cat cifra este mai mare decat ultima si ne permite k
        while (!stiva.empty() && k > 0 && cifra > stiva.top()) {
            stiva.pop();
            k--;
        }
        ///nu uitam sa actualizam cifra
        stiva.push(cifra);
    }
    ///daca mai avem cum mai dam pop la final
    while (k > 0)
    {
        stiva.pop();
        k--;
    }
    ///pentru a afla numarul dam pop si il afisam  ca sa fie in ordinea corecta
    string cifre_ramase;
    while (!stiva.empty())
    {
        cifre_ramase += stiva.top();
        stiva.pop();
    }
    for (int i = cifre_ramase.size() - 1; i >= 0; i--)
        g << cifre_ramase[i];

    return 0;
}
