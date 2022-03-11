#include <iostream>
using namespace std;

////// реализовать стек и очередь
///задача со скобочками
struct mvector{
    int *data = nullptr;
    unsigned int capacity = 0;
    unsigned int size = 0;

};
void resize(mvector *v,unsigned int scale){
    auto * new_data = new int[v->capacity*scale];
    for (auto i = 0ul;i< v->size;++i){
        new_data[i] = v->data[i];
    };
    delete [] v->data;
    v->data = new_data;
    v->capacity *= scale;
};
void push_back(mvector *v, int value){
    if(v-> size +1 == v-> capacity){
        resize(v,2);
    }
    v->data[v->size] = value;
    ++v->size;
};
void shrink2fit(mvector *v){
    auto *ndata = new int [v->size];
    for(auto i = 0ul;i<v->size;++i){
        ndata[i] = v->data[i];
    };
    v->data = ndata;
    delete [] v->data;
    v->capacity = v->size;
};

void print_vector(mvector){

};

mvector* create(unsigned int capacity){
    mvector *v=new mvector ;
    v->data = new int[capacity];
    v->capacity = capacity;
    v->size = capacity;
    return v;
};


void free(mvector *v){
    delete [] v->data;
    delete v;
};

