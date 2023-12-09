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
//mapper
long destination(long source, vector<pair<long,long> > v)
{
    for(int i=0;i<v.size();i=i+2)
    {
        if(v[i].first<=source && v[i+1].first>=source)
        {
           return v[i].second+source- v[i].first;    
        }

    }
    return source;
}


vector<pair<long,long> > mend(vector<pair<long,long> > v)
{
if(v[0].first!=0)
{v.insert(v.begin(),make_pair(0,0));
long temp=v[1].first;
v.insert(v.begin()+1,make_pair(temp-1,temp-1));
}
for(int i=1;i<v.size()-1;)
{  
if(v[i].first-v[i+1].first!=-1 && (v[i].second-v[i].first)==(v[i-1].second-v[i-1].first))
{long t1=v[i].first;
long t2=v[i+1].first;
    v.insert(v.begin()+i+1,make_pair(t1+1,t1+1));
     v.insert(v.begin()+i+2,make_pair(t2-1,t2-1));
    i=i+2;
}
else if(v[i+1].first-v[i].first==1)
{
    i=i+2;
}
}
return v;
}



void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
vector<string> process(string s){
   
   stringstream ss(s);
   vector<string> tokens;
   string token;
   while (ss >> token) {
    
       tokens.push_back(token);
   }
   return tokens;
}


int main()
{
  vector <vector<string> > v;
   
   string s;
   while(getline(cin,s)){
    if(s[0]=='#')
    break;
    v.push_back(process(s));
   }
   int l=1;
  
vector<long> seed(v[0].size()-1);
for(int i=0;i<v[0].size()-1;i++)
{
    seed[i]=stol(v[0][i+1]);   
}
l++;
int i;

vector <pair <long,long> > soil;
    if(v[l][0]=="seed-to-soil")
    {l++;
    
    for( i=l;v[i].begin()!=v[i].end();i++)
    {
       soil.push_back(make_pair(stol(v[i][1]),stol(v[i][0])));
       soil.push_back(make_pair(stol(v[i][1])+stol(v[i][2])-1,stol(v[i][0])-1+stol(v[i][2])));
    }
    l=i+1;}
sort(soil.begin(), soil.end());
soil=mend(soil);

vector <pair <long,long> > fert;
    if(v[l][0]=="soil-to-fertilizer")
    {
    l++;
    for(i=l;v[i].begin()!=v[i].end();i++)
    {
       fert.push_back(make_pair(stol(v[i][1]),stol(v[i][0])));
       fert.push_back(make_pair(stol(v[i][1])+stol(v[i][2])-1,stol(v[i][0])-1+stol(v[i][2])));
    }
    l=i+1;}
sort(fert.begin(), fert.end());
fert=mend(fert);

vector <pair <long,long> > water;
    if(v[l][0]=="fertilizer-to-water")
    {l++;
    for(i=l;v[i].begin()!=v[i].end();i++)
    {
       water.push_back(make_pair(stol(v[i][1]),stol(v[i][0])));
       water.push_back(make_pair(stol(v[i][1])+stol(v[i][2])-1,stol(v[i][0])-1+stol(v[i][2])));
    }
    l=i+1;}
sort(water.begin(), water.end());
water=mend(water);
vector <pair <long,long> > light;
    if(v[l][0]=="water-to-light")
    {l++;
    for(i=l;v[i].begin()!=v[i].end();i++)
    {
       light.push_back(make_pair(stol(v[i][1]),stol(v[i][0])));
       light.push_back(make_pair(stol(v[i][1])+stol(v[i][2])-1,stol(v[i][0])-1+stol(v[i][2])));
    }
    l=i+1;}
sort(light.begin(), light.end());
light=mend(light);
vector <pair <long,long> > temp;
    if(v[l][0]=="light-to-temperature")
    {l++;
    for(i=l;v[i].begin()!=v[i].end();i++)
    {
       temp.push_back(make_pair(stol(v[i][1]),stol(v[i][0])));
       temp.push_back(make_pair(stol(v[i][1])+stol(v[i][2])-1,stol(v[i][0])-1+stol(v[i][2])));
    }
    l=i+1;
    }
sort(temp.begin(), temp.end());
temp=mend(temp);
vector <pair <long,long> > hum;
    if(v[l][0]=="temperature-to-humidity")
    {l++;
    for(i=l;v[i].begin()!=v[i].end();i++)
    {
       hum.push_back(make_pair(stol(v[i][1]),stol(v[i][0])));
       hum.push_back(make_pair(stol(v[i][1])+stol(v[i][2])-1,stol(v[i][0])-1+stol(v[i][2])));
    }
    l=i+1;}
sort(hum.begin(), hum.end());
hum=mend(hum);
vector <pair <long,long> > loc;
    if(v[l][0]=="humidity-to-location")
    {l++;
    for(i=l;v[i].begin()!=v[i].end();i++)
    {
       loc.push_back(make_pair(stol(v[i][1]),stol(v[i][0])));
       loc.push_back(make_pair(stol(v[i][1])+stol(v[i][2])-1,stol(v[i][0])-1+stol(v[i][2])));
    }
    l=i+1;
}
sort(loc.begin(), loc.end());
hum=mend(hum);
// //now mapping:(
 map <long,long> m;
long mini;
 mini=destination(destination(destination(destination(destination(destination(destination(seed[0],soil),fert),water),light),temp),hum),loc);
//cout<<mini;
for( i=1;i<seed.size();i++)
{

long tempo=destination(destination(destination(destination(destination(destination(destination(seed[i],soil),fert),water),light),temp),hum),loc);
mini=min(tempo,mini);
    
}
cout<<mini;
return 0;  
}