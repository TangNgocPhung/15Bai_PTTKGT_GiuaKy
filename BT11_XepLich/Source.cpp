#include <bits/stdc++.h>
using namespace std;

struct Job {
	int start, finish, profit;
};

bool jobComparator(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

int latestNonConflict(Job arr[], int i)
{
	for (int j = i - 1; j >= 0; j--) {
		if (arr[j].finish <= arr[i].start)
			return j;
	}
	return -1;
}

int findMaxProfit(Job arr[], int n)
{
	sort(arr, arr + n, jobComparator);
	int* table = new int[n];
	table[0] = arr[0].profit;
	for (int i = 1; i < n; i++) 
	{
		int inclProf = arr[i].profit;
		int l = latestNonConflict(arr, i);
		if (l != -1)
			inclProf += table[l];
		table[i] = max(inclProf, table[i - 1]);
	}
	int result = table[n - 1];
	delete[] table;
	return result;
}

int main()
{
	cout << "Ban chon Testcase nao tu 1 den 10: "; string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open())
	{
		int n; Job arr[100];
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
		}
		cout << "The optimal profit is " << findMaxProfit(arr, n);
	}
	else
	{
		cout << "Khong mo duoc File";
	}
	return 0;
}
