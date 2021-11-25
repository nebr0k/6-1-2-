#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
void M(int* a, const int size, int& s, int& k, int i);

int main()
{
    srand((unsigned)time(NULL)); 
    const int n = 26;
    int a[n];

    int Low = -40;
    int High = 20;
    int s = 0;
    int k = 0;

    Create(a, n, Low, High, 0);
    cout << "before: "; Print(a, n, 0);

    M(a, n, s, k, 0);
    

    cout << "sum:" << setw(4) << s << endl
        << "k:" << setw(2) << k << endl;
    cout << "after: "; Print(a, n, 0);

}
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}
void M(int* a, const int size, int& s, int& k, int i)
{
    if (a[i] < 0 || i % 2 != 0) {
        s += a[i];
        a[i] = 0;
        k++;
    }
    if (i < size - 1) 
{
        M(a, size, s, k, i + 1);
    }
}
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}