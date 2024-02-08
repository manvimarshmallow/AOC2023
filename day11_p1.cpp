#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<long> vi;
typedef vector<long long> vll;
typedef pair<long, long> pii;
typedef vector<pii> vii;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
long fixum(vector<long> v)
{
    sort(all(v));
    long sum = 0;
    for (long i = 1; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] > 1)
        {
            long diff = (v[i] - v[i - 1] - 1) * (1000000 - 1);
            for (long j = i; j < v.size(); j++)
            {
                v[j] = v[j] + diff;
            }
        }
    }
    for (long i = 0; i < v.size(); i++)
    {
        for (long j = i + 1; j < v.size(); j++)
        {
            sum = v[j] - v[i] + sum;
        }
    }
    for (long i : v)
        cout << i << " ";
    cout << endl;
    return sum;
}
int main()
{
    string s;
    vector<long> rows;
    vector<long> cols;
    vector<string> v;
    long c = 0;
    while (cin >> s)
    {
        v.push_back(s);
        for (long i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                cols.push_back(i);
                rows.push_back(c);
            }
        }
        c++;
    }
    cout << fixum(rows) + fixum(cols);
    cout << endl;
}