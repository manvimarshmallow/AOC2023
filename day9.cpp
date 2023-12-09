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
template <typename T>
bool all_equal(const vector<T> &vecObj)
{
    return all_of(vecObj.begin(),
                  vecObj.end(),
                  [&](const T &value)
                  {
                      return value == *(vecObj.begin());
                  });
}
vector<int> process(string s)
{
    stringstream ss(s);
    vector<int> tokens;
    string token;
    while (ss >> token)
    {
        tokens.push_back(stoi(token));
    }
    return tokens;
}
int prediction(vector<int> v)
{
    if (all_equal(v))
    {
        return v[0];
    }
    else
    {
        vector<int> temp;
        for (int i = 1; i < v.size(); i++)
        {
            temp.push_back(v[i]-v[i-1]);
        }
        return (v.back()+prediction(temp));
    }
}
int main()
{
    string s;
    long sum1 = 0;
    long sum2= 0;

    while (getline(cin, s))
    {
        vector<int> temp = process(s);
        sum1 = sum1 + prediction(temp);
        reverse(all(temp));
        sum2=sum2+prediction(temp);
    }
    cout << sum1<<endl;
    cout<< sum2;
}