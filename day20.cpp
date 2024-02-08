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
        if (token.back() == ',')
            token.pop_back();
        tokens.push_back(token);
    }
    return tokens;
}
int main()
{
    string s;
    int pulse = -1;
    int swich = 0;
    map<string, pii> memory;
    vector <vector<string> > input;
    while (getline(cin, s))
    {   
        vector<string> temp = process(s);
        input.push_back(temp);
        if (temp[0] == "broadcaster")
        {
            pulse = 0;
        }
        else if (temp[0][0] == '&')
        {
            if (memory.find(temp[0].substr(1, 100)) != memory.end())
            {
                if (memory[temp[0].substr(1, 100)].first == 0)
                {
                    if (memory[temp[0].substr(1, 100)].second == 0)
                    {
                        pulse = 1;
                        memory[temp[0].substr(1, 100)].second = 1;
                    }
                    else
                    {
                        pulse = 0;
                        memory[temp[0].substr(1, 100)].second = 0;
                    }
                }
                else if (memory[temp[0].substr(1, 100)].first == 1)
                {
                    pulse = 1;
                }
            }
        }
        else if (temp[0][0] == '%')
        {
            if (memory.find(temp[0].substr(1, 100)) != memory.end())
            {
                if (memory[temp[0].substr(1, 100)].first == 0)
                {
                    pulse = 1;
                }
                else if(memory[temp[0].substr(1, 100)].first == 1)
                  pulse = 0;
            }   
        }
        for (int i = 2; i < temp.size(); i++)
        {
                if(memory.find(temp[i])==memory.end())
                   memory[temp[i]].second = swich;
                memory[temp[i]].first = pulse;
                cout<<pulse<<" ";
        }
    }
}