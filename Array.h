#ifndef D_ARRAY_H
#define D_ARRAY_H

using namespace std;
#include <iostream>
template<typename T>
class GrowableArray{
 private:
  T* array;
  int capacity;
  int size;
  void resize();
     
 public:
  GrowableArray();
  ~GrowableArray();
  void add(const T& item);
  T& get(int index) const;
  void remove(int index);
  unsigned int getSize() const;
  
  const T& operator[](int index) const{
  if (index < 0 || index >= size) {
    throw out_of_range("Index out of range");
  }
  return array[index];
}
  
  int find(T& item) const;
  void pop_back();

  T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }
  
  bool operator==(const GrowableArray<T>& other){
  if(size != other.size){
    return false;
  }
  for(int i = 0; i < size; ++i){
    if(array[i] != other.array[i]){
        return false;
      }
      }
    return true;
  }
  
  void push_back(const T& item);

  bool operator!=(const GrowableArray<T>& other){
  return !(*this == other);
}
  
};

#endif 