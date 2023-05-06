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

    vector<int> ages(n);
    for (int i = 0; i < n; i++)
        f >> ages[i];

    deque<int> a,b;

    int max_diff = 0;

    for (int i = 0; i < n; i++)
    {
        if (a.front() < i - k)
            a.pop_front();
        while (!a.empty() && ages[a.back()] < ages[i])
            a.pop_back();
        a.push_back(i);
        if (b.front() < i - k)
            b.pop_front();
        while (!b.empty() && ages[b.back()] > ages[i])
            b.pop_back();
        b.push_back(i);
        max_diff = max(max_diff, ages[a.front()] - ages[b.front()]);
    }
    g<< max_diff << endl;

    return 0;
}
