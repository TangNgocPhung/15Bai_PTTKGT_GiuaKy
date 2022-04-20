#include <bits/stdc++.h>
using namespace std;

int n, w, a[100], c[100], f[100][100], kq[100];

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
			cin >> a[i] >> c[i];
		}
	}
	else
	{
		cout << "Khong mo duoc File";
	}
}

void TaoBang()
{
	int i = 1;
	for (int i = 0; i <= n; i++)
	{
		f[i][0] = 0;
	}
	// giải quyêt các bài toán con đơn giản
	for (int j = 1; j <= w; j++)
	{
		f[0][j] = 0;
	}
	// giải quyết các bài toán tổng quát
	for (i = 1; i <= n; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (a[i] <= j)
			{
				f[i][j] = max(f[i - 1][j - a[i]] + c[i], f[i - 1][j]);
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
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