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

int steps(string start, string s, map<string, pair<string, string>> m)
{
    string source = start;
    int counter = 0, step = 0;
    while (source[2] != 'Z')
    {
        if (s[counter] == 'L')
            source = m[source].first;
        else
            source = m[source].second;
        counter++;
        counter = counter % s.size();
        step++;
    }
    return step;
}
int main()
{
    string s;
    getline(cin, s);
    string blank;
    getline(cin, blank);
    map<string, pair<string, string>> m;
    vector<string> start;
    while (getline(cin, blank))
    {
        vector<string> temp;
        temp = process(blank);
        if (temp[0][2] == 'A')
            start.push_back(temp[0]);
        m[temp[0]] = {temp[2].substr(1, 3), temp[3].substr(0, 3)};
    }
    // for(auto x : m)
    //     cout << x.first << " " << x.second.first << " " << x.second.second << "\n";

    // int counter = 0;
    long long step = 0;
    // while (true)
    // {
    //     bool all = true;
    //     vector<string> dest;
    //     for (int i = 0; i < start.size(); i++)
    //     {
    //         if (s[counter] == 'L')
    //             dest.push_back(m[start[i]].first);
    //         else
    //             dest.push_back(m[start[i]].second);
    //     }
    //     counter++;
    //     counter = counter % s.size();
    //     step++;
    //     for(int i=0;i<dest.size();i++)
    //     {
    //         // cout << dest[i] << " ";
    //         if(dest[i][2] != 'Z')
    //             all = false;
    //     }
    //     start = dest;
    //     // cout << "\n";
    //     if(all)
    //         break;
    // }
    vector<int> time(start.size());
    for(int i=0;i<start.size();i++)
    {
        time[i] = steps(start[i],s,m);
        if(step == 0)
            step = time[i];
        step = lcm(step,time[i]);
        cout << time[i] << " ";
    }
    cout << "\n";
    cout << step;
}