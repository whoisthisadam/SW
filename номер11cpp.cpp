#include <iostream>
#include<locale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    int n1 = 0;
    cout << "������� �����:"; cin >> n;
    if (n < 0) n = -n;
    if (n == 0) cout << 0 << endl;
    else
    {
        while (n >= 1)
        {
            n1 = 10 * n1 + n % 10;
            n /= 10;
        }

        while (n1 >= 1)
        {
            cout << n1 % 10 << endl;
            n1 /= 10;
        }
    }
    return 0;
}