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
bool compare(string s, string t)
{
    map<char, int> p;
    p['2'] = 2;
    p['3'] = 3;
    p['4'] = 4;
    p['5'] = 5;
    p['6'] = 6;
    p['7'] = 7;
    p['8'] = 8;
    p['9'] = 9;
    p['T'] = 10;
    p['J'] = 1;
    p['Q'] = 12;
    p['K'] = 13;
    p['A'] = 14;
    for (int i = 0; i < 5; i++)
    {
        if (p[s[i]] > p[t[i]])
        {
            // cout << i << " " <<   p[s[i]] << " " << p[t[i]] << " " << s << " " << t << "\n";
            return true;
        }
        if (p[s[i]] < p[t[i]])
        {
            return false;
        }
    }
    return false;
}

int main()
{

    int k;
    string str;
    map<string, int> bid;
    vector<string> five;
    vector<string> four, three, one, two, high, fullhouse;
    int c = 0;

    while (cin >> str >> k)
    {
        c++;
        if (str[0] == '#')
            break;
        bid[str] = k;
        map<char, int> m;
        for (int i = 0; i < 5; i++)

            m[str[i]]++;

        if (m.find('J') != m.end())
        {
            if (m.size() == 1 || m.size() == 2)
            {
                five.push_back(str);
            }
            else if (m.size() == 3)
            {
                if (m['J'] == 1)
                {
                    bool found = false;
                    for (auto x : m)
                    {
                        if (x.second == 3)
                        {
                            found = true;
                            four.push_back(str);
                        }
                    }
                    if (!found)
                        fullhouse.push_back(str);
                }
                else
                    four.push_back(str);
            }
            else if (m.size() == 4)
                three.push_back(str);
            else
                one.push_back(str);
        }
        else
        {
            if (m.size() == 1)
            {
                five.push_back(str);
            }
            else if (m.size() == 2)
            {
                for (auto x : m)
                    if (x.second == 4)
                        four.push_back(str);
                    else if (x.second == 3)
                        fullhouse.push_back(str);
            }
            else if (m.size() == 3)
            {
                bool found = false;
                for (auto x : m)
                    if (x.second == 3)
                    {
                        found = true;
                        three.push_back(str);
                    }
                if (!found)
                    two.push_back(str);
            }
            else if (m.size() == 4)
            {
                // cout << m.size() << "HERE BITCH\n";
                // cout << "HIHIHI\n";
                one.push_back(str);
            }
            else if (m.size() == 5)
                high.push_back(str);
        }
    }

    // cout<<c<<endl;
    // cout<<five.size()<<endl;
    // cout<<four.size()<<endl;
    // cout<<three.size()<<endl;
    // cout<<high.size()<<endl;
    // cout<<two.size()<<endl;
    // cout<<one.size()<<endl;
    // cout <<fullhouse.size() << endl;

    sort(all(four), compare);
    sort(all(three), compare);
    sort(all(two), compare);
    sort(all(one), compare);
    sort(all(high), compare);
    sort(all(five), compare);
    sort(all(fullhouse), compare);
    // for(string s: four)
    // cout<<s<<"  ";
    // cout << endl;
    long ans = 0;
    int rank = bid.size();
    for (string s : five)
    {
        // cout << s << "->";
        ans = ans + bid[s] * rank;
        rank--;
    }
    cout << "\n";
    for (string s : four)
    {
        // cout << s << "->";
        ans = ans + bid[s] * rank;
        rank--;
    }
    // cout << "\n";
    for (string s : fullhouse)
    {
        // cout << s << "->";
        ans = ans + bid[s] * rank;
        rank--;
    }
    // cout << "\n";
    for (string s : three)
    {
        // cout << s << "->";
        ans = ans + bid[s] * rank;
        rank--;
    }
    // cout << "\n";
    for (string s : two)
    {
        // cout << s << "----->";
        ans = ans + bid[s] * rank;
        rank--;
    }
    // cout << "\n";
    for (string s : one)
    {
        // cout << s << "----1->";
        ans = ans + bid[s] * rank;
        rank--;
    }
    // cout << "\n";
    for (string s : high)
    {
        // cout << s << "->";
        ans = ans + bid[s] * rank;
        rank--;
    }
    // cout << "\n";
    cout << ans;
}