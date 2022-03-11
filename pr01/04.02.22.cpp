#include <iostream>
#include <string>
struct student{
    std::string name_;
    unsigned marks_num_;
    unsigned *marks_;
};

void read_students(student **students, unsigned *students_count)
int main(){
    unsigned students_count;
    student *students;
    std::cin>> students_count;
    students = new student[students_count];

    for (auto i  = 0; i<students_count;++i){
        std::cin>> students[i].name_>>data[i].marks_num_
    }


  return 0;

};