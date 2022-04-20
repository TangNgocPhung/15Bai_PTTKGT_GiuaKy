#include <bits/stdc++.h>
using namespace std;

int n, w, a[100], f[100][100], kq[100];

void Input()
{
	cout << "Ban chon Testcase nao tu 1 den 10: "; string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open())
	{
		cin >> n >> w;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
	}
	else
	{
		cout << "Khong mo duoc File";
	}
}
void TaoBang()
{
	int k = 1;
	for (int v = 1; v <= w; v++)
	{
		if (a[k] <= v) f[k][v] = a[k];
		else f[k][v] = 0;
	}
	for (int k = 2; k <= n; k++)
	{
		for (int v = 1; v <= w; v++)
		{
			if (a[k] <= v) f[k][v] = max(f[k - 1][v - a[k]] + a[k], f[k - 1][v]);
			else f[k][v] = f[k - 1][v];
		}
	}
}
void TraBang()
{
	int k = n;
	int v = w;
	for (int i = k; i >= 1; --i)
	{
		if (f[i][v] != f[i - 1][v])
		{
			kq[i] = 1;
			v = v - a[i];
		}
	}
}
void Output()
{
	cout << "Bang phuong an cua quy hoach dong \n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Tong gia tri lon nhat la " << f[n][w] << endl;
	cout << "Ba lo gom: ";
	for (int i = 1; i <= n; i++)
	{
		if (kq[i] == 1)
		{
			cout << "goi hang "  << i << "   ";
		}
	}
}
int main()
{
	Input();
	TaoBang();
	TraBang();
	Output();
}