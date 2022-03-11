#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void separate_rgba(unsigned int *data, unsigned int n)
{
    unsigned int* m = new unsigned int[4*n];
    for(int i = 0;i < 4*n;i++)
    {
        m[i]= data[i];
    }

    int k = 0;
    for(int b = 0; b < 4*n;b+=4)
    {
        data[k]= m[b];
        k++;
    }
    for(int b = 1; b < 4*n;b+=4)
    {
        data[k]= m[b];
        k++;
    }
    for(int b = 2; b < 4*n;b+=4)
    {
        data[k]= m[b];
        k++;
    }
    for(int b = 3; b < 4*n;b+=4)
    {
        data[k]= m[b];
        k++;
    }
    delete[] m;
}

int main()
{
    unsigned int n;
    cin >> n;
    unsigned int* data = new unsigned int[4*n];
    for (unsigned int i = 0; i < 4*n; i++)
        cin >> data[i];
    separate_rgba(data, n);
    for (unsigned int i = 0; i < 4*n; i++)
        cout << data[i] << " ";
    cout << endl;
    delete[] data;
    return 0;
}