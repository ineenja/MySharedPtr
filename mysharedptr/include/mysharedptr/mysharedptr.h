#ifndef MYSHAREDPTR
#define MYSHAREDPTR

#include <memory>
#include <iostream>



template <typename T>
class MySharedPtr{

private:
    T* ptr;
    uint32_t* ptrCounter;

    void deleteptr(){
        (*ptrCounter)--;
        if (*ptrCounter == 0){
            delete ptr; // удаление объекта из памяти при удалении последнего указателя на него
            delete ptrCounter;
        }
        ptr = nullptr; // явное очищение указателя
        ptrCounter = nullptr;
    }

public:

    MySharedPtr(): ptr(nullptr), ptrCounter(nullptr) {}; // конструктор без параметров создающий никуда не адресующий указатель
    MySharedPtr(T* ptr): ptr(ptr), ptrCounter(new uint32_t(1)) {}; // конструктор создающий новый умный указатель на переменную
    MySharedPtr(const MySharedPtr<T>& other): ptr(other.ptr), ptrCounter(other.ptrCounter) {
        *ptrCounter += 1;
    }; // конструктор копирующий существующий указатель

    ~MySharedPtr(){
        deleteptr();
    }


    MySharedPtr& operator=(const MySharedPtr* r){
        deleteptr();
        ptr = r->ptr;
        ptrCounter = r->ptrCounter;
        if (ptr) {
            ++(*ptrCounter);
        }
        return *this;
    }

    T& operator*() const{
        return *getPtr();
    }

    T* operator->() const{
        return getPtr();
    }

    T* getPtr() const{
        return ptr;
    }

    uint32_t getPtrCounter() const{
        return *ptrCounter;
    }

};


// специализированный шаблон для массивов
//template <typename T>
//class MySharedPtr<T[]>{

//private:
//    T* ptr;
//    uint32_t* ptrCounter;

//    void clean();

//public:

//    MySharedPtr(); // конструктор без параметров создающий никуда не адресующий указатель
//    MySharedPtr(T* ptr); // конструктор создающий новый умный указатель на переменную
//    MySharedPtr(MySharedPtr<T>& other); // конструктор копирующий существующий умный указатель

//    ~MySharedPtr();

//    MySharedPtr& operator=(const MySharedPtr* r);

//    T* get() const;

//};


template<typename T, typename... Args>
MySharedPtr<T> makeShared(Args&&... args) {
    return MySharedPtr<T>(new T(std::forward<Args>(args)...));
}

#endif
