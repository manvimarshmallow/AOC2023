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
#include <cmath>
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
int process(string s)
{
	stringstream ss(s);
	vector<string> tokens;
	string token;
	while (ss >> token)
	{
		tokens.push_back(token);
	}

	map<string, int> ref;
	ref["blue,"] = 0;
	ref["red,"] = 0;
	ref["green,"] = 0;
	ref["blue"] = 0;
	ref["red"] = 0;
	ref["green"] = 0;
	ref["blue;"] = 0;
	ref["red;"] = 0;
	ref["green;"] = 0;

	for (int i = 2; i < tokens.size(); i = i + 2)
	{
		ref[tokens[i + 1]] = max(stoi(tokens[i]), ref[tokens[i + 1]]);
	}
	int red = max(ref["red;"], ref["red,"]);
	red = max(red, ref["red"]);
	int blue = max(ref["blue;"], ref["blue,"]);
	blue = max(blue, ref["blue"]);
	int green = max(ref["green;"], ref["green,"]);
	green = max(green, ref["green"]);
	return red * blue * green;
}

int main()
{
	long long sum = 0;
	int i = 0;
	string s;
	while (getline(cin, s))
	{
		if (s[0] == '#')
			break;
		++i;
		int k = process(s);
		cout << k;
		sum += k;
	}

	cout << sum << "\n";
	return 0;
}
