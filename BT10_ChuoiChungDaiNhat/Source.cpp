#include <bits/stdc++.h>
using namespace std;
int m, n;
char a[12309];
char b[12309];
int F[2309][2309];
bool FF[2309][2309];

int f(int m, int n) {
	if (m == 0 || n == 0) return 0;
	if (FF[m][n]) return F[m][n];

	int r;
	if (a[m] == b[n])
		r = f(m - 1, n - 1) + 1;
	else
		r = max(f(m - 1, n), f(m, n - 1));
	FF[m][n] = true;
	F[m][n] = r;
	return r;
}

int main() {
	cout << "Ban chon testcase nao tu 1 den 10: "; string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open())
	{
		cin >> a >> b;
		m = strlen(a);
		n = strlen(b);
		printf("%d\n", f(m, n));
	}
	else cout << "Khong mo duoc File";
}