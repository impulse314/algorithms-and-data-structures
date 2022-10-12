#include <iostream>
#include "list.h"
#include <crtdbg.h>
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC //для ловли утечек памяти
using namespace std;

void list::clear() {

}

bool list::is_empty() {
    return front == nullptr; //если первый узел указывает на null, значит список пуст
}

void list::pushFront(int data){
    Node* tmp = new Node(data);
    if (is_empty()) {
        front = tmp;
        back = tmp;
        return;
    }
    tmp->next = front;
    front->prev = tmp;
    front = tmp;
}

void list::pushBack(int data){
    Node* tmp = new Node(data);
    if (is_empty()) {
        front = tmp;
        back = tmp;
        return;
    }
    back->next = tmp;
    tmp->prev = back;
    back = tmp;
}

void list::print() {
    if (is_empty()) return;
    Node* tmp = front;
    while (tmp) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

Node* list::getNth(int data) {
    Node* tmp = front;
    while (tmp && tmp->value != data)
        tmp = tmp->next;
    return (tmp && tmp->value == data) ? tmp : nullptr;
}

void list::popFront() {
    if (is_empty())
        return;
    Node* tmp = front;
    if (tmp->next) {
        front = tmp->next;
        front->prev = nullptr;
    }
    else {
        front = nullptr;
        back = nullptr;
    }
    delete tmp;
}

void list::popBack() {
    if (is_empty())
        return;
    Node* tmp = back;
    if (tmp->prev) {
        back = tmp->prev;
        back->next = nullptr;
    }
    else {
        back = nullptr;
        front = nullptr;
    }
    delete tmp;
}

void list::deleteNth(int data) {
    if (is_empty())
        return;
    if (front->value == data) {
        popFront();
        return;
    }
    else if (back->value == data) {
        popBack();
        return;
    }
    Node* fast = getNth(data);
    if (!fast) {
        cout << "This element does not exist" << endl;
        return;
    }
    fast->next->prev = fast->prev;
    fast->prev->next = fast->next;
    delete fast;
}

void list::insertNth(Node* front, int data, int n) {
    int i = 0;
    if (is_empty())
        pushFront(data);
    else {
        Node* tmp = new Node(data);

        while (i < n - 1) {
            if (front->next) {
                front = front->next;
                i++;
            }
            else {
                cout << "You're out of list's bounds!" << endl;
                return;
            }
        }
        tmp->next = front->next;
        if (front->next)
            front->next->prev = tmp;
        front->next = tmp;
        tmp->prev = front;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    list l;

    for (int j = 0; j < 1; j++)
    {
        int run = rand() % 5;
        for (int i = 0; i < 10; i++)
        {
            l.pushFront(rand() % 100);
        }
    }


    int menu = 1;
    while (menu) {
        int value = 0;
        int pos = 0;
        if (menu != 7) 
            system("cls");
        cout << "1. Вставить в начало списка\n"
            << "2. Вставить в конец списка\n"
            << "3. Вставить по индексу\n"
            << "4. Удалить первый элемент\n"
            << "5. Удалить последний элемент\n"
            << "6. Удалить по индексу\n"
            << "7. Вывести список\n"
            << "0. Выход\n";
        cout << "Введите номер команды: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "\nВведите значение: ";
            cin >> value;
            l.pushFront(value);
            system("pause"); 
            break;
        case 2:
            cout << "\nВведите значение: ";
            cin >> value;
            l.pushBack(value);
            system("pause"); 
            break;
        case 3:
            cout << "\nВведите значение: ";
            cin >> value;
            cout << "\nНа какую позицию вставляем: ";
            cin >> pos;
            l.insertNth(l.front, value, pos);
            system("pause"); 
            break;
        case 4:
            l.popFront();
            system("pause"); 
            break;
        case 5:
            l.popBack();
            system("pause"); 
            break;
        case 6:
            cout << "\nКакое значение удаляем: ";
            cin >> value;
            l.deleteNth(value);
            system("pause"); 
            break;
        case 7:
            l.print();
            system("pause"); 
            break;
        case 0:
            break;
        default:
            break;
        }
        cout << endl;
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
