#ifndef NEWTRYAGAIN_STACKSKKK_H
#define NEWTRYAGAIN_STACKSKKK_H


#include <algorithm>
#include <iostream>


constexpr int START_CAPACITY = 20;
constexpr int MEMORY_COEFFICIENT = 2;


template<typename T>
struct Stack
{
private:
    int capacity;
    int cap;
    int size;
    T *data;

public:
    Stack();
    Stack(const Stack& other);
    Stack& operator= (const Stack& other);
    Stack(Stack&& other) noexcept;
    Stack& operator= (Stack&& other) noexcept;
    ~Stack();

    void push(const T &item);
    void push(const T &&item);
    void pop();

    T top() const;
    bool isequal(const Stack& other) const;
    [[nodiscard]] bool isempty() const;
    [[nodiscard]] int wsize() const;
};


template<typename T>
Stack<T>::Stack()
{
    capacity = START_CAPACITY;
    cap = -1;
    size = 0;
    data = new T[capacity];
}

template<typename T>
void copying(T *source, T *target, int n)
{
    for (int i = 0; i <= n; i++)
    {
        target[i] = source[i];
    }
}

template<typename T>
Stack<T>::Stack(const Stack &other)
{
    capacity = other.capacity;
    cap = other.cap;
    size = other.size;
    data = new T[capacity];
    copying(other.data, data, cap);
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack &other)
{
    if (this != &other)
    {
        capacity = other.capacity;
        cap = other.cap;
        size = other.size;
        delete[] data;
        data = new T[capacity];
        copying(other.data, data, cap);
    }
    return *this;
}

template<typename T>
Stack<T>::Stack(Stack &&other) noexcept
{
    capacity = other.capacity;
    cap = other.cap;
    size = other.size;
    data = other.data;
    other.capacity = 0;
    other.cap = -1;
    other.size = 0;
    other.data = nullptr;
}

template<typename T>
Stack<T> &Stack<T>::operator=(Stack &&other) noexcept
{
    if (this != &other)
    {
        capacity = other.capacity;
        cap = other.cap;
        size = other.size;
        delete[] data;
        data = other.data;
        other.capacity = 0;
        other.cap = -1;
        other.size = 0;
        other.data = nullptr;
    }
    return *this;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] data;
}

template<typename T>
void Stack<T>::push(const T &item)
{
    if (cap == capacity - 1)
    {
        T *newdata = new T[capacity * MEMORY_COEFFICIENT];
        copying(data, newdata, capacity - 1);
        delete[] data;
        data = newdata;
        capacity *= MEMORY_COEFFICIENT;
    }
    data[++cap] = item;
    size++;
}

template<typename T>
void Stack<T>::push(const T &&item)
{
    if (cap == capacity - 1)
    {
        T *newdata = new T[capacity * MEMORY_COEFFICIENT];
        copying(data, newdata, capacity - 1);
        delete[] data;
        data = newdata;
        capacity *= MEMORY_COEFFICIENT;
    }
    data[++cap] = std::move(item);
    size++;
}

template<typename T>
void Stack<T>::pop()
{
    if (cap == -1)
    {
        throw "Stack is empty! Nothing to pop. ";
    }
    size--;
    cap--;
    data[cap + 1];
}

template<typename T>
T Stack<T>::top() const
{
    if (cap == -1)
    {
        throw "Stack is empty! Nothing on top. ";
    }
    return data[cap];
}

template<typename T>
bool Stack<T>::isequal(const Stack &other) const
{
    if (size == other.size && capacity == other.capacity)
    {
        if (data == other.data)
        {
            return true;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template<typename T>
bool Stack<T>::isempty() const
{
    return cap == -1;
}

template<typename T>
int Stack<T>::wsize() const
{
    return size;
}


#endif