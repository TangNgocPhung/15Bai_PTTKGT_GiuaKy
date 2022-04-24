#include <bits/stdc++.h>
using namespace std;
#define VOCUC 1000
#define MAX 100

int LuuVet[MAX];
int ChuaXet[MAX];
int DoDaiDuongDiToi[MAX];
bool flag = true;
struct Graph
{
	int sodinh;
	int a[MAX][MAX];
};

void ReadFile(string s, Graph& g)
{
	ifstream cin(s);
	if (cin.is_open())
	{
		cin >> g.sodinh;
		for (int i = 0; i < g.sodinh; i++)
		{
			for (int j = 0; j < g.sodinh; j++)
			{
				cin >> g.a[i][j];
				if (g.a[i][j] < 0)
				{
					flag = false;
				}
			}
		}
	}
	else cout << "Khong mo duoc File";
}
void PrintGraph(Graph& g)
{
	cout << "So dinh cua do thi: " << g.sodinh << endl;
	cout << "Ma tran ke cua do thi: \n";
	for (int i = 0; i < g.sodinh; i++)
	{
		for (int j = 0; j < g.sodinh; j++)
		{
			cout << g.a[i][j] << " ";
		}
		cout << endl;
	}
}

int TimDuongDiNhoNhat(Graph &g)
{
	int li = -1;
	float p = VOCUC;
	for (int i = 0; i < g.sodinh; i++)
	{
		if (ChuaXet[i] == 0 && DoDaiDuongDiToi[i] < p)
		{
			p = DoDaiDuongDiToi[i];
			li = i;
		}
	}
	return li;
}
void CapNhatDuongDi(int u, Graph& g)
{
	ChuaXet[u] = 1;
	for (int v = 0; v < g.sodinh; v++)
	{
		if (ChuaXet[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC)
		{
			if (DoDaiDuongDiToi[v] > DoDaiDuongDiToi[u] + g.a[u][v])
			{
				DoDaiDuongDiToi[v] = DoDaiDuongDiToi[u] + g.a[u][v];
				LuuVet[v] = u;
			}
		}
	}
}
void Dijkstra(int s, int f, Graph& g)
{
	int i;
	for (int i = 0; i < g.sodinh; i++)
	{
		ChuaXet[i] = 0;
		DoDaiDuongDiToi[i] = VOCUC;
		LuuVet[i] = -1;
	}
	DoDaiDuongDiToi[s] = 0;
	while (ChuaXet[f] == 0)
	{
		int u = TimDuongDiNhoNhat(g);
		if (u == -1)break;
		CapNhatDuongDi(u, g);
	}
	if (ChuaXet[f] == 1)
	{
		cout << "Duong di ngan nhat tu dinh " << s << " den dinh " << f << endl;
		i = f;
		cout << f;
		while (LuuVet[i] != s)
		{
			cout << "<---" << LuuVet[i];
			i = LuuVet[i];
		}
		cout << "<---" << LuuVet[i] << '\n';
		cout << "Voi do dai: " << DoDaiDuongDiToi[f];
	}
	else
	{
		cout << "Khong co duong di tu dinh " << s << " den dinh " << f;
	}
}
int main()
{
	cout << "Ban chon doc do thi testcase nao tu 1 den 10: "; string n; cin >> n;
	string fn = "Testcase" + n + ".txt";
	Graph g;
	ReadFile(fn, g);
	PrintGraph(g);
	if (flag == false)
	{
		cout << "Do thi co trong so am nen khong su dung duoc thuat toan Dijkstra \n";
		return 0;
	}
	else
	{
		int s, f;
		cout << "Chu y: Dinh bat dau tu 0 \n";
		cout << "Nhap dinh bat dau: "; cin >> s;
		cout << "Nhap dinh ket thuc: "; cin >> f;
		Dijkstra(s, f, g);
	}
}