#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int const MAX_N = 100000; //Максимальное количество элементов в массиве

void merge(long a[MAX_N], unsigned long lb, unsigned long split, unsigned long ub) {
// Слияние упорядоченных частей массива в буфер temp
// с дальнейшим переносом содержимого temp в a[lb]...a[ub]

    // текущая позиция чтения из первой последовательности a[lb]...a[split]
    unsigned long pos1=lb;

    // текущая позиция чтения из второй последовательности a[split+1]...a[ub]
    unsigned long pos2=split+1;

    // текущая позиция записи в temp
    unsigned long pos3=0;

    long temp[ub-lb+1];

    // идет слияние, пока есть хоть один элемент в каждой последовательности
    while (pos1 <= split && pos2 <= ub) {
        if (a[pos1] < a[pos2])
            temp[pos3++] = a[pos1++];
        else
            temp[pos3++] = a[pos2++];
    }

    // одна последовательность закончилась -
    // копировать остаток другой в конец буфера
    while (pos2 <= ub)   // пока вторая последовательность непуста
        temp[pos3++] = a[pos2++];
    while (pos1 <= split)  // пока первая последовательность непуста
        temp[pos3++] = a[pos1++];

    // скопировать буфер temp в a[lb]...a[ub]
    for (pos3 = 0; pos3 < ub-lb+1; pos3++)
        a[lb+pos3] = temp[pos3];

    temp[ub-lb+1] = {0};
}


void mergeSort(long a[MAX_N], unsigned long lb, unsigned long ub) {
    unsigned long split;                   // индекс, по которому делим массив

    if (lb < ub) {                // если есть более 1 элемента

        split = (lb + ub)/2;

        mergeSort(a, lb, split);       // сортировать левую половину
        mergeSort(a, split+1, ub);// сортировать правую половину
        merge(a, lb, split, ub);    // слить результаты в общий массив
    }
}


int main() {
    long c[5] = {3,5,34,9,12};
    unsigned  long n, m;
    mergeSort(c, 0,sizeof(c)/ sizeof(c[0])-1);
    for(int i = 0;i<5;++i){cout<<c[i]<<" ";}

    return 0;
}
