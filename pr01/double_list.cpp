#include <iostream>
using namespace std;
using value_type = int;

struct subforwardlist {
    value_type data;
    subforwardlist* next;
    subforwardlist* prev;

};

subforwardlist* init(value_type value){	//инициализация пустого недосписка
    subforwardlist *l=new subforwardlist ;
    l->data = value;
    l->next = nullptr;
    l->prev = nullptr;
    return l;
};
bool push_back(subforwardlist @sfl, int d); 	//добавление элемента в конец недосписка
int pop_back(subforwardlist @sfl); 	//удаление элемента с конца недосписка
bool push_forward(subforwardlist @sfl, int d); 	//добавление элемента в начало недосписка
int pop_forward(subforwardlist @sfl); 	//удаление элемента из начала недосписка
bool push_where(subforwardlist @sfl, unsigned int where, int d); //добавление элемента с порядковым номером where
bool erase_where @sfl, unsigned int where);	//удаление элемента с порядковым номером where
unsigned int size(subforwardlist  @sfl);	//определить размер недосписка
void clear(subforwardlist  @sfl);