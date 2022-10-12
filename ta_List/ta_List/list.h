#pragma once
#include<iostream>

/// <summary>
/// Реализация узла
/// value - Значение, заданное пользователем
/// * next, * prev - указатели на предыдущий и первый элемент
/// Node(int data) - конструктор
/// </summary>
struct Node {
    int value;
    Node* next;
    Node* prev;
    Node(int data) : value(data), next(nullptr), prev(nullptr) {}
};
/// <summary>
/// * front, * back - указатель на первый и последний узел
/// list(): - конструктор
/// clear - очистка списка
/// is_empty - проверка списка на наличие узлов
/// pushFront - добавление элемента в начало
/// pushBack - добавление элемента в конец
/// print - вывод списка на экран
/// getNth - получение N-ого элемента списка
/// popFront - удаление первого элемента
/// popBack - удаление последнего элемента
/// deleteNth - удаление N-ого элемента
/// insertNth - добавление элемента на N-ую позицию
/// </summary>
struct list {
    Node* front;
    Node* back;
    list() : front(nullptr), back(nullptr) {}
    ~list() {
        while (!is_empty())
        {
            popFront();
        }

    }
    
    /// <summary>
    /// Удаляет все элементы из списка
    /// </summary>
    void clear();

    /// <summary>
    /// Проверяет наличие узлов в списке
    /// </summary>
    /// <returns>true - узлов нет /false - узлы есть</returns>
    bool is_empty();

    /// <summary>
    /// Добавляет элемент в начало списка
    /// </summary>
    /// <param name="data">Добавляемое значение</param>
    void pushFront(int data);
    
    /// <summary>
    /// Добавляет элемент в конец списка
    /// </summary>
    /// <param name="data">Добавляемое значение</param>
    void pushBack(int data);

    /// <summary>
    /// Выводит список на экран
    /// </summary>
    void print();

    /// <summary>
    /// Находит узел в списке по заданному значению
    /// </summary>
    /// <param name="data">- искомое значение</param>
    /// <returns>Соответствующий значению узел</returns>
    Node* getNth(int data);

    /// <summary>
    /// Удаляет первый узел в списке
    /// </summary>
    void popFront();
    
    /// <summary>
    /// Удаляет последний узел в списке
    /// </summary>
    void popBack();

    /// <summary>
    /// Удаляет узел по заданному значению
    /// </summary>
    /// <param name="data"> - удаляемое значение</param>
    void deleteNth(int data);

    /// <summary>
    /// Вставляет узел по заданному значению
    /// </summary>
    /// <param name="front"> - указатель на начало списка</param>
    /// <param name="data"> - вставляемое значение</param>
    /// <param name="n"> - позиция, на которую вставляется значение</param>
    void insertNth(Node* front, int data, int n);
};