#ifndef MYSHAREDPTR
#define MYSHAREDPTR

#include <memory>




template <typename T>
class MySharedPtr{

private:
    T* ptr;
    uint32_t* ptrCounter;

public:

    MySharedPtr(): ptr(nullptr), ptrCounter(nullptr) {}; // конструктор без параметров создающий никуда не адресующий указатель
    MySharedPtr(T* ptr): ptr(ptr), ptrCounter(new uint32_t(1)) {}; // конструктор создающий новый умный указатель на переменную
    MySharedPtr(MySharedPtr<T>& other): ptr(other.ptr), ptrCounter(other.ptrCounter) {
        *ptrCounter += 1;
    }; // конструктор копирующий существующий указатель

    ~MySharedPtr(){
        (*ptrCounter)--;
        if (*ptrCounter == 0){
            delete ptr;
            delete ptrCounter;
//            ptr = nullptr;
//            ptrCounter = nullptr;
        }
    }


    MySharedPtr& operator=(const MySharedPtr* r){

        ptr = r->ptr;
        ptrCounter = r->ptrCounter;
        if (ptr) {
            ++(*ptrCounter);
        }

        return *this;
    }

    T* getPtr() const{
        return ptr;
    }

    T getPtrObj() const{
        return *ptr;
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
    std::allocator<T> alloc;    // Создаем аллокатор для управления памятью

    // Выделяем память для объекта и счетчика ссылок
    auto* storage = alloc.allocate(1); // Выделяем память для одного объекта типа T

    // Создаем объект в выделенной памяти
    new(storage) T(std::forward<Args>(args)...);;

    // Создаем sharedptr, который будет управлять этим объектом
    // Контрольный блок создается внутри shared_ptr
    return MySharedPtr<T>(storage); // Пробрасываем исключение дальше

}

#endif
