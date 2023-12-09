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
#include<unordered_set>
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
int process(string s){
   
   stringstream ss(s);
   vector<string> tokens;
   string token;
   while (ss >> token) {
    
       tokens.push_back(token);
   }
   unordered_set<int> n;
 for(int i=2;i<tokens.size();i++)
 {
    if(tokens[i][0]!='|')
 {
     n.insert(stoi(tokens[i]));
}
 }
 if(n.size()==(tokens.size()-3))
 return 0;
 else
 return tokens.size()-3-n.size();
}
int main()
{
  vector<int> v(220,1);
int f[220];
   int i = 0;
   string s;
   while(getline(cin,s)){
    if(s[0]=='#')
    break;
    f[i]=process(s);
    ++i;
   }
for(int i=0;i<220;i++)
{
    for(int j=i+1;j<=i+f[i];j++)
    {
        v[j]=v[j]+v[i];
    }
}

  
    cout<<accumulate(v.begin(),v.end(),0);
   return 0;   
}