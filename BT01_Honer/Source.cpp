#include <bits/stdc++.h>
using namespace std;

int horner(int poly[], int n, int x)
{
	int result = poly[0]; 
	for (int i = 1; i < n; i++)
		result = result * x + poly[i];

	return result;
}

int main()
{
	cout << "Ban chon Testcase nao tu 1 den 10: "; string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open())
	{
		int n, x, poly[100];
		cin >> n;
		for (int i = 0; i < n; i++) cin >> poly[i];
		cin >> x;
		cout << "Value of polynomial is " << horner(poly, n, x);
	}
	else
	{
		cout << "Khong mo duoc File";
	}
}
