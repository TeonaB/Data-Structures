#include <iostream>
#include <set>
#include <map>
#include <fstream>
using namespace std;
ifstream f("zeap.in");
ofstream g("zeap.out");
set<int> zeap;
map<int, int> dif;

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

int check(int x) {
    return zeap.count(x);
}

int calcmin() {
    if (zeap.size() < 4) {
        return -1;
    }
    return dif.begin()->first;
}

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
    zeap.insert(2000000005);
    zeap.insert(-1000000005);
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

