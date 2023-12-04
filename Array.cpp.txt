#include "Actor.h"
#include "Array.h"


template <typename T>
GrowableArray<T>::GrowableArray(){
  capacity = 10;
  size = 0;
  array = new T[capacity];
}

template <typename T>
GrowableArray<T>::~GrowableArray() {
  delete[] array;
}

template <typename T>
void GrowableArray<T>::resize(){
  capacity *= 2;
  T* newArray = new T[capacity];
  for (int i = 0; i < size; ++i) {
    newArray[i] = array[i];
  }
  delete[] array;
  array = newArray;
}

template <typename T>
void GrowableArray<T>::add(const T& item) {
  if (size == capacity) {
    resize();
  }
  array[size] = item;
  size++;
}

template <typename T>
T& GrowableArray<T>::get(int index) const {
  if (index >= 0 && index < size) {
    return array[index];
  }
  throw out_of_range("Index out of range");
}

template <typename T>
void GrowableArray<T>::remove(int index) {
  if (index >= 0 && index < size) {
    for (int i = index; i < size - 1; ++i) {
      array[i] = array[i + 1];
    }
    --size;
  } else {
    throw out_of_range("Index out of range");
  }
}

template <typename T>
unsigned int GrowableArray<T>::getSize() const {
  return size;
}

template <typename T>
int GrowableArray<T>::find(T& item) const{
  for (int i = 0; i < size; ++i) {
    if (array[i] == item) {
      return i;
    }
  }
  return -1; 
}

template <typename T>
void GrowableArray<T>::pop_back(){
if(size > 0) {
  size--;
 }
}

template <typename T>
void GrowableArray<T>::push_back(const T& item) {
    if (size == capacity) {
        resize();
    }
    array[size++] = item;
}

template class GrowableArray<Actor>;
