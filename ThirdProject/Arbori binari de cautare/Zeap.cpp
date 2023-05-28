#include <iostream>
#include <set>
#include <map>
#include <fstream>
using namespace std;
ifstream f("zeap.in");
ofstream g("zeap.out");
set<int> zeap;
map<int, int> dif;
///vom utiliza set ul pentru a implementa zeap-ul din enunt
///cand il inseram trebuie sa verificam daca mai exista si sa il inseram
///nu uitam sa actualizam diferenta pentru elemente
void insert(int x) {
    if (zeap.count(x)) {
        return;
    }

    auto it1 = zeap.lower_bound(x);
    auto it2 = it1 == zeap.begin() ? zeap.end() : prev(it1);
    int x1 = it1 == zeap.end() ? *prev(it1) : *it1;
    int x2 = it2 == zeap.end() ? *prev(it2) : *it2;
    zeap.insert(x);
    if (x1 - x2 >= 0) {
        dif[x1 - x2]--;
    }
    if (x1 - x >= 0) {
        dif[x1 - x]++;
    }
    if (x - x2 >= 0) {
        dif[x - x2]++;
    }

}
///pentru stergere verificam daca exista si dupa il stergem si actualizam iar pozitiile si diferentele din map si zeap
int erase(int x) {
    if (!zeap.count(x)) {
        return -1;
    }

    auto it1 = zeap.upper_bound(x);
    auto it2 = prev(zeap.lower_bound(x));
    int x1 = it1 == zeap.end() ? *prev(it1) : *it1;
    int x2 = it2 == zeap.end() ? *prev(it2) : *it2;

    if (x1 - x >= 0) {
        dif[x1 - x]--;
    }
    if (x - x2 >= 0) {
        dif[x - x2]--;
    }
    if (x1 - x2 >= 0) {
        dif[x1 - x2]++;
    }
    zeap.erase(x);
    return 0;
}
/// folosim un count pentru a verifica daca exista
int check(int x) {
    return zeap.count(x);
}
///pentru minim folosim map-ul creat si prima valoare
int calcmin() {
    if (zeap.size() < 4) {
        return -1;
    }
    return dif.begin()->first;
}
//pentru maxim folosim valorile din ambele capete
int calcmax() {
    if (zeap.size() < 4) {
        return -1;
    }
    auto it1 = zeap.begin();
    auto it2 = zeap.end();
    it2--;
    it2--;
    it1++;
    return *it2 - *it1;
}

int main() {
    ///inseram valori in ambele capete ca sa nu iesim din zeap
    zeap.insert(1000000000);
    zeap.insert(-1000000000);
    string op;
    int x;
    while (f >> op) {
        if (op == "I") {
            f >> x;
            insert(x);
        }
        else if (op == "S") {
            f >> x;
            int res = erase(x);
            if (res == -1) {
                g << "-1\n";
            }
        }
        else if (op == "C") {
            f >> x;
            g << check(x) << "\n";
        }
        else if (op == "MIN") {
            g << calcmin() << "\n";
        }
        else if (op == "MAX") {
            g << calcmax() << "\n";
        }
    }

    return 0;
}

