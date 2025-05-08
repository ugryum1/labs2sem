#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <fstream>

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND> class ListNode { // узел списка
private:
    INF d;                  // информационная часть узла
    ListNode *next;         // указатель на следующий узел списка
    ListNode(void) { next = nullptr; } //конструктор

    ListNode(const ListNode& other); // конструктор копирования
    ListNode& operator=(const ListNode& other); // оператор присваивания

    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF> class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void);           // конструктор
    MyStack(const MyStack& other); // конструктор копирования
    MyStack& operator=(const MyStack& other); // оператор присваивания
    ~MyStack(void);          // освободить динамическую память
    bool empty(void);        // стек пустой?
    bool push(INF n);        // добавить узел в вершину стека
    bool pop(void);          // удалить узел из вершины стека
    INF top_inf(void);       // считать информацию из вершины стека

    void print(std::ostream& out) const;

    template <class T> friend std::ostream& operator<<(std::ostream& out, const MyStack<T>& stack);
};

template<class INF, class FRIEND> ListNode<INF, FRIEND>::ListNode(const ListNode<INF, FRIEND>& other) : d(other.d), next(nullptr) {}

template<class INF, class FRIEND> ListNode<INF, FRIEND>& ListNode<INF, FRIEND>::operator=(const ListNode<INF, FRIEND>& other) {
    if (this != &other) {
        d = other.d;
    }
    return *this;
}

template <class INF> MyStack<INF>::MyStack(void) {
	top = nullptr;
}

template <class INF> MyStack<INF>::MyStack(const MyStack& other) : top(nullptr) {
    if (other.top) {
        Node* current = other.top;
        Node* prev = nullptr;
        while (current) {
            Node* newNode = new Node();
            newNode->d = current->d;
            if (!top) {
                top = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            current = current->next;
        }
    }
}

template <class INF> MyStack<INF>& MyStack<INF>::operator=(const MyStack& other) {
    if (this != &other) {
        while (!empty()) { // удаляем все существующие элементы стека
            pop();
        }

        if (other.top) { // если у другого стека есть элементы, копируем их
            Node* current = other.top; // указатель на текущий узел копируемого стека
            Node* prev = nullptr; // указатель на предыдущий узел нового стека
            while (current) { // проходим по всем узлам исходного стека
                Node* newNode = new Node(); // создаем новый узел
                newNode->d = current->d; // копируем данные
                if (!top) { // если это первый элемент, делаем его вершиной
                    top = newNode;
                } else { // иначе связываем его с предыдущим узлом
                    prev->next = newNode;
                }
                prev = newNode; // обновляем предыдущий узел
                current = current->next; // переходим к следующему узлу исходного стека
            }
        }
    }
    return *this; // Возвращаем текущий объект
}

template <class INF> MyStack<INF>::~MyStack(void) {
	while (!empty()) {
        pop();
    }
}

template <class INF> bool MyStack<INF>::empty(void) {
	return top == nullptr;
}

template <class INF> bool MyStack<INF>::push(INF n) {
	Node* newNode = new Node(); // новый узел
    newNode->d = n;
    newNode->next = top; // новый узел указывает на старый top
    top = newNode; // новый узел становится вершиной стека
    return true;
}

template <class INF> bool MyStack<INF>::pop(void) {
	if (empty()) {
        return false;
    }
    Node* temp = top;  // запоминаем текущий top
    top = top->next;   // смещаем вершину вниз
    delete temp;       // удаляем прежний top
    return true;
}

template <class INF> INF MyStack<INF>::top_inf() {
    if (empty()) {
        throw std::runtime_error("Стек пуст.");
    }
    return top->d;
}

template <class INF> void MyStack<INF>::print(std::ostream& out) const {
    Node* current = top;
    bool first = true;
    while (current != nullptr) {
        if (!first) {
            out << " * ";
        }
        out << current->d;
        current = current->next;
        first = false;
    }
}

template <class INF> std::ostream& operator<<(std::ostream& out, const MyStack<INF>& stack) {
    stack.print(out);
    return out;
}

#endif // MYSTACK_H
