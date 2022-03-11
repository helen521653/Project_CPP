#include <iostream>
#include <string>
#include <cmath>
//wsl 0.2
//Класс для представления временного интервала
class time_delta{
public:
double seconds;
    //конструктор временного интервала в seconds секунд
    time_delta(double seconds){

    };

    //возвращает количество продолжительность интервала в секундах
    double count();
};
/*!_______________________________________________________*/

//класс для представления временной метки в виде hh:mm:ss
class mtime {
public:
    size_t hh;
    size_t mm;
    size_t ss;
    //создает временную метку 00:00:00
    mtime():hh{0},mm{0},ss{0}{
    };
    //создает временную метку с заданными значениями hh, mm и ss
    mtime(size_t hh, size_t mm, size_t ss):hh{hh},mm{mm},ss{ss}{
    };
    //задает временную метку отстоящую на ss секунд от 00:00:00
    mtime(size_t ss):hh{0},mm{0},ss{ss}{
    };



    //задает временную метку из строки вида HH:MM:SS
    mtime(std::string const &time){
        std::string s = time;
        std::string s1;

        size_t f_hour = 0;

        while(s != ('?'*s.length()) )
        s.find(":",f_hour);
        for(auto i = 0;i<f_hour;++i){
            hh+=(s[i]-'0')*pow(10,f_hour-i);
            s[i] = '?';
        }




    };

    //возвращает временную метку в виде количества секунд от 00:00:00
    size_t to_seconds();

    //Выполнить корректную перегрузку следующих операторов
    bool operator== (mtime const &t); //сравнение двух меток
    mtime operator+ (time_delta const &td); //прибавление временного интервала

    mtime operator- (time_delta const &td); // вычитание временного интервала
    time_delta operator- (mtime const &t); // вычитание другой временно метки. Результат временной интервал

    //Увеличение/уменьшение временной метки на 1 секунду
    mtime& operator++();
    mtime operator++(int);

    mtime& operator--();
    mtime operator--(int);
};
//Добавить перегрузку опраторов вывода в поток std::ostream временной метки в формате hh:mm:ss
//Добавить перегрузку опретора ввода из потока std::istream временной метки в формате hh:mm:ss
//Проверить что перегрузка выполнена и для порядка слагаемых: mtime + time_delta и time_delta + mtime