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
#include <time.h>
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
vector<string> cycle(vector<string> s)
{ // tilt north
    for (int i = 0; i < s[0].length(); i++)
    {
        int l = s.size();
        int dot = 0;

        for (string str : s)
        {
            if (str[i] == '#')
            {
                dot = 0;
            }
            else if (str[i] == '.')
            {
                dot++;
            }
            else if (str[i] == 'O')
            {
                s[s.size() - l][i] = '.';
                s[s.size() - l - dot][i] = 'O';
            }
            l--;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        int l = s[0].length();
        int dot = 0;

        for (char c : s[i])
        {
            if (c == '#')
            {
                dot = 0;
            }
            else if (c == '.')
            {
                dot++;
            }
            else if (c == 'O')
            {
                s[i][s.size() - l] = '.';
                s[i][s.size() - l - dot] = 'O';
            }
            l--;
        }
    }

    reverse(all(s));
    for (int i = 0; i < s[0].length(); i++)
    {
        int l = s.size();
        int dot = 0;

        for (string str : s)
        {
            if (str[i] == '#')
            {
                dot = 0;
            }
            else if (str[i] == '.')
            {
                dot++;
            }
            else if (str[i] == 'O')
            {
                s[s.size() - l][i] = '.';
                s[s.size() - l - dot][i] = 'O';
            }
            l--;
        }
    }
    reverse(all(s));

    for (int i = 0; i < s.size(); i++)
    {
        int l = s[0].length();
        int dot = 0;
        reverse(all(s[i]));
        for (char c : s[i])
        {
            if (c == '#')
            {
                dot = 0;
            }
            else if (c == '.')
            {
                dot++;
            }
            else if (c == 'O')
            {
                s[i][s.size() - l] = '.';
                s[i][s.size() - l - dot] = 'O';
            }
            l--;
        }
        reverse(all(s[i]));
    }

    return s;
}
int main()
{
    /* Time function returns the time since the
        Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;

    /* You can call it like this : start = time(NULL);
    in both the way start contain total time in seconds
    since the Epoch. */
    time(&start);

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    string str;
    vector<string> s;
    while (getline(cin, str))
    {
        if (str[0] == '!')
            break;
        s.push_back(str);
    }

    for (int i = 0; i < 1000; i++)
    {
        s = cycle(s);
        int sum = 0;
        for (int i = 0; i < s[0].length(); i++)
        {
            int l = s.size();

            int load = 0;
            for (string str : s)
            {

                if (str[i] == 'O')
                {
                    load = load + l;
                }
                l--;
            }
            // cout << load << endl;
            sum = sum + load;
        }
        
        cout <<i+1<<" "<<sum<<endl;
    }
    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    cout<<1000000000%93;
    // for (string str : s)
    //     cout << str << endl;
    // cout << endl;
}