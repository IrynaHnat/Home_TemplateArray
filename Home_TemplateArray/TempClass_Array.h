#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;         
    int size;         
    int capacity;     
    int grow;         

public:
    Array(int initSize = 0, int growValue = 1);
    Array(const Array& other);

    ~Array();

    int GetSize() const;
    int GetUpperBound() const;
    bool IsEmpty() const;
    void SetSize(int newSize, int growValue = 1);
    void FreeExtra();
    void RemoveAll();
    T GetAt(int index) const;
    void SetAt(int index, T value);
    T& operator[](int index);  
    void Add(T element);
    void Append(const Array<T>& other);  
    Array<T>& operator=(const Array<T>& other);  
    T* GetData(); 
    void InsertAt(int index, T element);
    void RemoveAt(int index);
    void print() const;

private:
    void resize(int newCapacity);
};


template <typename T>
Array<T>::Array(int initSize, int growValue) : size(initSize), grow(growValue) {
    capacity = initSize > 0 ? initSize : 1;
    data = new T[capacity]();
}

template<typename T>
Array<T>::Array(const Array& other)
{
    size = other.size;
    capacity = other.capacity;
    grow = other.grow;
    if (capacity > 0) {
        data = new T[capacity]; 
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i]; 
        }
    }
    else {
        data = nullptr; 
    }
}


template <typename T>
inline Array<T>::~Array() {
    delete[] data;
}

template <typename T>
inline int Array<T>::GetSize() const {
    return size;
}

template <typename T>
inline int Array<T>::GetUpperBound() const {
    return size - 1;
}

template <typename T>
inline bool Array<T>::IsEmpty() const {
    return size == 0;
}

template <typename T>
void Array<T>::SetSize(int newSize, int growValue) {
    grow = growValue;
    if (newSize > capacity) {
        resize(newSize);
    }
    else if (newSize < size) {
        size = newSize; 
    }
}

template <typename T>
void Array<T>::FreeExtra() {
    if (size < capacity) {
        resize(size);
    }
}

template <typename T>
void Array<T>::RemoveAll() {
    delete[] data;
    size = 0;
    capacity = 1;
    data = new T[capacity];
}

template <typename T>
inline T Array<T>::GetAt(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    cout << "Error: Index " << index << " out of range.\n";
    return T();  
}

template <typename T>
inline void Array<T>::SetAt(int index, T value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
    else {
        cout << "Error: Index " << index << " out of range.\n";
    }
}

template <typename T>
inline T& Array<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    cout << "Index out of range. Returning the first element as a fallback." <<endl;
    return data[0]; 
}

template <typename T>
void Array<T>::Add(T element) {
    if (size >= capacity) {
        resize(capacity + grow);
    }
    data[size++] = element;
}

template <typename T>
void Array<T>::Append(const Array<T>& other) {
    for (int i = 0; i < other.GetSize(); i++) {
        Add(other.GetAt(i));
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        grow = other.grow;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T* Array<T>::GetData() {
    return data; 
}

template <typename T>
void Array<T>::InsertAt(int index, T element) {
    if (index >= 0 && index <= size) {
        if (size >= capacity) {
            resize(capacity + grow);
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = element;
        size++;
    }
    else {
        cout << "Error: Index " << index << " out of range.\n";
    }
}

template <typename T>
void Array<T>::RemoveAt(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
    else {
        cout << "Error: Index " << index << " out of range.\n";
    }
}

template <typename T>
void Array<T>::resize(int newCapacity) {
    if (newCapacity < size) {
        newCapacity = size;
    }
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template<typename T>
inline void Array<T>::print() const
{
    if (IsEmpty()) {
        cout << "The array is empty." << endl;
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
