#ifndef NEWTRYAGAIN_STACKSKKK_H
#define NEWTRYAGAIN_STACKSKKK_H


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
    Stack()
    {
        capacity = START_CAPACITY;
        cap = -1;
        size = 0;
        data = new T[capacity];
    }

    Stack(const Stack& other)
    {
        capacity = other.capacity;
        cap = other.cap;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i <= cap; i++)
        {
            data[i] = other.data[i];
        }
    }

    Stack& operator= (const Stack& other)
    {
        if (this != &other)
        {
            capacity = other.capacity;
            cap = other.cap;
            size = other.size;
            delete[] data;
            data = new T[capacity];
            for (int i = 0; i <= cap; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Stack(Stack&& other) noexcept
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

    Stack& operator= (Stack&& other) noexcept
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

    ~Stack()
    {
        delete[] data;
    }

    void push(const T &item)
    {
        if (cap == capacity - 1)
        {
            T *newdata = new T[capacity * MEMORY_COEFFICIENT];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            capacity *= MEMORY_COEFFICIENT;
        }
        data[++cap] = item;
        size++;
    }

    void pop()
    {
        if (cap == -1)
        {
            throw "TRUE Stack is empty! Nothing to pop. ";
        }
        size--;
        cap--;
        data[cap + 1];
    }

    T top() const
    {
        if (cap == -1)
        {
            throw "TRUE Stack is empty! Nothing on top. ";
        }
        return data[cap];
    }

    bool isequal(const Stack& other) const
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

    [[nodiscard]] bool isempty() const
    {
        return cap == -1;
    }

    [[nodiscard]] int wsize() const
    {
        return size;
    }
};


#endif