#include <iostream>
#include <string>

class Animal {
public:
    virtual std::string getType() = 0;
    virtual bool isDangerous() = 0;
};
class Monkey: public Animal{
public:
    virtual std::string getType(){
        return "Monkey";
    };
    Monkey()= default;
    bool isDangerous() override{return false;};
};
class Lion: public Animal{
public:
    Lion()= default;
    virtual std::string getType(){
        return "Lion";
    };    bool isDangerous()override {return true;};
};



class ZooKeeper {
public:
    unsigned processed_animals;
    unsigned dangerous_animals;
    // Создаём смотрителя зоопарка
    ZooKeeper():processed_animals(0u),dangerous_animals(0u) {};
    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal* a){
        processed_animals+=1;
        if(a->isDangerous()){
            dangerous_animals+=1;
        };
    };
    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount(){
        return dangerous_animals;
    };
};


int main(){
    ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;
    std::cout << z.getDangerousCount() << std::endl;

    return 0;
}