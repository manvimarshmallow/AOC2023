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
pii numfinder(string s)
{  pii temp;
temp.second=s.length()-1;

temp.first=-1;

  size_t found1 = s.find("one");
  if (found1 != string::npos)
    {
        if(temp.second>found1)
        {
            temp.second=found1;
            temp.first=1;
        }
    }
  size_t found2 = s.find("two");
  if (found2 != string::npos)
    {
        if(temp.second>found2)
        {
            temp.second=found2;
            temp.first=2;
        }
    }
    size_t found3 = s.find("three");
  if (found3 != string::npos)
    {
        if(temp.second>found3)
        {
            temp.second=found3;
            temp.first=3;
        }
    }
  size_t found4 = s.find("four");
  if (found4 != string::npos)
    {
        if(temp.second>found4)
        {
            temp.second=found4;
            temp.first=4;
        }
    }
     size_t found5 = s.find("five");
  if (found5 != string::npos)
    {
        if(temp.second>found5)
        {
            temp.second=found5;
            temp.first=5;
        }
    }
    size_t found6 = s.find("six");
   if(found6 != string::npos)
    {
        if(temp.second>found6)
        {
            temp.second=found6;
            temp.first=6;
        }
    }
    size_t found7 = s.find("seven");
  if (found7 != string::npos)
    {
        if(temp.second>found7)
        {
            temp.second=found7;
            temp.first=7;
        }
    }
    size_t found8 = s.find("eight");
  if (found8 != string::npos)
    {
        if(temp.second>found8)
        {
            temp.second=found8;
            temp.first=8;
        }
    }
    size_t found9 = s.find("nine");
  if (found9 != string::npos)
    {
        if(temp.second>found9)
        {
            temp.second=found9;
            temp.first=9;
        }
    }
    
    
return temp;

}
pii numfinderev(string s)
{  pii temp;
temp.second=numfinder(s).second;

temp.first=numfinder(s).first;
size_t found1 = s.find("one");
  if (found1 != string::npos)
    {
        if(temp.second<found1)
        {
            temp.second=found1;
            temp.first=1;
        }
    }
  size_t found2 = s.find("two");
  if (found2 != string::npos)
    {
        if(temp.second<found2)
        {
            temp.second=found2;
            temp.first=2;
        }
    }
    size_t found3 = s.find("three");
  if (found3 != string::npos)
    {
        if(temp.second<found3)
        {
            temp.second=found3;
            temp.first=3;
        }
    }
  size_t found4 = s.find("four");
  if (found4 != string::npos)
    {
        if(temp.second<found4)
        {
            temp.second=found4;
            temp.first=4;
        }
    }
     size_t found5 = s.find("five");
  if (found5 != string::npos)
    {
        if(temp.second<found5)
        {
            temp.second=found5;
            temp.first=5;
        }
    }
    size_t found6 = s.find("six");
   if(found6 != string::npos)
    {
        if(temp.second<found6)
        {
            temp.second=found6;
            temp.first=6;
        }
    }
    size_t found7 = s.find("seven");
  if (found7 != string::npos)
    {
        if(temp.second<found7)
        {
            temp.second=found7;
            temp.first=7;
        }
    }
    size_t found8 = s.find("eight");
  if (found8 != string::npos)
    {
        if(temp.second<found8)
        {
            temp.second=found8;
            temp.first=8;
        }
    }
    size_t found9 = s.find("nine");
  if (found9 != string::npos)
    {
        if(temp.second<found9)
        {
            temp.second=found9;
            temp.first=9;
        }
    }
   found1 = s.find("one", found1+1);
  if (found1 != string::npos)
    {
        if(temp.second<found1)
        {
            temp.second=found1;
            temp.first=1;
        }
    }
   found2 = s.find("two", found2+1);
  if (found2 != string::npos)
    {
        if(temp.second<found2)
        {
            temp.second=found2;
            temp.first=2;
        }
    }
     found3 = s.find("three", found3+1);
  if (found3 != string::npos)
    {
        if(temp.second<found3)
        {
            temp.second=found3;
            temp.first=3;
        }
    }
  found4 = s.find("four", found4+1);
  if (found4 != string::npos)
    {
        if(temp.second<found4)
        {
            temp.second=found4;
            temp.first=4;
        }
    }
     found5 = s.find("five", found5+1);
  if (found5 != string::npos)
    {
        if(temp.second<found5)
        {
            temp.second=found5;
            temp.first=5;
        }
    }
    found6 = s.find("six", found6+1);
   if(found6 != string::npos)
    {
        if(temp.second<found6)
        {
            temp.second=found6;
            temp.first=6;
        }
    }
    found7 = s.find("seven", found7+1);
  if (found7 != string::npos)
    {
        if(temp.second<found7)
        {
            temp.second=found7;
            temp.first=7;
        }
    }
 found8 = s.find("eight", found8+1);
  if (found8 != string::npos)
    {
        if(temp.second<found8)
        {
            temp.second=found8;
            temp.first=8;
        }
    }
    found9 = s.find("nine", found9 + 1);
  if (found9 != string::npos)
    {
        if(temp.second<found9)
        {
            temp.second=found9;
            temp.first=9;
        }
    }
    
    
return temp;

}
int main()
{
    int n=-1;

    double s=0,m=-1;
    string str;
    while(cin>>str)
    {if(str[0]=='#')
    break;
    int i,j;
    for( i=0; i<str.length() ; i++)
{
    if(str[i]>='0' && str[i]<='9')
      {
         n = str[i];
         n = n - 48;
      }
    if(n!=-1)
    break;
}
pii firstnumber=numfinder(str);
pii lastnumber=numfinderev(str);

for( j= str.length()-1; j>i-1;j--)
{
    if(str[j]>='0' && str[j]<='9')
      {
         m= str[j];
         m= m- 48;
      }
    if(m !=-1)
    break;
}
if(i>firstnumber.second)
n=firstnumber.first;
if(j<lastnumber.second&& lastnumber.second!=str.length()-1)
m=lastnumber.first;
cout<<n<<m<<endl;
s=s+n*10+m;
n=-1;
m=-1;
}

    cout<<s;
}