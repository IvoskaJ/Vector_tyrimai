#pragma once

#include <iostream>

template <typename T> class Vektor {
private:

    T* arr;
    int capacity;
    int current;

    void SetCapacity(int capacity) {
        this->capacity = capacity;
    }

public:
    Vektor() {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push(T data)
    {
        if (current == capacity) {
            T* temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;

        }

        arr[current] = data;
        current++;
    }

    T get(int index) {
        if (index < current) {
            return arr[index];
        }
    }

    T get(int index, T value) {
        if (index < current) {
            arr[index] = value;
        }
        return arr[index];
    }

    int getSize() {
        return current;
    }

    void pop() {
        current--;
    }

    int getCapacity() {
        return capacity;
    }

    T back() {
        return arr[current - 1];
    }

    T back(int newsize) {
        arr[current - 1] = newsize;
        return arr[current-1];
    }

    T start() {
        return arr[0];
    }

    void setDataAt(T data, int index) {
        arr[index] = data;
    }

    int resize(int newsize) {
        current = newsize;
        while(capacity<newsize)
            if (current<newsize) {
                T* temp = new T[2 * capacity];

                for (int i = 0; i < current; i++) {
                    temp[i] = arr[i];
                }

                delete[] arr;
                capacity *= 2;
                arr = temp;

            }
        return current;
    }

    void clear() {
        arr = {};
        resize(0);
        SetCapacity(1);
    }

    void swap(int index1, int index2) {
        T temp{};
        temp= arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
};
