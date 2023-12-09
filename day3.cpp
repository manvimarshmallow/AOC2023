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
int reverseDigits(int num) 
{ 
    int rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    return rev_num; 
} 
int c(char c)
{
    if(c=='.'||isdigit(c))
    return 1;
    else
    return 0;
}
    


int main()
{
    double sum=0;
    vector<string> s;
    string str;
    cin>>str;
    int e;
    while(cin>>str)
    {if(str[0]=='#')
    break;
        s.push_back(str);
    }
    for(int i=1;i<s.size();i++)
    {
    string mid=s[i];
    string top=s[i-1];
    string bot=s[i+1];
for(int j=0;j<mid.size()-1;j++)
{
    if(isdigit(mid[j]))
    {int f=1;
        e=stoi(mid.substr(j,3));
        if(j!=0){
            f=c(top[j-1])*c(mid[j-1])*c(bot[j-1]);
        }
        f=f*c(top[j])*c(bot[j]);
        if(e>99)
        {
            f=f*c(top[j+1])*c(bot[j+1])*c(top[j+2])*c(bot[j+2])*c(top[j+3])*c(bot[j+3])*c(top[j+4])*c(mid[j+4])*c(bot[j+4]);
            j=j+3;
        }
        else if(e>9)
        { 
            f=f*c(top[j+1])*c(bot[j+1])*c(top[j+2])*c(bot[j+2])*c(top[j+3])*c(bot[j+3])*c(mid[j+3]);
             j=j+2;
        }
        if(f==0)
            {
                sum=sum+e;
            }
    }
    }
}
cout<<sum;
    }


    
// {
    //    if(isdigit(mid[j+1])) 
    //    {sum=sum+stoi(mid.substr(j+1,3)); }
    //    if(isdigit(mid[j-1]))
    //    {int x= stoi(reverseStr(mid.substr(0,j)));
    //    sum=sum+reverseDigits(x);
    //    }
    //    if(isdigit(top[j-1]))
    //    {
    //     e=extract(top, j-1)
    //     sum=sum+e;
        
        
    //    } 
    //    else if(isdigit(top[j]));
    //    {
    //     sum=sum+extract(top,j);
    //    }
    //    else if(isdigit(top[j+1]))
