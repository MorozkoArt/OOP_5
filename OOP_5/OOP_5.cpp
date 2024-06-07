#include <iostream>
#include<locale>
#include<exception>
#include <string>

using namespace std;

class Stack_exception :public exception
{
private:
    string str;
    int idx = 0;
public:
    Stack_exception(const string& a, int b = 0) {
        str = a;
        idx = b;
        str += ("index : " + std::to_string(b));
    }

    virtual const char* what() const override {
        return str.c_str();
    }
};
template <class T>
class Stack
{
private:
    T* arr;//указатель на начало
    T* top;//указатель на вершину
    int size;
    int capacity;
public:
    Stack(int a) {
        if (a <= 0) throw Stack_exception("Невозможно выделить память ", a);
        arr = new T[a];
        top = nullptr;
        capacity = a;
        size = 0;
    }
    
    bool is_empty() {
        if (size == 0) return true;
        else return false;
    }
    bool is_full() {
        if (capacity == size)return true;
        return false;
    }
    void Push(T elem) {
        if (!is_full()) {
            if (size == 0) top = arr;
            else top++;
            *top = elem;
            size++;
        }
        else throw Stack_exception("Стек полностью заполнен, нельзя добавить новый элемент ", size+1);
    }
    T Pick() {
        if (!is_empty()) {
            return (*top);
        }
        else throw Stack_exception("Стек пуст, нельзя взять элемент ", -1);
    }
    void Pop() {
        if (!is_empty()) {
            if (size != 1) top--;
            else top = nullptr;
            size--;
        }
        else throw Stack_exception("Стек пуст, нельзя удалить элемент ", -1);
    }
    int Get_size() {
        return(size);
    }
    int Get_capacity() {
        return(capacity);
    }

    ~Stack() {
        delete[]arr;
        top = nullptr;
        capacity = 0;
        size = 0;
    }

};
int main()
{
    setlocale(LC_ALL, "Rus");
    try {
        //Stack<int>b(-1);
        Stack<int>a(4);
        if (a.is_empty()) cout << "Стек пуст" << endl;
        else cout << "Стек не пуст" << endl;
        a.Push(1);
        a.Push(2);
        a.Push(3);
        a.Push(4);
        //a.Push(5);
        if (a.is_full()) cout << "Стек полностью заполнен" << endl;
        else cout << "Стек заполнен не полностью" << endl;
        cout << "Верхний элемент " << a.Pick() << endl;
        a.Pop();
        cout << "capacity " << a.Get_capacity() << endl;
        cout << "size " << a.Get_size() << endl;
        cout << "Верхний элемент " << a.Pick() << endl;
        a.Pop();
        cout << "Верхний элемент " << a.Pick() << endl;
        a.Pop();
        cout << "Верхний элемент " << a.Pick() << endl;
        a.Pop();
        //cout << "Верхний элемент " << a.Pick() << endl;
        //a.Pop();
    }
    catch (Stack_exception a) {
        cout << a.what();
    }
}


