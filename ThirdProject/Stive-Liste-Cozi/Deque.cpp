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

    deque<int> dq;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        f >> a[i];

        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            sum += a[dq.front()];
        }
    }

    g << sum << endl;

    return 0;
}
