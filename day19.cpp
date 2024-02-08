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

string fun(string s)
{
    size_t found = s.find(':');
    return s.substr(found + 1, 10);
}
string parse(vector<string> ins, vector<int> v)
{
    map<char, int> idx;
    idx['x'] = 0;
    idx['m'] = 1;
    idx['a'] = 2;
    idx['s'] = 3;
    for (string s : ins)
    {
        if (s[0] == 'A')
            return "A";
        else if (s[0] == 'R')
            return "R";
        else if (!(s[1] == '>' ) && !(s[1]== '<'))
        {   
            return s;
        }
        else
        {
            int index = idx[s[0]];
            if (s[1] == '>')
            {
                int k = stoi(s.substr(2, 10));
                if (v[index] > k)
                {
                    return fun(s);
                }
            }
            else if (s[1] == '<')
            {
                int k = stoi(s.substr(2, 10));
                if (v[index] < k)
                {
                    return fun(s);
                }
            }
        }
    }
    return ins.back();
}
vector<string> proc(string s)
{
    vector<string> ins;
    string name;
    size_t found = s.find('{');
    name = s.substr(0, found);
    int start = found + 1, finish;
    for (int i = found + 1; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            finish = i;
            ins.push_back(s.substr(start, finish - start));
            start = i + 1;
        }
    }
    finish = s.length() - 1;
    ins.push_back(s.substr(start, finish - start));
    ins.push_back(name);
    return ins;
}
vector<int> process(string s)
{
    vector<int> tokens;
    int token;
    for (int i = 1; s[i] != '}'; i++)
    {
        char c = s[i];
        if (c == 'x' || c == 'm' || c == 'a' || c == 's')
        {
            token = stoi(s.substr(i + 2, 100));
            tokens.push_back(token);
        }
    }
    return tokens;
}
int main()
{
    string s;
    map<string, vector<string>> ins;
    vector<string> temp;
    vector<vector<int>> xmas;
    while (getline(cin, s))
    {
        if (s == "")
            break;
        else
        {
            temp = proc(s);
            string name = temp.back();
            temp.pop_back();
            ins[name] = temp;
        }
    }
    while (getline(cin, s))
    {
        if (s[0] == '#')
            break;
        xmas.push_back(process(s));
    }
    for (const auto &x : ins)
    {
        cout << x.first << endl;
        for (string s : x.second)
            cout << s << " ";
        cout << endl;
    }
    for (vector<int> v : xmas)
    {
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    double sum = 0;
    for (vector<int> v : xmas)
    {
        string next = parse(ins["in"], v);
        
        while (!(next == "A") && !(next == "R"))
        {   cout<<next<<" ";
            next = parse(ins[next], v);
        }
        cout << next<<endl;
        if (next == "A")
        {
            sum = sum + accumulate(all(v), 0);
        }
    }
    cout << sum;
}