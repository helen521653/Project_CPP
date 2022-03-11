#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

//После фразы TASK-??: идет задание которое нужно сделать. Их будет несколько в этом файле
//Класс хранящий информацию об оценках студента
 class Marks {
 public:
     Marks(unsigned mcount) : marks_count_{mcount}{
         marks_ = new unsigned[marks_count_];
         read_marks(); //вызов приватного метода для чтения оценок
         for(auto i = 0; i< marks_count_;++i){
             std::cout<< marks_[i]<< "std::endl";
         };
     }


     Marks(unsigned mcount, unsigned *marks) : marks_count_{mcount}, marks_{new unsigned[marks_count_]} {
         for(auto i = 0; i<marks_count_;++i){

         };
         //std::copy(marks_1, marks_1 + mcount, marks_);
     }

     ~Marks() {
         delete[]marks_;
     }


     unsigned const *get_marks() { return marks_; }

     unsigned get_marks_count() { return marks_count_; }

     //! Метод возвращающий среднюю оценку
     double average_mark() {
         auto ave = 0.0;
         for (auto i = 0; i < marks_count_; ++i)
             ave += marks_[i];
         return (ave / marks_count_);
     }

     //! 5 самых больших оценок в порядке убывания
     unsigned *five_max_marks() {

         if (marks_count_ <= 5) {
             std::cout<< marks_[0]<<" marks_1111 ";
             std::cout<< marks_[1]<<" marks_1111 ";



             // for (auto i = 0; i < marks_count_; ++i) {
             //   std::cout << marks_[i] << " ";
             // };
             unsigned *marks_1_ = new unsigned[marks_count_];
             for(auto i = 0; i<marks_count_; ++i){
                 marks_1_[i] = marks_[i];
                 std::cout<< marks_[i]<<" marks_ ";
             };
             //std::copy(marks_, marks_ + marks_count_* sizeof(marks_[0]), marks_1_);
             for(auto i = 0; i< marks_count_;++i){
                 std::cout<< marks_1_[i]<< "std::endl";
             };
             return marks_1_;
         } else {
             unsigned *marks_1_ = new unsigned[marks_count_];
             std::copy(marks_, marks_ + marks_count_, marks_1_);
             std::sort(marks_1_, marks_1_ + marks_count_, std::greater<unsigned>());
//             for(auto i = 0;i<5;++i){
//                 std::cout<< marks_1_[i];
//             };
//
//            delete [] marks_1_;
             return marks_1_;
         };
     };


 private:
     unsigned marks_count_; //Количество оценок
     unsigned *marks_; //собстно, сами оценки
     /*
     * Приватный метод считывающий (в модельном случае с клавиатуры) оценки студента
     */


     void read_marks() {
         for (auto i = 0; i < marks_count_; ++i) {
             if (i < 1) {
                 std::cout << "Input marks,please\n";
             };
             std::cin >> marks_[i];
         };
     };
 };

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
    //for progrpeople ctor
    student_info(std::string name, unsigned mcount,unsigned *marks_):name_{name}, mark_(mcount, marks_){
        std::cout<<"student_info for progrpeople ctor"<<std::endl;
    }

     //less stupid ctor
    student_info(std::string name, unsigned mcount) : name_{name}, mark_(mcount)
    {}
    //default ctor
    student_info(): student_info("", 0)
    {}

    double get_av_mark()
    {
        return mark_.average_mark();
    }

    void print_five_marks()
    {
        unsigned *five_marks = mark_.five_max_marks();

        for(auto i = 0; i < (sizeof(five_marks)/ sizeof(five_marks[0])); ++i){
            std::cout << five_marks[i]<<" ";
        };
        delete [] five_marks;
    }


    std::string get_name() { return name_; }
private:

    Marks mark_;
    //Секция приватных переменных, доступных только из методов класса student_info
    std::string name_;  //Строка - ФИО студента

    //Эти два поля имеет смысл вынести в отдельный класс, Marks и использовать его
    //Для хранения оценок. TASK-1: Эти манипуляции предлагается проделать самостоятельно.

};


class Storage{
public:
    Storage(unsigned N): students_count{N},data{new student_info[N]}{
        for(int i = 0; i<students_count; ++i){
            std::cout<< "Input a name of a student and a number of his marks \n";
            std::string name_of_student; unsigned mcount;
            std::cin>>name_of_student>>mcount;
            data[i] = student_info(name_of_student, mcount);
        };
    };

    ~Storage(){
        delete [] data;
    };
    void request(std::string req_name){
        for (auto i = 0; i < students_count; ++i) {
            if (req_name == data[i].get_name()) {
                data[i].print_five_marks();//TASK-4: Добавить вывод 5 или меньше наибольших оценок по убыванию.
                std::cout << data[i].get_name() << " ave: " << data[i].get_av_mark() << std::endl;
                return; //нашли студента, вывели инфу о нём и выходим
            };
        };
        std::cout << "Student " << req_name << " not found." << std::endl;
    };

private:
    student_info *data;
    unsigned students_count;
};



/*
 * Создаём и заполняем информацию о студентах
 */
/* void read_students_data(student_info** students, unsigned *count){
    std::cin >> *count;
    auto *data = new student_info[*count]; //Создаём массив студентов. Вызывается default-конструктор для каждого элемента массива
    for (auto i = 0; i < *count; ++i){
        std::string name; unsigned k;
        std::cin >> name >> k;
        data[i] = student_info(name, k); //Создаём нового студента с заданным именем и копируем его в data[i]
    }

    *students = data; //возврат массива в вызываемую функцию
}
 */

/*
 * Выполняем поиск нужного студента
 */
/*
void process_request(std::string req_name, student_info* students, unsigned count){
    for (auto i = 0; i < count; ++i) {
        if (req_name == students[i].get_name()) {
            students[i].print_five_marks();//TASK-4: Добавить вывод 5 или меньше наибольших оценок по убыванию.
            std::cout << students[i].get_name() << " ave: " << students[i].get_av_mark() << std::endl;
            return; //нашли студента, вывели инфу о нём и выходим
        }
    }
    std::cout << "Student " << req_name << " not found." << std::endl;
}
*/
/*
int main(int argc, char** argv){
    std::string iname = "Nata";
    unsigned mark_count = 3;
    unsigned mark_[3] = {1,2,3};
    student_info s = student_info(iname, mark_count, mark_);




    unsigned students_count = 0; // Общее кол-во студентов в массиве
    //std::cin >> students_count;
    student_info *students;

    //Читаем студентов
    read_students_data(&students, &students_count);  //Захочет на ввод имя и кол-во оценок в каждой строчке


    //Готовимся читать и выполнять запросы к нашему классу
    //TASK-0: Найти ошибку в логике программы.
    int j;
    std::cin >> j;
    unsigned req_count = 0; // скольких студентов хотим найти
    std::cin >> req_count;
    for (auto i = 0; i < req_count; ++i){
        std::string req_name;
        std::cin >> req_name;
        process_request(req_name, students, students_count);// ищет студентов в массиве и выводит инфо о них
    }

    delete[] students;
    return 0;
}
*/

//TASK-6: Обернуть операции хранения, чтения и поиска студентов в класс. Должно получиться в функции main что-то подобное:
int main(int argc, char** argv){
  unsigned N; std::cin >> N;
  Storage students(N); //Прочитать информацию о N студентах

  unsigned req_count;
  std::cout<< "How many students you want to search\n";
  std::cin >> req_count;
  for (auto i = 0; i < req_count; ++i){

    std::string req_name;std::cout<<"Input a name of student you want to see\n"; std::cin >> req_name;
    students.request(req_name); //Выполнить поиск студента и вывод информации о нём.
  }
  return 0;
};
//TASK-7*: Реализовать возможность добавления произвольного количества студентов в Storage
/*TASK-8*: Организовать вывод таблицы студентов блоками по m единиц на странице в виде
 * NAME1 Mark1 Mark2 ... MarkN
 * NAME2 Mark1 Mark2 ... MarkN
 * NAME3 Mark1 Mark2 ... MarkN
 */