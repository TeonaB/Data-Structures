#include <fstream>
#include <deque>
#include <string>

using namespace std;
ifstream f("deque.in");
ofstream g("deque.out");

const int MAXN = 5000005;
int a[MAXN];
int main() {
    int n, k;
    f >> n >> k;
    ///ne folosim de cerinta si folosim deque
    deque<int> dq;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        f >> a[i];
        ///daca primul element e inca in subsecventa anterioara il eliminam
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        ///atata timp cat ultimul element e mai mare decat primul il stergem pentru ca nu mai este nevoie de el
        while (!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }
        /// adaugam si indicele in deque
        dq.push_back(i);
        //// daca am depasit subsecventa adaugam primul element(minimul) la suma
        if (i >= k - 1) {
            sum += a[dq.front()];
        }
    }

    g << sum << endl;

    return 0;
}
