#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void THN(ll n, ll num, char Src, char Dest, char Tmp);

// Tăng Ngọc Phụng - 46.01.103.055

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    //cout << "So dia cho truoc o cot A: ";
    cout << "Ban chon testcase nao tu 1 den 10: "; string s; cin >> s;
    string fn = "Testcase" + s + ".txt";
    ifstream cin(fn);
    if (cin.is_open()) {
        cin >> n;
        THN(n, n, 'A', 'C', 'B');
        return 0;
    }
    else
    {
        cout << "Khong mo duoc File";
    }
}

void THN(ll n, ll num, char Src, char Dest, char Tmp) {
    if (n == 1) {
        cout << "Dia can chuyen la: " << num << endl;
        cout << "Chuyen tu dia " << Src << " sang dia  " << Dest << endl << endl;
    }
    else
    {
        THN(n - 1, n - 1, Src, Tmp, Dest);
        THN(1, num, Src, Dest, Tmp);
        THN(n - 1, n - 1, Tmp, Dest, Src);
    }
}