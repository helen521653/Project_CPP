#include <iostream>
using namespace std;
using value_type = int;
//Односвязный список
struct  list_node{
    int value;
    list_node *next;
};
struct TopList{
    list_node *head;
};

list_node* create(value_type value){
    list_node *p = new  list_node;
    p -> value = value;
    p->next = nullptr;
    return  p;
};
list_node* insert(list_node *u, value_type value){
    list_node *p = create(value);
    p-> next = u->next;
    u->next = p;
    return p;
};

void push_front(list_node *head, value_type value){
    list_node *p = create(value);
    p-> next = head->next;
    head->next = p;
    };
list_node* find(value_type value, list_node *head){
    list_node *p = head;
    while ((p->next != nullptr) && (p->value!=value)){
        p = p->next;
    };
    return p;

};
void delite(list_node* p,list_node* head){
    list_node *u = head;
    while (u->next!=p){
        u = u->next;
    };
    u->next = p->next;
    delete p;
};
unsigned  const N = 5;
int main(){
    list_node *head;
    value_type value;
    cout<<"Enter the head element"<< endl;
    cin>> value;
    head = create(value);
    value_type e;
    list_node* prev = head;
    value_type j = 0;
    cout<<"Enter the list items:"<< endl;
    while (j<5){
        cin>>e;
        ++j;
        prev = insert(prev, e);
    };
    cout<<"Enter a value to search for in the list:"<< endl;
    cin>> value;
    cout<< (find(value, head))->value<<" pointer: "<<find(value, head) <<" Here is the meaning you are trying to find "<<endl;
    prev = head;
    cout<<"Enter the value you want to delite:"<< endl;
    cin>> value;
    delite(find(value,head),head);
    cout<<"List after deletion:"<< endl;
    while (prev!= nullptr){
        cout<<prev->value<<' ';
        prev = prev->next;
    };
    cout<<"Enter a value to push_front in the list:"<< endl;
    cin>> value;
    push_front(head,value);
    prev = head;
    cout<<"List after push_front:"<< endl;
    while (prev!= nullptr){
        cout<<prev->value<<' ';
        prev = prev->next;
    };
    return 0;
};
