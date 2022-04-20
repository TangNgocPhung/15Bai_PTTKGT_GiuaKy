#include <conio.h>
#include <bits/stdc++.h>
using namespace std;
int n, R[51];
int Count;
bool col[10000], _plus[10000], _minus[10000];
int check(int x, int y) {
	int i;
	//kiem tra vi tri thich hop de dat quan hau k
	for (i = 1; i < x; i++)
	{
		if ((R[i] == y) || (i - R[i] == x - y) || (i - x == y - R[i]))
		{
			y = y + 1;
			i = 0;
		}
	}
	if (y > n)
		return 0;
	else
		return y;
}

void Print() {
	int i, f;
	for (i = 1; i <= n; i++) {
		for (f = 1; f <= n; f++)
		{
			if (f == R[i])
				printf("Q ");
			else
				printf("_ ");
		}
		printf("\n");
	}
}


void Try(int i) {
	for (int j = 1; j <= n; j++)
		if (!col[j] && !_plus[i + j - 1] && !_minus[i - j + n]) {
			col[j] = _plus[i + j - 1] = _minus[i - j + n] = 1;
			if (i < n) Try(i + 1);
			else Count++;
			col[j] = _plus[i + j - 1] = _minus[i - j + n] = 0;
		}
}

int main() {
	int i, f;
	int count = 0;
	cout << "Ban chon Testcase nao tu 1 den 10: ";
	string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open())
	{
		cin >> n;
		Try(1);
		cout << Count;
		printf("\n");
		for (i = 1; i <= n; i++)
			R[i] = 1;
		i = 1;
		while (1) {
			for (; i <= n; i++)
			{

				f = check(i, R[i]);
				if (f != 0)
					R[i] = f;
				else
				{
					R[i] = 1;
					R[i - 1] = R[i - 1] + 1;
					i = i - 2;
					count++;
				}

			}
			//print the solution
			Print();
			printf("\n[");
			for (i = 1; i < n; i++)
				printf("%d,", R[i]);
			printf("%d]", R[n]);
			_getch();
			//xoa ket qua truoc do
			system("CLS");
			//In ra cach dat hau khac
			printf("solution for size %d\n\n", n);
			//cout << "Loi giai cua kich thuoc ban co " << n;
			R[n] = R[n] + 1;
			i = n;
		}
	}
	else
	{
		cout << "Khong mo duoc File";
	}
}
