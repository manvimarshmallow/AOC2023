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
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main()
{
    string str;
    vector<string> s;
    while (getline(cin, str))
    {
        if (str[0] == '!')
            break;
        s.push_back(str);
    }
    int sum = 0;
    for (int i = 0; i < s[0].length(); i++)
    {
        int l = s.size();
        int dot = 0;
        int load = 0;
        for (string str : s)
        {
            if (str[i] == '#')
            {
                dot = 0;
            }
            else if (str[i] == '.')
            {
                dot++;
            }
            else if (str[i] == 'O')
            {
                load = load + l + dot;
            }
                l--;
        }
            cout << load << endl;
        sum = sum + load;
    }
    cout << sum;
}