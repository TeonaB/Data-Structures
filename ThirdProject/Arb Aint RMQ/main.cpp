#include <iostream>
#include <fstream>

using namespace std;
ifstream f("order.in");
ofstream g("order.out");
const int NMAX = 30000;
int aib[NMAX + 1];

// Functia adauga() actualizeaza vectorul aib adaugand x la fiecare element incepand de la pozitia i pana la n
void adauga(int i, int n, int x) {
    for (; i <= n; i += (i & -i))
        aib[i] += x;
}

// Functia afiseaza() implementeaza algoritmul Josephus pentru a determina ordinea de eliminare a persoanelor din cerc
void afiseaza(int n) {
    int nr = 1, rezerva = n;  // Variabilele nr si rezerva retin informatii despre numarul curent si numarul de persoane ramase
    for (int i = 1; i <= n; i++) {
        nr = ((nr + i - 1) % rezerva) + 1;  // Calculam urmatoarea pozitie de eliminare a persoanei
        int miscare = (1 << 14), pozitie = 0, sum = 0;  // Variabilele miscare, pozitie si sum sunt folosite pentru a naviga prin vectorul aib
        while (miscare) {  // Parcurgem bitii valorii miscare
            if (pozitie + miscare <= n && sum + aib[pozitie + miscare] < nr) {  // Daca pozitia curenta + miscare nu depaseste n si suma curenta + valoarea din aib[pozitie + miscare] este mai mica decat nr
                sum += aib[pozitie + miscare];  // Actualizam suma curenta
                pozitie += miscare;  // Actualizam pozitia curenta
            }
            miscare >>= 1;  // Shiftam miscare-ul la dreapta
        }
        rezerva--;  // Scadem numarul de persoane ramase
        nr--;  // Scadem numarul curent
        adauga(pozitie + 1, n, -1);  // Eliminam persoana de pe pozitie
        g << pozitie + 1 << " ";
    }
}
int main()
{
    int n;
    f >> n;
    for(int i = 1; i <= n; i++)
        adauga(i, n, 1);
    afiseaza(n);
    return 0;
}
