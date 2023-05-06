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

    f >> n >> k >> numar;
    for (char cifra : numar) {
        while (!stiva.empty() && k > 0 && cifra > stiva.top()) {
            stiva.pop();
            k--;
        }
        stiva.push(cifra);
    }

    while (k > 0)
    {
        stiva.pop();
        k--;
    }

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
