/***
 * Требуется:
 * 1. Реализовать алгоритм медленной сортировки (один из: сортировка выбором, вставками, пузырьком)
 * 2. Реализовать алгоритм быстрой сортировки (сортировка Хоара или сортировка слиянием)
 * 3. Реализовать алгоритмы поиска элемента в отсортированном массиве (тривиальный алгоритм, бинарный поиск)
* Вопросы к заданию:
 * 1. Определить зависимость времени работы медленной сортировки (сортировки выбором) от числа элементов массива
 * 2. Определить зависимость времени работы быстрой сортировки (сортировка Хоара/сортировка слиянием)  от числа элементов массива
 * 3. Определить количество элементов массива при котором медленная сортировка работает быстрее быстрой(1...1000).
 * 4. Определить зависимость времени работы тривиального поиска от количества элементов массива и количества запросов поиска
 * 5. Определить зависимость времени работы бинарного поиска от количества элементов массива и количества запросов поиска
 * 6. Обменяться кодами быстрой сортировки с одногрупниками, провести исследование времени работы альтернативного алгоритма.
 * 7. Определить диапазоны значений параметра N, для которых тот или иной алгоритм сортировки применим
 * 8. Определите максимальное значение параметра MAX_N(для mergesort когда программа пере (с точностью до десятков тысяч) при котором программа может работать
*/

#include <iostream>
#include "extension.hpp"
using namespace std;

unsigned long long const MAX_N = 100000; //Максимальное количество элементов в массиве

//******************************Поиск элемента в массиве**********************************

//Напишите здесь функцию которая выполняет поиск заданного элемента в массиве и возвращает его индекс
unsigned long ElementFind(long a[MAX_N],long f, unsigned long n){
    unsigned long ind;
    for(unsigned long i = 0;  i < n-1; ++i){
        if(a[i]==f){
            ind = i;
            return ind;
        }
    }
}

//***************************************************************************************

//***********************Сортировка выбором********************************************
//Напишите здесь функцию которая выполняет сортировку выбором переданного ей массива

long foundmin(long a[MAX_N], unsigned long s, unsigned long e){
    unsigned long ind=  s;
    long minim = a[s];
    for( unsigned long i=s+1;i<=e;++i) {
        if (a[i] < minim) {
            minim = a[i];
            ind = i;
        }
    }
    return ind;
}

void SortVybor(long c[MAX_N],unsigned long n)
{
    unsigned long s = 0,e = n-1;
    for(unsigned long current = 0;current< e;++current){
        unsigned long p = foundmin(c, current,e);
        swap(c[current],c[p]);
        s+=1;
    }
}




//***************************************************************************************

//**********************************Сортировака слиянием*********************************

//Напишите здесь функцию которая выполняет сортировку массива слиянием (если от вас это требуется)

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


//***************************************************************************************

//**********************************Сортировка Хоара*************************************

//Напишите здесь функцию которая выполняет сортировку Хоара для переданного ей массива (если от вас это требуется)
void QuickSort(long c[MAX_N], unsigned long s,unsigned long e){
    unsigned long indopporn = e;
    for(unsigned int i = 0; i<=e;++i ){
        if ((c[i]> c[indopporn]) && (i<indopporn)){
            swap(c[i],c[indopporn]);
            indopporn = i;

        }
    }
    unsigned long opl = indopporn, opr = indopporn;
    if (opl>0){
        QuickSort(c, 0,opl - 1);

    }
    if (opr<e){
        QuickSort(c,opr+1,e);

    }
}

//***************************************************************************************

void search_test_function(long A[MAX_N], unsigned long N, unsigned long requests_counts){
  Utils util;
  long *requests =new long[requests_counts];
  util.generate_data(requests, requests, requests_counts);

  Timer t; t.start();
  unsigned long misses = 0;
  for (auto i = 0ul; i < requests_counts; ++i){
    unsigned long index = 0;
    index = ElementFind(A,requests[i],N); //Разместите вызов вашей функции поиска элемента requests[i] в массиве A здесь
    if (index >= N){
      ++misses;
    }
    if (index < N && A[index] != requests[i]){
      std::cout << "Fail to search " << requests[i] << ". A[index] == " << A[index] << std::endl;
      return;
    }
  }
  t.stop();

  std::cout << "Processed " << requests_counts << " requests for array size " << N << ". Missed "<< misses
            << " requests. Elapsed time: "
            << t.elapsed() << " microseconds." << std::endl;

  delete[] requests;
}

int main() {
  Utils util;

  long slow_data[MAX_N], rapid_data[MAX_N];

  unsigned long const N = 10000; //Варьируемый параметр. Можно смело изменять для получения зависимости времени от N. N <= MAX_N

  //Генерация N произвольных числе из отрезка [-1000, 1000] в массивы slow_data и rapid_data. slow_data[i] == rapid_data[i]
  util.generate_data(slow_data, rapid_data, N);

  //*****************************Тестирование медленной сортировки******************************************************
  {
    Timer t;
    t.start();

    SortVybor(slow_data,N);//Разместите вызов функции медленной сортировки для массива slow_data здесь

    t.stop();

    if (!util.check_order(slow_data, N)) {
      std::cout << "Sort order is wrong. Check the sort function." << std::endl;
    } else {
      std::cout << "Performed slow sort of " << N << " elements. Elapsed time: " << t.elapsed() << " microseconds.\n" ;
    }
    std::cout << "First min(" << N << ", 10) elements:\n";
    for (auto i = 0; i < std::min(N, 10ul); ++i)
      std::cout << slow_data[i] << " ";
    std::cout << std::endl;
  }
  //********************************************************************************************************************

  //*****************************Тестирование быстрой сортировки********************************************************
  {
    Timer t;
    t.start();

    QuickSort(rapid_data,0,N);//Разместите вызов функции быстрой сортировки для массива rapid_data здесь

    t.stop();

    if (!util.check_order(rapid_data, N)) {
      std::cout << "Sort order is wrong. Check the sort function." << std::endl;
    } else {
      std::cout << "Performed rapid sort of " << N << " elements. Elapsed time: " << t.elapsed() << " microseconds.\n";
    }

    std::cout << "First min(" << N << ", 10) elements:\n";
    for (auto i = 0; i < std::min(N, 10ul); ++i)
      std::cout << rapid_data[i] << " ";
    std::cout << std::endl;
  }
  //********************************************************************************************************************

  //*****************************Тестирование поиска элемента в массиве*************************************************
  unsigned long request_count = 100; //Количество запросов поиска. Можно варьировать в неограниченных (в разумной степени) пределах
  search_test_function(slow_data, N, request_count);
  //********************************************************************************************************************
  return 0;
}
