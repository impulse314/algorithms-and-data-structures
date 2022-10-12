#pragma once
#include<iostream>

/// <summary>
/// ���������� ����
/// value - ��������, �������� �������������
/// * next, * prev - ��������� �� ���������� � ������ �������
/// Node(int data) - �����������
/// </summary>
struct Node {
    int value;
    Node* next;
    Node* prev;
    Node(int data) : value(data), next(nullptr), prev(nullptr) {}
};
/// <summary>
/// * front, * back - ��������� �� ������ � ��������� ����
/// list(): - �����������
/// clear - ������� ������
/// is_empty - �������� ������ �� ������� �����
/// pushFront - ���������� �������� � ������
/// pushBack - ���������� �������� � �����
/// print - ����� ������ �� �����
/// getNth - ��������� N-��� �������� ������
/// popFront - �������� ������� ��������
/// popBack - �������� ���������� ��������
/// deleteNth - �������� N-��� ��������
/// insertNth - ���������� �������� �� N-�� �������
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
    /// ������� ��� �������� �� ������
    /// </summary>
    void clear();

    /// <summary>
    /// ��������� ������� ����� � ������
    /// </summary>
    /// <returns>true - ����� ��� /false - ���� ����</returns>
    bool is_empty();

    /// <summary>
    /// ��������� ������� � ������ ������
    /// </summary>
    /// <param name="data">����������� ��������</param>
    void pushFront(int data);
    
    /// <summary>
    /// ��������� ������� � ����� ������
    /// </summary>
    /// <param name="data">����������� ��������</param>
    void pushBack(int data);

    /// <summary>
    /// ������� ������ �� �����
    /// </summary>
    void print();

    /// <summary>
    /// ������� ���� � ������ �� ��������� ��������
    /// </summary>
    /// <param name="data">- ������� ��������</param>
    /// <returns>��������������� �������� ����</returns>
    Node* getNth(int data);

    /// <summary>
    /// ������� ������ ���� � ������
    /// </summary>
    void popFront();
    
    /// <summary>
    /// ������� ��������� ���� � ������
    /// </summary>
    void popBack();

    /// <summary>
    /// ������� ���� �� ��������� ��������
    /// </summary>
    /// <param name="data"> - ��������� ��������</param>
    void deleteNth(int data);

    /// <summary>
    /// ��������� ���� �� ��������� ��������
    /// </summary>
    /// <param name="front"> - ��������� �� ������ ������</param>
    /// <param name="data"> - ����������� ��������</param>
    /// <param name="n"> - �������, �� ������� ����������� ��������</param>
    void insertNth(Node* front, int data, int n);
};