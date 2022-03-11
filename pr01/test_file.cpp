#include <iostream>

class Storage
{
public:
    unsigned int n;
    unsigned int* m;

    // Конструктор хранилища размерности n
    Storage(unsigned int n):n{n}, m{new unsigned int[n]}{};

    // Добавьте нужный деструктор
    ~Storage(){delete []m;};

    // Получение размерности хранилища
    unsigned getSize(){return n;};

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    int getValue(unsigned int i) {return m[i];};

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    void setValue(unsigned int i, int value){m[i] = value;};
};

//Приблизительный код для тестирования реализованного класса:

// Класс TestStorage, наследуется от вашей реализации Storage
class TestStorage : public Storage {
protected:
    // Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
    int* more_data;

public:
    // В конструкторе память выделяется,
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }
    // ... а в деструкторе освобождается - всё честно.
    ~TestStorage() {
        delete[] more_data;
    }
};

int main() {
    Storage *ts = new TestStorage(42);
    delete ts;
    return 0;
}

