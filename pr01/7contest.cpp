#include <iostream>
using namespace std;

struct stack{
    int v;
    struct stack *prev;
};
void read_array(unsigned int** data, unsigned int* n){
    struct stack *p = nullptr;
    unsigned int value = 0,i = 0;
    while ((std::cin>>value)&&(value!=33)){
        struct stack *s = new stack;
        s->v = value;
        ++i;
        s->prev = p;
        p = s;
    };

    *n = i;
    unsigned int *d = new unsigned int [i];
    for(int j = 0; j<i; ++j){
        stack *s = p;
        d[j] = p->v;
        p = p->prev;
        delete s;
    };
    *data = d;
};
int main(){
    unsigned int n;
    unsigned int *data;
    read_array(&data,&n);
    for (int i = 0; i<(n);++i){
        cout<<data[i]<<' ';
    };

    return 0;
}