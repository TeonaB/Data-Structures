#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;
ifstream f("paranteze.in");
ofstream g("paranteze.out");
int max_paranteze(string sir, int n)
{   ///folosim stack pentru a putea vedea top-ul usor
    stack <int> s;
    int v[n]; ///cu acest vector marcam parantezele corecte
    for(int i=0; i<n; i++)
    {   ///verificam sa incepem cu o paranteza deschisa si adaugam in stiva 
        if(sir[i]=='('||sir[i]=='['||sir[i]=='{')
                s.push(i);
        else ///daca nu incepem cu paranteza ori avem stiva goala si adaugam indicele 
            if (!s.empty()) ///ori verificam daca parantezele si secventa se vor inchide bine in capete si atunci le marcam cu 1 in vector
                if((sir[s.top()] == '{' && sir[i]=='}')||(sir[s.top()] == '[' && sir[i]==']')||(sir[s.top()] == '(' && sir[i]==')'))
                {
                    v[i] = 1;
                    v[s.top()] = 1;
                    s.pop();
                }
                else
                    s.push(i);
    }
    int lung = 0, max_len = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == 1)
        {
            lung++;
            max_len=max(max_len,lung);
        }
        else
            lung = 0;

    return max_len;
}

int main() {
    int n;
    string paranteze;
    f >> n >> paranteze;
    g << max_paranteze(paranteze,n) << endl;
    return 0;
}
