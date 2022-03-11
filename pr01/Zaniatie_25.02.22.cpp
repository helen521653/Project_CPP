//const_ cast<type>(src) - пребраз конст в неконст и обратно
//static_cast<target_t>(src) - преобраз какого- то типа к какому - то, класса к классу
//dynamic_cast<target_t>(src) - преверяет цепочку наследования не даёт преобразовать указатель одного класса в другой
// если они не равнозначны
//
#include <iostream>
#include <string>

namespace namespaceA {
    class Engine {
    public:
        void run() {
            std::cout << "EngineA run" << std::endl;
        }
    };
}

namespace namespaceB {
    class Engine {
    public:
        void run() {
            std::cout << "EngineB run" << std::endl;
        }
    };
}

namespace namespaceC {
    class Engine {
    public:
        void run() {
            std::cout << "EngineC run" << std::endl;
        }
    };
}
class MyEngine {
public:
    // Если передан параметр 1 - должен быть вызван метод run и Engine-а из библиотеки A.
    // Если передан параметр 2 - должен быть вызван метод run и Engine-а из библиотеки B.
    // Если передан параметр 3 - должен быть вызван метод run и Engine-а из библиотеки C.
    // Если передано что-то иное - должно ничего не произойти.
    void run(unsigned int number){
        namespaceA::Engine a;
        namespaceB::Engine b;
        namespaceC::Engine c;

        if(number==1){
            a.run();
        }
        else if(number==2){
            b.run();
        }
        else if(number==3){
            c.run();
        }
    };
};



int main(){

    MyEngine e;
    e.run(1); // вызов run из Engine-а из библиотеки A
    e.run(2); // вызов run из Engine-а из библиотеки B
    e.run(3); // вызов run из Engine-а из библиотеки C
    e.run(10); // ничего не происходит

    return 0;
};