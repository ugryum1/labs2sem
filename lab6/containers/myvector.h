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
    T& operator[](int i);
    void sort();
    int find(T el) const;
    int length();
    MyVector<T> &operator=(const MyVector<T> &v);

    friend std::ostream &operator<<(std::ostream &out, MyVector &v) {
      for (int i = 0; i < v.size; i++) {
        out << v.pdata[i] << " ";
      }
      return out;
    };
};

template <typename T>
MyVector<T>::MyVector(int max_size) : max_size(max_size), size(0), pdata(new T[max_size]) {}

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
T &MyVector<T>::operator[](int i) {
  if (i < 0 || i >= size) throw "Index out of bounds";
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
int MyVector<T>::length() {
  return size;
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

#endif  // INHERITANCE_MYVECTOR_H
