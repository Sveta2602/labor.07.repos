#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 5;
    int High = 67;

    int rowCount = 9;
    int colCount = 5;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);
    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "S: " << S << endl;
    cout << "k: " << k << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);

}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount - 1; i++)
        for (int j = 0; j < rowCount - i - 1; j++)
            if ((a[j][0] > a[j + 1][0]) || (a[j][0] == a[j + 1][0] && a[j][1] > a[j + 1][1]) || (a[j][0] == a[j + 1][0] && a[j][1] == a[j + 1][1] && a[j][3] < a[j + 1][3]))
                Change(a, j, j + 1, colCount);
}

void Change(int** a, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int i = 0; i < colCount; i++)
    {
        tmp = a[row1][i];
        a[row1][i] = a[row2][i];
        a[row2][i] = tmp;
    }
}


void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (a[i][j] % 2 == 0 && a[i][j] % 2 == 13)
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}