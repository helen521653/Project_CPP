//
// Created by yalavrinenko on 15.11.2021.
//
#include <iostream>
#include <cassert>

/***
 * Реализуйте структуру данных очередь. Тесты придумайте сами, тесты должны демонстрировать работу вашей очереди
 */

using value_type = char;
struct queue{
    value_type *data = nullptr;
    size_t head = 1;
    size_t tail = 1;
    size_t length = 0;

};

queue* queue_create(size_t max_queue_size){
    auto q = new vector;
    q->data = new value_type [max_queue_size];
    q->head =1;
    q->tail = 1;
    q->length = max_queue_size;
    return q;

}

void queue_release(queue** q){
    delete[] (*q)->data;
    delete *q;
    *q = nullptr;

}

void queue_push(queue *q, value_type value){
    q->data[q->tail] = value;
    if(q->tail == q->length){
        q->tail =1;
    } else{
        q->tail = ++(q->tail);
    }

}

void queue_pop(queue *q) {
    queue_front(q);
    if (q->head == q->length) {
        q->head = 1;
    } else {
        q->head = ++(q->head);
    };

}

value_type queue_front(queue* q) {
    value_type x = q->data[q->tail];
    return x;
}

bool empty(queue* q){
    if(q->tail ==q->head==1){
        return true;
    }
}

int main(){
  //plase tests here
}