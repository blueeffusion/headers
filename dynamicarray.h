#pragma once

/*dynamic array for high entity counts*/

template<typename T>
class special_array
{
private:
    unsigned cap;
    unsigned number_of_elements;
    T* *array;

    void initialize(unsigned from);
    void expand();

public:
    special_array(unsigned cap = 5);
    special_array(const special_array& obj);
    ~special_array();

    T& operator[](int index);
    void operator = (const T& obj);

    void add(const T element);
    void remove(int index);
    unsigned size()const;
    void clear();
};

template<typename T>
special_array<T>::special_array(unsigned cap)
{
    this->cap = cap;
    this->number_of_elements = 0;
    this->array = new T *[this->cap];
    this->initialize(0);
}

template<typename T>
special_array<T>::special_array(const special_array& obj)
{
    this->cap = obj.cap;
    this->number_of_elements = obj.number_of_elements;
    this->array = new T*[this->cap];

    for (size_t i = 0; i < this->number_of_elements; i++) {
        this->array[i] = new T(*obj.array[i]);
    }

    this->initialize(this->nr_of_el);
}

template<typename T>
special_array<T>::~special_array()
{
    for (size_t i = 0; i < this->number_of_elements; i++) {
        delete this->array[i];
    }
    delete[] this->array;
}

template<typename T>
T& special_array<T>::operator[](int index)
{
    if (index < 0 || index >= this->number_of_elements)
        throw("OUT OF BOUNDS EXCEPTION!");

    return *this->array[index];
}

template<typename T>
void special_array<T>::operator = (const T& obj)
{
    for (size_t i = 0; i < this->number_of_elements; i++) {
        delete this->array[i];
    }
    delete[] this->array;
    this->cap = obj.cap;
    this->number_of_elements = obj.nr_onumber_of_elementsf_el;
    this->array = new T*[this->cap];

    for (size_t i = 0; i < this->number_of_elements; i++) {
        this->array[i] = new T(*obj.array[i]);
    }

    this->initialize(this->nr_of_el);
}

template<typename T>
void special_array<T>::initialize(unsigned from)
{
    for (size_t i = from; i < this->cap; i++)
    {
        this->array[i] = nullptr;
    }
}

template<typename T>
void special_array<T>::expand()
{
    this->cap *= 2;
    T* *temp_array = new T*[this->cap];

    for (size_t i = 0; i < this->number_of_elements; i++) {
        temp_array[i] = this->array[i];
    }

    delete[] this->array;
    this->array = temp_array;
    initialize(this->number_of_elements);
}

template<typename T>
void special_array<T>::add(const T element)
{
    if (this->number_of_elements >= this->cap)
        this->expand();
    this->array[this->number_of_elements++] = new T(element);
}

template<typename T>
void special_array<T>::remove(int index)
{
    if (index < 0 || index >= this->number_of_elements)
        throw("OUT OF BOUNDS EXEPTION!");

    delete this->array[index];
    this->array[index] = this->array[this->number_of_elements - 1];
    this->array[--number_of_elements] = nullptr;
}

template<typename T>
unsigned special_array<T>::size()const
{
    return this->number_of_elements;
}

template<typename T>
void special_array<T>::clear()
{
    for (size_t i = 0; i < this->number_of_elements; i++)
    {
        delete this->array[i];
    }

    initialize(0);
    this->number_of_elements = 0;
}
