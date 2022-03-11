//
// Created by yalavrinenko on 15.11.2021.
//
#include <iostream>
#include <cassert>

using value_type = char;

/***
 * Реализовать структуру данных stack написав реализации сответствующих структур и функций
 * Тестирование выполняется на задаче проверки правильной скобочной последовательности
 */

struct stack {
    value_type *data = nullptr;
    int top = 0;
};

stack *stack_create(size_t max_stack_size) {
    auto s = new stack;
    s->data = new value_type [max_stack_size];
    s->top= 0; //место под значение top для каждого стека ввыделяется из кучи или из стека?____
    return s;

}
void stack_release(stack **s) {
    delete[] (*s)->data; //освобождаем данные stack
    delete *s; //освобождаем память под структуру stack
    *s = nullptr;

}

void stack_push(stack *s, value_type value) {
    s->top = s->top +1;
    s->data[s->top] = value;

}

bool stack_empty(stack const *s) {
    if( s->top == 0){
        return true;
    }
    else{
        return false;
    };
}

void stack_pop(stack *s) {
    s->top = s->top -1;
}

value_type stack_top(stack const *s) {
    return s->data[s->top];

}



char braces_compl(char brace) {
  switch (brace) {
    case '}' :
      return '{';
    case ')' :
      return '(';
    case '>' :
      return '<';
    case ']' :
      return '[';
    default:
      return 'x';
  }
}

bool is_brace(char symbol) {
  char braces[] = {'{', '}', '(', ')', '[', ']', '<', '>'};
  for (auto i = 0ul; i < sizeof(braces); ++i)
    if (braces[i] == symbol) return true;

  return false;
}

bool check_brace_sequence(char const *begin) {
  auto s = stack_create(1000);
  while (*begin != '\0') {
    if (is_brace(*begin)) {
      if (braces_compl(*begin) == 'x')
        stack_push(s, *begin);
      else {
        if (stack_empty(s) || braces_compl(*begin) != stack_top(s)) {
          break;
        } else
          stack_pop(s);
      }
    }
    ++begin;
  }

  auto result = stack_empty(s) && *begin == '\0';
  stack_release(&s);
  return result;
}

int main(int argc, char **argv) {
  assert(check_brace_sequence("(){}[]<>") == true);
  assert(check_brace_sequence("}}{") == false);
  assert(check_brace_sequence("[](auto i, auto a){ some_foo(a, i).call(a); return foo(some<int>(i)); }") == true);
  assert(check_brace_sequence("[[[][[[s]{}[[[[}]]]]]][[]") == false);
  assert(check_brace_sequence("asdasdasda>") == false);
  //add your test here

  return 0;
}
