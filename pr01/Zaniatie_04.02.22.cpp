#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

//После фразы TASK-??: идет задание которое нужно сделать. Их будет несколько в этом файле

/***
 * Класс хранящий информацию о студенте. ФОИ, и его оценки
 */
class student_info{
public:
    /**
     * Конструктор класса от двух аргументов. Инициализирует поля класса заданными значениями.
     *
     * Для инициализации полей выполняется вызов конструкторов полей класса в том порядке, в котором они
     * объявлены в приватной секции. Для передачи аргументов в конструктор используется uniform initialisation
     * через {} скобки. Практически полный эквивалент () и рекомендуемый в текущий момент.
     * https://en.cppreference.com/w/cpp/language/aggregate_initialization
     * https://habr.com/ru/company/jugru/blog/469465/
     * @param name ФИО студент
     * @param mcount Количество оценок у студента
     */
    student_info(std::string name, unsigned mcount): name_{name},
                                                     marks_count_{mcount}, marks_{new unsigned [marks_count_]} {
        read_marks(); //вызов приватного метода для чтения оценок
    }

    /**
     * Default конструктор, который использует реализацию вышеописанного конструктора для
     * инициализации состояния класса. Можно расписать инициализацию всех полей руками, но
     * это будет дублирование уже написанного кода, что не есть хорошо.
     */
    student_info(): student_info("", 0){

    }

    /*
     * TASK-2: Написать конструктор инициализирующих класс по передаваемому имени студента, количеству оценок и массиву оценок
     */

    /*
     * Набор методов для получения копий значений хранящихся в полях класса.
     */
    std::string get_name() { return name_; }
    unsigned const* get_marks() { return marks_; }
    unsigned get_marks_count() { return marks_count_; }

    /*
     * Метод возвращающий среднюю оценку
     */
    double average_mark() {
        auto ave = 0.0;
        for (auto i = 0; i < marks_count_; ++i)
            ave += marks_[i];
        return ave;
    }

    /*
     * TASK-3: Реализовать метод выводящий 5 самых больших оценок в порядке убывания.  Если оценок меньше 5 то вывести всё что есть.
     */
    void five_max_marks(){
        if( marks_count_ <= 5){
            for(auto i = 0; i < marks_count_;++i){
                std::cout<<marks_[i]<<" ";
            };
        }
        else{
            unsigned *marks_1_ = new unsigned [marks_count_];
            std::copy(marks_, marks_+marks_count_, marks_1_);
            std::sort(marks_1_, marks_1_+marks_count_, std::greater<unsigned>());
            for(auto i = 0;i<5;++i){
                std::cout<< marks_1_[i];
            };
            delete [] marks_1_;
        };
    }

private:
    /*
     * Приватный метод считывающий (в модельном случае с клавиатуры) оценки студента
     */
    void read_marks() {
        for (auto i = 0; i < marks_count_; ++i)
            std::cin >> marks_[i];
    }


    //Секция приватных переменных, доступных только из методов класса student_info
    std::string name_;  //Строка - ФИО студента

    //Эти два поля имеет смысл вынести в отдельный класс, Marks и использовать его
    //Для хранения оценок. TASK-1: Эти манипуляции предлагается проделать самостоятельно.
    unsigned marks_count_; //Количество оценок
    unsigned *marks_; //собстно, сами оценки
};

/*
 * Создаём и заполняем информацию о студентах
 */
void read_students_data(student_info** students, unsigned *count){
    std::cin >> *count;

    auto data = new student_info[*count]; //Создаём массив студентов. Вызывается default-конструктор для каждого элемента массива
    for (auto i = 0; i < *count; ++i){
        std::string name; unsigned k;
        std::cin >> name >> k;
        data[i] = student_info(name, k); //Создаём нового студента с заданным именем и копируем его в data[i]
    }

    *students = data; //возврат массива в вызываемую функцию
}

/*
 * Выполняем поиск нужного студента
 */
void process_request(std::string req_name, student_info* students, unsigned count){
    for (auto i = 0; i < count; ++i) {
        if (req_name == students[i].get_name()) {
            students[i].five_max_marks();//TASK-4: Добавить вывод 5 или меньше наибольших оценок по убыванию.
            std::cout << students[i].get_name() << " ave: " << students[i].average_mark() << std::endl;
            return; //нашли студента, вывели инфу о нём и выходим
        }
    }

    std::cout << "Student " << req_name << " not found." << std::endl;
}

int main(int argc, char** argv){
    unsigned students_count = 0;
    student_info *students;

    //Читаем студентов
    read_students_data(&students, &students_count);


    //Готовимся чистать и выполнять запросы к нашему классу
    //TASK-0: Найти ошибку в логике программы. ?? Неправильно организова delete? нет деструктора???
    unsigned req_count;
    std::cin >> req_count;
    for (auto i = 0; i < req_count; ++i){
        std::string req_name; std::cin >> req_name;
        process_request(req_name, students, students_count);
    }

    delete[] students;
    return 0;
}

//TASK-6: Обернуть операции хранения, чтения и поиска студентов в класс. Должно получиться в функции main что-то подобное:
//int main(int argc, char** argv){
//  unsigned N; std::cin >> N;
//  Storage students(N); //Прочитать информацию о N студентах
//
//  unsigned req_count;
//  std::cin >> req_count;
//  for (auto i = 0; i < req_count; ++i){
//    std::string req_name; std::cin >> req_name;
//    students.reques(req_name); //Выполнить поиск студента и вывод информации о нём.
//  }
//  return 0;
//}

//TASK-7*: Реализовать возможность добавления произвольного количества студентов в Storage
/*TASK-8*: Организовать вывод таблицы студентов блоками по m единиц на странице в виде
 * NAME1 Mark1 Mark2 ... MarkN
 * NAME2 Mark1 Mark2 ... MarkN
 * NAME3 Mark1 Mark2 ... MarkN
 */