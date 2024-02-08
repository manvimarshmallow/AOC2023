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
set<pii> s;
set<pii> r, l, d, n;

vector<string> down(vector<string> grid, int row, int col);
vector<string> left(vector<string> grid, int row, int col);
vector<string> north(vector<string> grid, int row, int col);
vector<string> right(vector<string> grid, int row, int col)
{
    for (int i = col; grid[row][i] != 'o'; i++)
    {
        if (grid[row][i] == '.')
        {
            grid[row][i] = '#';
            s.insert(make_pair(row, i));
        }
        else if (grid[row][i] == '\\')
        {
            s.insert(make_pair(row, i));
            if (r.find(make_pair(row, i)) != r.end())
                return grid;
            else
            {
                r.insert(make_pair(row, i));
                return (down(grid, row + 1, i));
            }
        }
        else if (grid[row][i] == '/')
        {
            s.insert(make_pair(row, i));
            if (r.find(make_pair(row, i)) != r.end())
                return grid;
            else
            {
                r.insert(make_pair(row, i));
                return (north(grid, row - 1, i));
            }
        }
        else if (grid[row][i] == '|')
        {
            s.insert(make_pair(row, i));
            grid = north(grid, row - 1, i);
            return down(grid, row + 1, i);
        }
        else if (grid[row][i] == '-')
            s.insert(make_pair(row, i));
    }
    return grid;
}
vector<string> left(vector<string> grid, int row, int col)
{
    for (int i = col; grid[row][i] != 'o'; i--)
    {
        if (grid[row][i] == '.')
        {
            grid[row][i] = '#';
            s.insert(make_pair(row, i));
        }
        else if (grid[row][i] == '\\')
        {
            s.insert(make_pair(row, i));
            if (l.find(make_pair(row, i)) != l.end())
                return grid;
            else
            {
                l.insert(make_pair(row, i));
                return (north(grid, row - 1, i));
            }
        }
        else if (grid[row][i] == '/')
        {
            s.insert(make_pair(row, i));
            if (l.find(make_pair(row, i)) != l.end())
                return grid;
            else
            {
                l.insert(make_pair(row, i));
                return (down(grid, row + 1, i));
            }
        }
        else if (grid[row][i] == '|')
        {
            s.insert(make_pair(row, i));
            grid = north(grid, row - 1, i);
            return down(grid, row + 1, i);
        }
        else if (grid[row][i] == '-')
            s.insert(make_pair(row, i));
    }
    return grid;
}
vector<string> north(vector<string> grid, int row, int col)
{
    for (int i = row; grid[i][col] != 'o'; i--)
    {
        if (grid[i][col] == '.')
        {
            grid[i][col] = '#';
            s.insert(make_pair(i, col));
        }
        else if (grid[i][col] == '\\')
        {
            s.insert(make_pair(i, col));
            if (n.find(make_pair(i, col)) != n.end())
                return grid;
            else
            {
                n.insert(make_pair(i, col));
                return (left(grid, i, col - 1));
            }
        }
        else if (grid[i][col] == '/')
        {
            s.insert(make_pair(i, col));
            if (n.find(make_pair(i, col)) != n.end())
                return grid;
            else
            {
                n.insert(make_pair(i, col));
                return (right(grid, i, col + 1));
            }
        }
        else if (grid[i][col] == '-')
        {
            s.insert(make_pair(i, col));
            grid = right(grid, i, col + 1);
            return left(grid, i, col - 1);
        }
        else if (grid[i][col] == '|')
            s.insert(make_pair(i, col));
    }
    return grid;
}

vector<string> down(vector<string> grid, int row, int col)
{
    for (int i = row; grid[i][col] != 'o'; i++)
    {
        if (grid[i][col] == '.')
        {
            grid[i][col] = '#';
            s.insert(make_pair(i, col));
        }
        else if (grid[i][col] == '\\')
        {
            s.insert(make_pair(i, col));
            if (d.find(make_pair(i, col)) != d.end())
                return grid;
            else
            {
                d.insert(make_pair(i, col));
                return (right(grid, i, col + 1));
            }
        }
        else if (grid[i][col] == '/')
        {
            s.insert(make_pair(i, col));
            if (d.find(make_pair(i, col)) != d.end())
                return grid;
            else
            {
                d.insert(make_pair(i, col));
                return (left(grid, i, col - 1));
            }
        }
        else if (grid[i][col] == '-')
        {
            s.insert(make_pair(i, col));
            grid = right(grid, i, col + 1);
            return left(grid, i, col - 1);
        }
        else if (grid[i][col] == '|')
            s.insert(make_pair(i, col));
    }

    return grid;
}
int main()
{
    vector<string> grid,g,tempod;
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
        if (temp[0] == '#')
            break;
        temp.push_back('o');
        temp.insert(temp.begin(), 'o');
        grid.push_back(temp);
    }
    grid.push_back(space);
    g=grid;
    //part1
    grid = right(grid, 1, 1);
    // for (string s : grid)
    //     cout << s << endl;
    cout <<s.size();
    //part2
    //top row
    int m=0;
    for(int i=1;i<grid[0].length()-1;i++)
    {   
        tempod=g;
        s.clear();
        r.clear();
        l.clear();
        n.clear();
        d.clear();
        tempod=down(tempod,1,i);
        cout<<s.size()<<endl;
        m=max(m,(int)s.size());
        tempod=g;
        s.clear();
        r.clear();
        l.clear();
        n.clear();
        d.clear();
        tempod=north(tempod,grid.size()-2,i);
        cout<<s.size()<<endl;
        m=max(m,(int)s.size());
    }
    for(int i=1;i<grid.size()-1;i++)
    {   
        tempod=g;
        s.clear();
        r.clear();
        l.clear();
        n.clear();
        d.clear();
        tempod=right(tempod,i,1);
        cout<<s.size()<<endl;
        m=max(m,(int)s.size());
        tempod=g;
        s.clear();
        r.clear();
        l.clear();
        n.clear();
        d.clear();
        tempod=left(tempod,i,grid[0].length()-2);
        cout<<s.size()<<endl;
        m=max(m,(int)s.size());
    }
    cout<<m;

}