#include "Vector.h"

ostream& operator<<(ostream& out, Vector<bool>& v)
{
    for (int i = 0; i < v.Size; i++)
        out << v.array[i] << ' ';
    return out;
}
ostream& operator<<(ostream& out, Vector<int>& v)
{
    for (int i = 0; i < v.Size; i++)
        out << v.array[i] << ' ';
    return out;
}
ostream& operator<<(ostream& out, Vector<double>& v)
{
    for (int i = 0; i < v.Size; i++)
        out << v.array[i] << ' ';
    out << endl;
    return out;
}
istream& operator>>(istream& in, Vector<double>& v)
{
    for (int i = 0; i < v.Size; i++)
        in >> v.array[i];
    return in;
}


