#include <iostream>

struct list_node{
  int value;
  list_node *next;
};

list_node* list_create_node(int value) {
  return new list_node{value, nullptr};
}

void list_release_node(list_node **node){
  delete *node;
  *node = nullptr;
}

list_node* list_next(list_node const *node){
  return node->next;
}

list_node* list_push_front(list_node **head, int value) {
  auto node = list_create_node(value);
  node->next = *head;
  *head = node;
  return node;
}

list_node* list_insert_after(list_node *position, int value){
  auto node = list_create_node(value);
  if (position){
    node->next = position->next;
    position->next = node;
  }
  return node;
}

list_node* list_merge_after(list_node *position, list_node* list){
  if (position){
    auto forward_node = position->next;
    position->next = list;

    for (; list != nullptr && list->next != nullptr; list = list_next(list));
    if (list != nullptr)
      list->next = forward_node;
  }
  return list;
}

int list_node_value(list_node const *node){
  return node->value;
}

void update_node_value(list_node *node, int value){
  node->value = value;
}

void list_delete(list_node** head, list_node *node){
  if (*head == node && node != nullptr){
    *head = node->next;
  } else if (node != nullptr) {
    auto it = *head;
    while (it != nullptr && it->next != node)
      it = list_next(it);
    if (it) {
      it->next = node->next;
    }
  }
  list_release_node(&node);
}

list_node* list_find(list_node* head, int value){
  auto it = head;
  for (; it != nullptr && list_node_value(it) != value; it = list_next(it));
  return it;
}

void list_clear(list_node **head){
  auto it = *head;
  while (it != nullptr)
    list_delete(&it, it);
  *head = nullptr;
}

template<typename InitList>
bool check_list(list_node const* head, InitList const& eta){
  for (auto const &eta_element : eta){
    if (!head || eta_element != list_node_value(head)){
      return false;
    }
    head = list_next(head);
  }

  return head == nullptr;
}

template<typename InitData>
list_node* create_list(InitData const& data){
  list_node *head = nullptr, *it = head;
  for (auto e: data) {
    if (it == nullptr) {
      list_push_front(&head, e);
      it = head;
    } else
      it = list_insert_after(it, e);
  }
  return head;
}

template<typename EtaData>
void dump_list_check(list_node **head, EtaData const& eta){
  std::cout << "Casual test " << std::boolalpha << check_list(*head, eta) << std::endl;
  list_clear(head);
  std::cout << "Cleared " << std::boolalpha << (*head == nullptr) << std::endl;
}

int main() {
  {
    //Casual test.
    auto data = {1, 2, 5, 6, 7, 8, 10};
    auto head = create_list(data);

    dump_list_check(&head, data);
  }

  {
    //Casual list plus insertion at the end and front
    auto main_data = {1, 2, 3};
    auto l = create_list(main_data);

    auto insert_at_end = {10, 20, 30};
    auto l_it = l; for (; list_next(l_it) != nullptr; l_it = list_next(l_it));
    for (auto e : insert_at_end)
      l_it = list_insert_after(l_it, e);

    auto insert_stack_front = {-1, -2, -3};
    for (auto e : insert_stack_front)
      list_push_front(&l, e);

    auto eta = {-3, -2, -1, 1, 2, 3, 10, 20, 30};
    dump_list_check(&l, eta);
  }

  {
    //Insert after find
    auto data = {1, 2, 3, 4, 5, 6, 7};
    auto l = create_list(data);

    auto it = list_find(l, 4);
    it = list_insert_after(it, 44);
    it = list_insert_after(it, 45);
    it = list_insert_after(it, 46);

    it = list_find(l, 6);
    list_insert_after(it, 61);

    it = list_find(l, 1);
    list_insert_after(it, 11);
    it = list_find(l, 7);
    list_insert_after(it, 71);
    auto eta = {1, 11, 2, 3, 4, 44, 45, 46, 5, 6, 61, 7, 71 };
    dump_list_check(&l, eta);
  }

  {
    //Merge test
    auto list_1 = {1, 2, 3, 4, 5, 6};
    auto list_2 = {-1, -2, -3, -4, -5, -6};
    auto l1 = create_list(list_1);
    auto l2 = create_list(list_2);

    list_merge_after(list_find(l1, 3), l2);
    auto eta = {1, 2, 3, -1, -2, -3, -4, -5, -6, 4, 5, 6 };
    dump_list_check(&l1, eta);
  }

  return 0;
}
