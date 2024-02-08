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
vector<string> process(string s)
{
    stringstream ss(s);
    vector<string> tokens;
    string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}
int main()
{
    string s;
    vector<int> v;
    vector<string> colour;
    vector<char> move;
    while (getline(cin, s))
    {
        vector<string> dig = process(s);
        move.push_back(dig[0][0]);
        v.push_back(stoi(dig[1]));
        colour.push_back(dig[2]);
    }
    int wall = accumulate(all(v), 0);
    int depth = 0;
    map<int, int> m;
    m[0] = 0;
    int i = 0;
    for (char c : move)
    {
        switch (c)
        {
        case 'R':
        {
            m[depth] = v[i] + m[depth];
        }
        break;
        case 'L':
        {
            m[depth] = m[depth] - v[i];
        }
        break;
        case 'U':
        {
            depth = depth - v[i];
            if (m.find(depth) == m.end())
            {
                m[depth] = 0;
            }
        }
        break;
        case 'D':
        {
            depth = depth + v[i];
            if (m.find(depth) == m.end())
            {
                m[depth] = 0;
            }
        }
        break;
        }
        i++;
    }
    
    int prod=0;
    for(const auto& x:m)
    {    cout<<x.first<<" "<<x.second<<endl;
       if(x.second>0)
        prod=prod+(x.second-1)*(depth-x.first);
        else if(x.second<0)
        prod=prod+(x.second+1)*(depth-x.first);
    }   
    cout<<prod;
}