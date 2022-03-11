#include <iostream>
using namespace std;


class SpacePort
{
public:
    unsigned int size;
    unsigned int *data;

    // Создать космодром, в котором size штук доков.
    // Доки нумеруются от 0 до size-1.
    // В момент создания все доки свободны.
    SpacePort(unsigned int size):
            size{size},data{new unsigned [size]} {
        for(int i = 0;i<size;++i ){
            data[i] = 0;
        };
    }

    // Запросить посадку в док с номером dockNumber.
    // Если такого дока нет - вернуть false (запрет посадки).
    // Если док есть, но занят - вернуть false (запрет посадки).
    // Если док есть и свободен - вернуть true (разрешение посадки) и док становится занят.
    bool requestLanding(unsigned int dockNumber){
        if(dockNumber<=((this-> size)-1)){
            if((this->data[dockNumber])==0){
                this->data[dockNumber] = 1;
                return true;
            }
            else{
                return false;
            };
        }
        else{
            return false;
        };
    };

    // Запросить взлёт из дока с номером dockNumber.
    // Если такого дока нет - вернуть false (запрет взлёта).
    // Если док есть, но там пусто - вернуть false (запрет взлёта).
    // Если док есть и в нём кто-то стоит - вернуть true (разрешение взлёта) и док становится свободен.
    bool requestTakeoff(unsigned int dockNumber){
        if(dockNumber<=((this-> size)-1)){
            if((this->data[dockNumber])==0){
                return false;
            }
            else{
                this->data[dockNumber] = 0;
                return true;
            };
        }
        else{
            return false;
        };
    };
    ~SpacePort()
    {
        delete[] this->data;
    }
};
int main(){
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;

    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;
    return 0;
}