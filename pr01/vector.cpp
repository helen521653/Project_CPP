#include <iostream>

using value_type = int; //value_type пседоним для int. Позволяет быстро изменять тип данных в векторе

struct vector{
  value_type *data = nullptr;
  size_t size = 0;
  size_t capacity = 0;
};

/***
 * Инициализация вектора размера size
 * @param size Количество элементов в векторе
 * @return Указатель блок информации о векторе
 */
vector* vector_create(size_t size){  //что такое size_t, тип данных? как и value_type?___
  auto v = new vector;
  v->data = new value_type [size];
  v->size = v->capacity = size; // разве size не 0 при создании____
  return v;
}

/***
 * Освобождение ресурсов вектора
 * @param v
 */
void vector_release(vector** v){
  delete[] (*v)->data; //освобождаем данные вектора
  delete *v; //освобождаем память под структуру вектор
  *v = nullptr;
}

/***
 * Изменение размера вектора.
 * @param v Указатель на информацию о векторе
 * @param target_size Целевой размер вектора
 */
void vector_resize(vector *v, size_t target_size){
  auto new_data = new value_type [target_size]; //Выделяем новый участок памяти

  for (auto i = 0ul; i < std::min(v->size, target_size); ++i)
    new_data[i] = v->data[i]; //копирование старых данных в новые

  delete[] v->data; //освобождение старых данных

  v->data = new_data; //обновляем указатель на хранилище
  v->capacity = target_size;
  v->size = std::min(v->size, target_size);
}

/***
 * Добавление элемента в конец вектора
 * @param v Вектор
 * @param value Значения
 */
void vector_push_back(vector *v, value_type value){
  if (v->size == v->capacity){ //Размер вектора израсходован, нужна переаллокация
    auto const scale = 2; //Во сколько раз увеличивать размер вектора. Попробуйте изменять этот параметр и смотреть, что будет.
    vector_resize(v, v->capacity * scale);
  }
  v->data[v->size] = value;
  ++v->size;
}

/***
 * Подогнать размер вектора под количество данных
 * @param v
 */
void vector_shrink2fit(vector *v) {
  vector_resize(v, v->size);
}

/***
 * Очистить вектор
 * @param v
 */
void vector_clear(vector *v) {
  v->size = 0;
}

void vector_dump(vector const* v, char const* label){

  std::cout << "******************[" << label << "]********************\n";

  if (v == nullptr) {
    std::cout << "Non-initialized vector\n";
  } else {
    std::cout << "Vector at address: " << v << "\n"
              << "\tdata: " << v->data << "\n"
              << "\tsize: " << v->size << "\n"
              << "\tcapacity: " << v->capacity << "\n";
    for (auto i = 0ul; i < v->size; ++i)
      std::cout << v->data[i] << " ";
    std::cout << "\n";
  }
  std::cout << "****************************************************\n";
}

void vector_simple_demo(){
  vector* v = vector_create(10); //vector with 10 elements
  vector_dump(v, "Uninitialized vector"); //May trigger valgrind error.

  for (auto i = 0ul; i < v->size; ++i)
    v->data[i] = i;
  vector_dump(v, "After init");

  for (auto i = 0; i < 21; ++i)
    vector_push_back(v, i * i);
  vector_dump(v, "Insert 21 values");

  vector_shrink2fit(v);
  vector_dump(v, "After shrink to fit");

  vector_resize(v, 15);
  vector_dump(v, "After resize");

  vector_clear(v);
  vector_dump(v, "After clear");

  for (auto i = 0; i < 10; ++i)
    vector_push_back(v, i * 100);
  vector_dump(v, "Next 10 insertion");

  vector_release(&v);
  vector_dump(v, "After release");
}

int main() {
  vector_simple_demo();
  return 0;
}
