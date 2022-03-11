#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void sort_errors(unsigned int** errors, unsigned int n, unsigned int m){

};

// Здесь ваша реализация функции

int main()
{
    unsigned int n, m;
    cin >> n >> m;
    unsigned int** data = new unsigned int*[n];
    for (unsigned int i = 0; i < n; i++)
        data[i] = new unsigned int[m];
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            cin >> data[i][j];

    sort_errors(data, n, m);

    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }

    for (unsigned int i = 0; i < n; i++)
        delete[] data[i];
    delete[] data;
    return 0;
}