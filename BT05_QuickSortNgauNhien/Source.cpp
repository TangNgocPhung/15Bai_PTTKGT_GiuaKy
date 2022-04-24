#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot) 
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int partition_r(int arr[], int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition_r(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int main()
{
	cout << "Ban chon Testcase nao tu 1 den 10: "; string s; cin >> s;
	string fn = "Testcase" + s + ".txt";
	ifstream cin(fn);
	if (cin.is_open())
	{
		int n, arr[100];
		cin >> n;
		for (int  i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		quickSort(arr, 0, n - 1);
		printf("Mang sau khi da sap xep tang dan: \n");
		printArray(arr, n);
	}
	return 0;
}
