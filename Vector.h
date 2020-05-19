#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <typename Type>
class Vector
{
    int Size;
    Type* array;
public:
    Vector ()
    {
        Size = 5;
        array = new Type[Size];
        for (int i = 0; i < Size; i++)
            array[i] = 0;
    }
    Vector (int size)
    {
        Size = size;
        array = new Type[Size];
    }
    Vector(int size, Type n)
    {
        Size = size;
        array = new Type[Size];
        for (int i = 0; i < Size; i++)
            array[i] = n;
    }
    Vector(Vector& v)
    {
        Size = v.Size;
        array = new Type[Size];
        for (int i = 0; i < Size; i++)
            array[i] = v.array[i];
    }
    ~Vector() { delete[] array; }

    void SetSize(int n);
    int GetSize();
    void InitVectorRandom();
    void ShowVector();
    friend ostream& operator<<(ostream& stream, Vector& v);
    friend istream& operator>>(istream& stream, Vector& v);
    //Type operator[](const int index);
    Type& operator[](const int index);  
};


template<typename Type>
void Vector<Type>::SetSize(int n)
{
    Size = n;
    delete[] array;
    array = new Type[Size];
}

template<class Type>
int Vector<Type>::GetSize()
{
    return Size;
}

template<class Type>
void Vector<Type>::ShowVector()
{
    cout << array << endl;
}

template<class Type>
ostream& operator<<(ostream& out, Vector<Type>& v)
{
    for (int i = 0; i < v.Size; i++)
        out << v.array[i] << ' ';
    return out;
}

template <typename Type>
void Vector<Type>::InitVectorRandom()
{
    for (int i = 0; i < Size; i++)
        array[i] = rand() % 10;
}

template<typename Type>
istream& operator>>(istream& in, Vector<Type>& v)
{
    for (int i = 0; i < v.Size; i++)
        in >> v.array[i];
    return in;
}

template <typename Type>
Type& Vector <Type>::operator[](const int i)
{
    if (i < 0)
        return array[0];
    if (i >= Size)
        return array[Size - 1];
    return array[i];
}

// = array[i]
//template <typename Type>
//Type Vector <Type>::operator[](const int i)
//{
//    if (i < 0)
//        return array[0];
//    if (i >= Size)
//        return array[Size - 1];
//    return array[i];
//}



