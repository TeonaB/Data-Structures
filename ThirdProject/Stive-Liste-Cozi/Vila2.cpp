#include <fstream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;
ifstream f("vila2.in");
ofstream g("vila2.out");
int main()
{
    int n, k;
    f>> n >> k;
    ///cream vectorul cu varstele locatarilor
    vector<int> ages(n);
    for (int i = 0; i < n; i++)
        f >> ages[i];
    ///stocam indicii in deque pentru intervalul k
    deque<int> a,b;

    int max_diff = 0;
    /// in a retinem  indicii persoanelor în ordinea descrescătoare a vârstelor
    /// in b retinem  indicii persoanelor în ordinea crescătoare a vârstelor
    for (int i = 0; i < n; i++)
    {
        if (a.front() < i - k)  ///le eliminam indicii persoanelor care nu mai sunt în intervalul curent in stânga deque-ului
            a.pop_front();
        ///se elimină indicii persoanelor cu vârste mai mici decât vârsta persoanei curente 
        while (!a.empty() && ages[a.back()] < ages[i])
            a.pop_back();
        a.push_back(i);
        ///adaugam indicele in a si apoi aplicam acelasi lucru si pentru b doar ca crescator
        ///nu uitam sa adaugam in b
        if (b.front() < i - k)
            b.pop_front();
        while (!b.empty() && ages[b.back()] > ages[i])
            b.pop_back();
        b.push_back(i);
        ///calculam diferenta maxima pentru fiecare i cu maxim
        max_diff = max(max_diff, ages[a.front()] - ages[b.front()]);
    }
    g<< max_diff << endl;

    return 0;
}
