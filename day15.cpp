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
    int first=0;
    int sum=0;
    int i;
    for( i=0;i<s.length();i++)
    {
        if(s[i]==',')
        {
            string temp=s.substr(first,i-first);
            int h=hashf(temp);
            sum=sum+h;
            cout<<temp<<" "<<h<<endl;;
            first=i+1;
        }

    }
    sum=sum+hashf(s.substr(first,100));
    cout<<sum;
}