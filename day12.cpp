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
vector<int> processnum(string s)
{
    vector<int> num;
    num.push_back(stoi(s));
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ',')
            num.push_back(stoi(s.substr(i + 1, s.length())));
    }
    return num;
}
int ways(string s, vector<int> n)
{

    if (n.size() == 0)
    {
        cout << "+" << endl;
        return 1;
    }
    else if (s.length() - n.size() + 1 < accumulate(all(n), 0))
        return 0;
    else if (n.size() == 1)
    {
        int way = 0;
        int c = 0;
        int hash = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '?' || s[i] == '#')
            {
                if (s[i] == '#')
                    hash++;
                c++;
                if (c == n[0])
                {
                    way = way + 1;
                    c = 0;
                    i = i - n[0] + 1;
                }
            }
            else
            {
                c = 0;
            }
        }
        //cout << "hi" << s<<" "<<way<<endl;
        if (way == 0)
            return way;
        else if(hash>n[0])
            return 0;
        else if (hash==n[0])
            return 1;
        else
            return way;
    }
    else
    {
        int way = 0;
        int c = 0;
        int hash = -1;
        int nhash=0;
        for (int i = 0; i < s.length();)
        {
            if (s[i] == '?' || s[i] == '#')
            {
                ++c;
                if(s[i]=='#')
                {hash=i;
                nhash++;
                }
                if (c == n[0])
                {
                    //cout << c << " yo" << endl;
                    if (i + 1 < s.length())
                    {
                        if (s[i + 1] == '#')
                        {
                            c = 0;
                            i = i - n[0] + 1;
                        }
                        else
                        {
                            vector<int> v = n;
                            v.erase(v.begin());
                            //std::cout << s.substr(i + 2, 1000) <<" lol"<< endl;
                            if(hash==-1)
                            {way = way + ways(s.substr(i + 2, 1000), v);
                            i = i - n[0] + 1;}
                           else if(i<=hash-nhash+n[0])
                           {
                             way = way + ways(s.substr(i+2, 1000), v);
                           }
                            c = 0;
                        }
                    }
                }
                else if (c == 1 && s[i - 1] == '#')
                {
                    c = 0;
                }

                i++;
            }
            else
            {
                c = 0;
                i++;
            }
        }
        return way;
    }
}

int main()
{
    int sum = 0;
    string s;
    while (getline(cin, s))
    {
        vector<string> temp = process(s);
        int x = ways(temp[0], processnum(temp[1]));
        //cout << x << endl;
        sum = sum + x;
    }
    cout << sum;
}