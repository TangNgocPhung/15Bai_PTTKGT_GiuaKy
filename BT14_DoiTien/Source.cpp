#include <bits/stdc++.h>
#define INF 9999999
using namespace std;

int a[110], f[1000010], n, x;

int main() {
	cout << "Ban chon Testcase nao tu 1 den 10 "; string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open()) 
	{
		cin >> n >> x;
		for (int i = 1; i <= n; i++) cin >> a[i];

		for (int i = 1; i <= x; i++) {
			f[i] = INF;
			for (int j = 1; j <= n; j++)
				if (i >= a[j]) f[i] = min(f[i], f[i - a[j]] + 1);
		}

		if (f[x] == INF) cout << "Khong co cach chia nao het";
		else cout << f[x];
	}
	else
	{
		cout << "Khong mo duoc File";
	}
	return 0;
}
