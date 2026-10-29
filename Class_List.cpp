#include <iostream>
using namespace std;

template <class T>
struct elem
{
    T inf;
    elem <T>* link;
};

template <class T>
class List
{
public:
    List();
    ~List();
    void AddAfter(T y, T x);
    void AddBefore(T y, T x);
    int Del_El(T x);
    void Print_list();
    void Del_list();

    elem <T>* first;
};

template <class T>
List<T>::List()
{
    first = nullptr;
}

template <class T>
List<T>::~List()
{
    Del_list();
}

template <class T>
void List<T>::AddAfter(T y, T x)
{
    elem <T>* p = first;
    while (p && p->inf != y) p = p->link;
    
    elem <T>* q = new elem <T>;
    q->inf = x;

    if (p)
    {
        q->link = p->link;
        p->link = q;
    }
    else
    {
        // Ако y не е намерен, го добавяме в началото (или в края според логиката ви)
        q->link = first;
        first = q;
    }
}

template <class T>
int List <T>::Del_El(T x)
{
    if (!first) return 0; // Предпазва от срив при празен списък

    if (first->inf == x)
    {
        elem <T>* q = first;
        first = first->link;
        delete q;
        return 1;
    }

    elem <T>* p = first;
    while (p->link && p->link->inf != x) p = p->link;
    
    if (!p->link) return 0;

    elem <T>* q = p->link;
    p->link = q->link;
    delete q;
    return 1;
}

template <class T>
void List<T>::Print_list()
{
    elem <T>* p = first;
    while (p)
    {
        cout << p->inf << " ";
        p = p->link;
    }
    cout << endl;
}

template <class T>
void List<T>::Del_list()
{
    elem <T>* p = first, * q;
    while (p)
    {
        q = p; 
        p = p->link;
        delete q;
    }
    first = nullptr;
}
