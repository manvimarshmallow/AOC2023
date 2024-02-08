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
int hashf(string s)
{
    int val = 0;
    for (char c : s)
    {
        val = val + c;
        val = (val * 17) % 256;
    }
    return val;
}
int main()
{
    string s;
    cin >> s;
    int first = -1;
    int i;
    map<string, int> label;
    map<int, vector<pair<string, int>>> box;

    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == '=' || s[i] == '-')
        {
            string temp = s.substr(first + 1, i - first - 1);
            label[temp] = hashf(temp);
            cout << temp << " " << endl;
            if (s[i] == '=')
            {
                box[label[temp]].push_back(make_pair(temp, s[i + 1] - 48));
                first = i + 2;
            }
            else
            {
                first = i + 1;
                if (box.find(label[temp]) != box.end())
                {
                    vector<pair<string, int>> v = box[label[temp]];
                    for (int i = 0; i < v.size();)
                    {
                        if (v[i].first == temp)
                            v.erase(v.begin() + i);
                        else
                            i++;
                    }
                    if (v.begin() == v.end())
                        box.erase(label[temp]);
                    else
                        box[label[temp]] = v;
                }
            }
        }
    }
    int sum = 0;
    for (const auto &elem : box)
    {
        cout << elem.first << endl;
        int k = elem.first;
        int boxum=0;
        vector<pair<string, int>> v = box[k];
        for (int i = 0; i < v.size(); i++)
        {
            string temp=v[i].first;
            int len=v[i].second;
            for(int j=i+1;j<v.size();)
            {
                if(v[j].first==v[i].first)
                {
                    len=v[j].second;
                    v.erase(v.begin()+j);
                }
                else
                j++;
            }
            cout<<len<<" ";
            boxum=boxum+(i+1)*len;
        }
        cout<<endl;
        cout<<boxum<<endl;
        sum=sum+(k+1)*boxum;
    }
    cout<<sum;
}