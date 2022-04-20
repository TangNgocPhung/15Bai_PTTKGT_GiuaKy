#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define ll long long int
#define MAX 10000
#define endl '\n'
// Tăng Ngọc Phụng - 46.01.103.055

void QuickSort(ll a[], ll left, ll right, bool flag)
{
	if (left >= right) return;
	ll pivot = a[(left + right) / 2];
	ll i = left, j = right;
	if (flag == true)
	{
		do
		{
			while (a[i] < pivot) i++;
			while (a[j] > pivot)j--;
			if (i <= j)
			{
				ll tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++;
				j--;
			}
		} while (i < j);
		QuickSort(a, left, j, true);
		QuickSort(a, i, right, true);
	}
	else
	{
		do
		{
			while (a[i] > pivot) i++;
			while (a[j] < pivot)j--;
			if (i <= j)
			{
				ll tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++;
				j--;
			}
		} while (i < j);
		QuickSort(a, left, j, false);
		QuickSort(a, i, right, false);
	}
}
int main()
{
	ll n;
	cout << "Ban chon testcase nao tu 1 den 10: ";
	//cout << "Nhap so luong phan tu cua mang:   ";
	string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open()) {
		cin >> n;
		ll a[MAX];
		//cout << "Nhap gia tri phan tu cua mang:    ";
		for (ll i = 0; i < n; i++) cin >> a[i];
		QuickSort(a, 0, n - 1, true);
		cout << "Mang sau khi da sap xep tang dan:  ";
		for (ll i = 0; i < n; i++) cout << a[i] << "   ";
		cout << endl << endl;
		QuickSort(a, 0, n - 1, false);
		cout << "Mang sau khi da sap xep giam dan:  ";
		for (ll i = 0; i < n; i++) cout << a[i] << "   ";
	}
	else
	{
		cout << "Khong mo duoc File";
	}
}