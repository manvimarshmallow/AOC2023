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
{string s;
        vector <string> row;
        int mirror=0;
        long sum=0;
 while(getline(cin,s))   
 {
    if(s=="")
    {
    if(mirror==0)
    {
     for(int i=0;i<row[0].length()-1;i++)
     {  string temp;
        for(int j=0;j<row.size();j++)
        {
          temp[j]=row[j][i];
        }
        cout<<temp;
     }
    }
    sum=sum+mirror*100;
       
        row.clear();
    }
    if(row.back()==s)
    {mirror=row.size();}
    row.push_back(s); 
 }
}