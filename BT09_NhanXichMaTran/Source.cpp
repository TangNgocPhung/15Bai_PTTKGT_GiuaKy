#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int MatrixChainOrder(int p[], int n)
{
	int m[MAX][MAX];

	int i, j, k, L, q;

	/* m[i, j] = Minimum number of scalar
	multiplications needed to compute the
	matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying
	// one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}

// Driver Code
int main()
{
	cout << "Ban chon testcase nao tu 1 den 10: "; string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open())
	{
		int size, arr[100];
		cin >> size;
		for (int i = 0; i < size; i++) cin >> arr[i];
		cout << "Minimum number of multiplications is "
			<< MatrixChainOrder(arr, size);
	}
	else
	{
		cout << "Khong mo duoc File";
	}
	return 0;
}
