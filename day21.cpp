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
set<vector<int>> point;
void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
vector<string> garden(pii start, int n, vector<string> grid)
{

    int row = start.first;
    int col = start.second;
    vector<int> star(3);
    star[0] = row;
    star[1] = col;
    star[2] = n;
        cout << row << " " << col << " " << n << endl;
    if (point.find(star) != point.end())
        return grid;
    else
        point.insert(star);
    if (n == 49)
    {
        if (grid[row - 1][col] == '.'||grid[row - 1][col] == 'S')
            grid[row - 1][col] = 'x';
        if (grid[row + 1][col] == '.'||grid[row + 1][col] == 'S')
            grid[row + 1][col] = 'x';
        if (grid[row][col + 1] == '.'||grid[row][col + 1] == 'S')
            grid[row][col + 1] = 'x';
        if (grid[row][col - 1] == '.'||grid[row][col - 1] == 'S')
            grid[row][col - 1] = 'x';
        // for (string s : grid)
        //     cout << s << endl;
        return grid;
    }
    else
    {
        // cout<<n<<endl;

        if (grid[row - 1][col] == '.' || grid[row - 1][col] == 'x')
            grid = garden(make_pair(row - 1, col), n + 1, grid);
        if (grid[row + 1][col] == '.' || grid[row + 1][col] == 'x')
            grid = garden(make_pair(row + 1, col), n + 1, grid);
        if (grid[row][col + 1] == '.' || grid[row][col + 1] == 'x')
            grid = garden(make_pair(row, col + 1), n + 1, grid);
        if (grid[row][col - 1] == '.' || grid[row][col - 1] == 'x')
            grid = garden(make_pair(row, col - 1), n + 1, grid);
        return grid;
    }
}
int main()
{
    pii start;
    vector<string> grid;
    string temp;
    getline(cin, temp);
    temp.push_back('o');
    temp.insert(temp.begin(), 'o');
    string space;
    for (int i = 0; i < temp.length(); i++)
        space.push_back('o');
    grid.push_back(space);
    grid.push_back(temp);
    while (getline(cin, temp))
    {
        if (temp[0] == '%')
            break;
        size_t found = temp.find('S');
        if (found != string::npos)
        {
            start.second = found+1;
            start.first = grid.size();
        }
        //temp[found]='.';
        temp.push_back('o');
        temp.insert(temp.begin(), 'o');
        grid.push_back(temp);
    }
    grid.push_back(space);
    // for (string s : grid)
    //     cout << s << endl;
    grid = garden(start, 0, grid);
    int k = 0;
    for (string s : grid)
    {
        cout << s << endl;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'x')
                k++;
        }
    }
    //cout<<grid.size()<<" "<<grid[0].length();
    cout << k;
}
