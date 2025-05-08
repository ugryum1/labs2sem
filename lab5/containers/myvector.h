#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>
#include <cstring>
#include <algorithm>

const int MAX_SIZE = 5;

template <typename T>
class MyVector {
  protected:
    int max_size;
    int size;
    T* pdata;
    void resize();

  public:
    MyVector(int max_size = MAX_SIZE);
    MyVector(T el, int max_size = MAX_SIZE);
    MyVector(const MyVector<T> &v);
    ~MyVector();

    void add_element(T el);
    bool delete_element(int i);
    const T &operator[](int i) const;
    void sort();
    int find(T el) const;
    MyVector<T> &operator=(const MyVector<T> &v);

    friend std::ostream &operator<<(std::ostream &out, MyVector &v) {
      for (int i = 0; i < v.size; i++) {
        out << v.pdata[i] << " ";
      }
      return out;
    };
};

template <typename T>
MyVector<T>::MyVector(T el, int max_size) : max_size(max_size), size(1), pdata(new T[max_size]) {
  pdata[0] = el;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &v) : max_size(v.max_size), size(v.size) {
  pdata = new T[max_size];
  for (int i = 0; i < size; ++i) {
      pdata[i] = v.pdata[i];
  }
}

template <typename T>
MyVector<T>::~MyVector() {
  delete[] pdata;
}

template <typename T>
void MyVector<T>::resize() {
  if (size >= max_size) {
      max_size *= 2;
  } else if (size < max_size / 4 && max_size > MAX_SIZE) {
      max_size /= 2;
  } else {
      return;
  }

  T *new_pdata = new T[max_size];
  for (int i = 0; i < size; i++) {
      new_pdata[i] = pdata[i];
  }

  delete[] pdata;

  pdata = new_pdata;
}

template <typename T>
void MyVector<T>::add_element(T el) {
  resize();

  pdata[size] = el;
  ++size;
}

template <typename T>
bool MyVector<T>::delete_element(int i) {
  if (i < 0 || i >= size) {
      return false;
  }

  for (int j = i; j < size - 1; ++j) {
      pdata[j] = pdata[j + 1];
  }

  --size;
  resize();

  return true;
}

template <typename T>
const T &MyVector<T>::operator[](int i) const {
  if (i < 0 || i >= size) {
      throw "Error.";
  }
  return pdata[i];
}

template <typename T>
void MyVector<T>::sort() {
  std::sort(pdata, pdata + size);
}

template <typename T>
int MyVector<T>::find(T el) const {
  for (int i = 0; i < size; ++i) {
      if (pdata[i] == el) {
          return i;
      }
  }
  return -1;
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &v) {
  if (this == &v) {
      return *this;
  }

  delete[] pdata;

  max_size = v.max_size;
  size = v.size;
  pdata = new T[max_size];

  for (int i = 0; i < size; ++i) {
      pdata[i] = v.pdata[i];
  }
  return *this;
}

/*
СПЕЦИАЛИЗАЦИЯ ШАБЛОЛА ДЛЯ char*
*/

template <>
class MyVector<char*> {
protected:
    int max_size;
    int size;
    char** pdata;
    void resize();

public:
    MyVector(char* el = nullptr, int max_size = MAX_SIZE);
    MyVector(const MyVector<char*>& v);
    MyVector(const char* el, int max_size = MAX_SIZE) : MyVector(const_cast<char*>(el), max_size) {}
    ~MyVector();

    void add_element(char* el);
    void add_element(const char* el);
    bool delete_element(int i);
    const char* operator[](int i) const;
    char* &operator[](int i);
    void sort();
    int find(const char* el) const;
    MyVector<char*>& operator=(const MyVector<char*>& v);

    friend std::ostream& operator<<(std::ostream& out, const MyVector<char*>& v) {
      for (int i = 0; i < v.size; ++i) {
          out << v.pdata[i] << " ";
      }
      return out;
    }
};

void MyVector<char*>::add_element(char *el) {
  resize();

  pdata[size] = new char[strlen(el) + 1];
  std::strcpy(pdata[size], el);
  ++size;
}

void MyVector<char*>::add_element(const char* el) {
  add_element(const_cast<char*>(el));
}

bool MyVector<char*>::delete_element(int i) {
  if (i < 0 || i >= size) {
      return false;
  }

  delete[] pdata[i];

  for (int j = i; j < size - 1; ++j) {
      pdata[j] = pdata[j + 1];
  }

  --size;
  resize();

  return true;
}

const char* MyVector<char*>::operator[](int i) const {
  if (i < 0 || i >= size) {
      throw "Error.";
  }
  return pdata[i];
}

char*& MyVector<char*>::operator[](int i) {
  if (i < 0 || i >= size) {
      throw "Error.";
  }
  return pdata[i];
}

void MyVector<char*>::sort() {
  std::sort(pdata, pdata + size, [](const char *a, const char *b) {
      return std::strcmp(a, b) < 0;
  });
}

int MyVector<char*>::find(const char *el) const {
  for (int i = 0; i < size; ++i) {
      if (std::strcmp(pdata[i], el) == 0) {
          return i;
      }
  }
  return -1;
}

MyVector<char*> &MyVector<char*>::operator=(const MyVector<char*> &v) {
  if (this == &v) {
      return *this;
  }

  for (int i = 0; i < size; ++i) {
      delete[] pdata[i];
  }
  delete[] pdata;

  max_size = v.max_size;
  size = v.size;
  pdata = new char*[max_size];
  for (int i = 0; i < size; ++i) {
      pdata[i] = new char[std::strlen(v.pdata[i]) + 1];
      std::strcpy(pdata[i], v.pdata[i]);
  }
  return *this;
}

MyVector<char*>::MyVector(char *el, int max_size) : max_size(max_size), size(0) {
  pdata = new char*[max_size];
  if (el) {
      add_element(el);
  }
}

MyVector<char*>::MyVector(const MyVector<char*> &v) : max_size(v.max_size), size(v.size) {
  pdata = new char*[max_size];
  for (int i = 0; i < size; ++i) {
      pdata[i] = new char[std::strlen(v.pdata[i]) + 1];
      std::strcpy(pdata[i], v.pdata[i]);
  }
}

MyVector<char*>::~MyVector() {
  for (int i = 0; i < size; ++i) {
      delete[] pdata[i];
  }
  delete[] pdata;
}

void MyVector<char*>::resize() {
  if (size >= max_size) {
      max_size *= 2;
  } else if (size < max_size / 4 && max_size > MAX_SIZE) {
      max_size /= 2;
  } else {
      return;
  }

  char **new_pdata = new char*[max_size];
  for (int i = 0; i < size; i++) {
      new_pdata[i] = new char[strlen(pdata[i]) + 1];
      std::strcpy(new_pdata[i], pdata[i]);
  }

  for (int i = 0; i < size; i++) {
      delete[] pdata[i];
  }
  delete[] pdata;

  pdata = new_pdata;
}

// Дедукционные гиды для MyVector:
template<typename T>
MyVector(T) -> MyVector<T>;

// Если передаётся строковый литерал (const char*), выводим тип как MyVector<char*>:
MyVector(const char*) -> MyVector<char*>;

#endif  // INHERITANCE_MYVECTOR_H
