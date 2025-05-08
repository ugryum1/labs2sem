#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include "myvector.h"

template <typename T = char*>
class MySet : public MyVector<T> {
private:
    int q_find(const T &el) const;
public:
    MySet() : MyVector<T>() {}
    explicit MySet(const T &el);
    MySet(const MySet<T> &s);
    ~MySet() = default;

    MySet<T> &operator=(const MySet<T> &s);
    bool operator==(const MySet<T> &s) const;
    MySet<T> &operator+=(const MySet<T> &s);
    MySet<T> &operator-=(const MySet<T> &s);
    MySet<T> &operator*=(const MySet<T> &s);

    void add_element(const T &el);
    bool delete_element(const T &el);
    bool is_element(const T &el) const;

    friend std::ostream &operator<<(std::ostream &out, const MySet<T> &s) {
        out << "{";
        for (int i = 0; i < s.size; ++i) {
            out << s[i];
            if (i < s.size - 1) out << ", ";
        }
        out << "}";
        return out;
    }

    friend MySet<T> operator+(const MySet<T> &s1, const MySet<T> &s2) {
        MySet<T> result = s1;
        result += s2;
        return result;
    }

    friend MySet<T> operator-(const MySet<T> &s1, const MySet<T> &s2) {
        MySet<T> result = s1;
        result -= s2;
        return result;
    }

    friend MySet<T> operator*(const MySet<T> &s1, const MySet<T> &s2) {
        MySet<T> result = s1;
        result *= s2;
        return result;
    };
};

template <typename T>
MySet<T>::MySet(const T &el) : MyVector<T>() {
    add_element(el);
}

template <typename T>
MySet<T>::MySet(const MySet<T> &s) : MyVector<T>(s) {}

template <typename T>
int MySet<T>::q_find(const T &el) const {
    int left = 0, right = this->size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (this->pdata[mid] == el) {
            return mid;
        } else if (this->pdata[mid] < el) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void MySet<T>::add_element(const T &el) {
    if (q_find(el) == -1) {
        MyVector<T>::add_element(el);
        this->sort();
    }
}

template <typename T>
bool MySet<T>::delete_element(const T &el) {
    int pos = q_find(el);
    if (pos != -1) {
        return MyVector<T>::delete_element(pos);
    }
    return false;
}

template <typename T>
bool MySet<T>::is_element(const T &el) const {
    return q_find(el) != -1;
}

template <typename T>
MySet<T> &MySet<T>::operator=(const MySet<T> &s) {
    if (this == &s) {
        return *this;
    }
    MyVector<T>::operator=(s);
    return *this;
}

template <typename T>
bool MySet<T>::operator==(const MySet<T> &s) const {
    if (this->size != s.size) {
        return false;
    }
    for (int i = 0; i < this->size; ++i) {
        if (!(this->pdata[i] == s.pdata[i])) {
            return false;
        }
    }
    return true;
}

template <typename T>
MySet<T> &MySet<T>::operator+=(const MySet<T> &s) {
    for (int i = 0; i < s.size; ++i) {
        add_element(s.pdata[i]);
    }
    return *this;
}

template <typename T>
MySet<T> &MySet<T>::operator-=(const MySet<T> &s) {
    for (int i = 0; i < s.size; ++i) {
        delete_element(s.pdata[i]);
    }
    return *this;
}

template <typename T>
MySet<T> &MySet<T>::operator*=(const MySet<T> &s) {
    MySet<T> temp;
    for (int i = 0; i < this->size; ++i) {
        if (s.is_element(this->pdata[i])) {
            temp.add_element(this->pdata[i]);
        }
    }
    *this = temp;
    return *this;
}

/*
ДАЛЕЕ ОПИСАНА СПЕЦИАЛИЗАЦИЯ ШАБЛОНА ДЛЯ char *
*/

template <>
class MySet<char*> : public MyVector<char*> {
private:
    int q_find(const char *el) const;
public:
    MySet() : MyVector<char*>() {}
    explicit MySet(const char *el);
    MySet(const MySet<char*> &s);
    ~MySet() = default;

    MySet<char*> &operator=(const MySet<char*> &s);
    bool operator==(const MySet<char*> &s) const;
    MySet<char*> &operator+=(const MySet<char*> &s);
    MySet<char*> &operator-=(const MySet<char*> &s);
    MySet<char*> &operator*=(const MySet<char*> &s);

    void add_element(const char *el);
    void add_element(char *el);
    bool delete_element(const char *el);
    bool is_element(const char *el) const;

    friend std::ostream& operator<<(std::ostream &out, const MySet<char*> &s);
    friend MySet<char*> operator+(const MySet<char*> &s1, const MySet<char*> &s2);
    friend MySet<char*> operator-(const MySet<char*> &s1, const MySet<char*> &s2);
    friend MySet<char*> operator*(const MySet<char*> &s1, const MySet<char*> &s2);
};

MySet<char*>::MySet(const char *el) : MyVector<char*>() {
    if (el) {
        add_element(el);
    }
}

MySet<char*>::MySet(const MySet<char*> &s) {
    this->max_size = s.max_size;
    this->size = s.size;
    this->pdata = new char*[this->max_size];

    for (int i = 0; i < this->size; ++i) {
        this->pdata[i] = new char[std::strlen(s.pdata[i]) + 1];
        std::strcpy(this->pdata[i], s.pdata[i]);
    }
}

int MySet<char*>::q_find(const char *el) const {
    int left = 0, right = this->size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = std::strcmp(this->pdata[mid], el);
        if (cmp == 0) return mid;
        cmp < 0 ? left = mid + 1 : right = mid - 1;
    }
    return -1;
}

void MySet<char*>::add_element(const char *el) {
    if (!el) {
        return;
    }

    if (q_find(el) == -1) {
        char* new_str = new char[strlen(el) + 1];
        strcpy(new_str, el);
        MyVector<char*>::add_element(new_str);
        this->sort();
    }
}

void MySet<char*>::add_element(char *el) {
    add_element(const_cast<const char*>(el));
}

bool MySet<char*>::delete_element(const char *el) {
    int pos = q_find(el);
    if (pos == -1) {
        return false;
    }

    delete[] this->pdata[pos];
    for (int i = pos; i < this->size - 1; ++i) {
        this->pdata[i] = this->pdata[i + 1];
    }
    this->size--;
    return true;
}

bool MySet<char*>::is_element(const char *el) const {
    return q_find(el) != -1;
}

MySet<char*>& MySet<char*>::operator=(const MySet<char*> &s) {
    if (this != &s) {
        for (int i = 0; i < this->size; ++i) {
            delete[] this->pdata[i];
        }
        delete[] this->pdata;

        this->max_size = s.max_size;
        this->size = s.size;
        this->pdata = new char*[this->max_size];

        for (int i = 0; i < this->size; ++i) {
            this->pdata[i] = new char[std::strlen(s.pdata[i]) + 1];
            std::strcpy(this->pdata[i], s.pdata[i]);
        }
    }
    return *this;
}

bool MySet<char*>::operator==(const MySet<char*> &s) const {
    if (this->size != s.size) {
        return false;
    }
    for (int i = 0; i < this->size; ++i) {
        if (std::strcmp(this->pdata[i], s.pdata[i]) != 0) return false;
    }
    return true;
}

MySet<char*> &MySet<char*>::operator+=(const MySet<char*> &s) {
    for (int i = 0; i < s.size; ++i) {
        add_element(s.pdata[i]);
    }
    return *this;
}

MySet<char*> &MySet<char*>::operator-=(const MySet<char*> &s) {
    for (int i = 0; i < s.size; ++i) {
        delete_element(s.pdata[i]);
    }
    return *this;
}

MySet<char*> &MySet<char*>::operator*=(const MySet<char*> &s) {
    MySet<char*> temp;
    for (int i = 0; i < this->size; ++i) {
        if (s.is_element(this->pdata[i])) {
            temp.add_element(this->pdata[i]);
        }
    }
    *this = temp;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const MySet<char*> &s) {
    out << "{";
    for (int i = 0; i < s.size; ++i) {
        out << s[i];
        if (i < s.size - 1) out << ", ";
    }
    out << "}";
    return out;
}

MySet<char*> operator+(const MySet<char*> &s1, const MySet<char*> &s2) {
    MySet<char*> result = s1;
    result += s2;
    return result;
}

MySet<char*> operator-(const MySet<char*> &s1, const MySet<char*> &s2) {
    MySet<char*> result = s1;
    result -= s2;
    return result;
}

MySet<char*> operator*(const MySet<char*> &s1, const MySet<char*> &s2) {
    MySet<char*> result = s1;
    result *= s2;
    return result;
}

// Дедукционные гиды для MySet:
template<typename T>
MySet(T) -> MySet<T>;

// Если передаётся строковый литерал (const char*), выводим тип как MySet<char*>:
MySet(const char*) -> MySet<char*>;

#endif  // INHERITANCE_MYSET_H
